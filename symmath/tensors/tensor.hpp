#ifndef SYMMATH_TENSORS_TENSOR_HPP
#define SYMMATH_TENSORS_TENSOR_HPP

#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

#include <symmath/operations/tensors.hpp>
#include <symmath/sets/tensors/vector_space.hpp>
#include <symmath/tensors/tensor_initializer.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/nested_initializer_list.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t N,
          size_t M >
class Tensor {
public:

  static constexpr size_t Order = (N + M);

                          using This      = Tensor<T, N, M>;
                          using Reference = This&;
                          using ConstRef  = const This&;
                          using MoveRef   = This&&;
  template< typename U >  using Other     = Tensor<U, N, M>;

  template< typename U >  using Scalar_   = Tensor<U, 0, 0>;
  template< typename U >  using Covector_ = Tensor<U, 0, 1>;
  template< typename U >  using Vector_   = Tensor<U, 1, 0>;
  template< typename U >  using Matrix_   = Tensor<U, 1, 1>;

  // using ElementOf =

  using ValueType = T;
  using ArrayType = std::vector<ValueType>;

  // STL Type Requirements
  using value_type      = ValueType;
  using reference       = ValueType&;
  using const_reference = const ValueType&;
  using iterator        = typename ArrayType::iterator;
  using const_iterator  = typename ArrayType::const_iterator;
  using difference_type = typename ArrayType::difference_type;
  using size_type       = typename ArrayType::size_type;

private:

  std::array<size_t, Order> dim_;

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();

  template< typename ...U, typename = EnableIf_t<sizeof...(U) == Order> >
  explicit inline Tensor(const U... dim);

  explicit inline Tensor(NestedInitializerList_t<T, Order> list);

                          inline Tensor(ConstRef other) = default;
                          inline Tensor(MoveRef other) = default;
  template< typename U >  inline Tensor(const Other<U> &other);
  template< typename U >  inline Tensor(Other<U> &&other);

  // Assignment Operator
  inline Reference operator=(NestedInitializerList_t<T, Order> list);

                          inline Reference operator=(ConstRef other) = default;
                          inline Reference operator=(MoveRef other) = default;
  template< typename U >  inline Reference operator=(const Other<U> &other);
  template< typename U >  inline Reference operator=(Other<U> &&other);

  // Assign
                          inline void assign(ConstRef &rhs);
  template< typename U >  inline void assign(const Other<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Addition
                          inline void assign_add(ConstRef &rhs);
  template< typename U >  inline void assign_add(const Other<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Subtraction
                          inline void assign_sub(ConstRef &rhs);
  template< typename U >  inline void assign_sub(const Other<U> &rhs);
  template< typename U >  inline auto assign_sub(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Scalar Multiplication
                          inline void assign_scalar_mul(const ValueType &rhs);
  template< typename U >  inline void assign_scalar_mul(const Scalar_<U> &rhs);

  // Assign Tensor Product
  template< typename U, size_t P, size_t Q >
  inline void assign_tensor_prod(const Tensor<U, P, Q> &rhs);

  inline auto size() const -> size_type;
  inline auto dim(size_t d) const -> size_type;

  template< typename ...U, typename = EnableIf_t<sizeof...(U) == Order> >
  inline auto operator()(U... dim) -> ValueType &;

  template< typename ...U, typename = EnableIf_t<sizeof...(U) == Order> >
  inline auto operator()(U... dim) const -> const ValueType &;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T,
          size_t N,
          size_t M >
inline Tensor<T, N, M>::Tensor()
  : dim_{0},
    value_() {}

template< typename T,
          size_t N,
          size_t M >
template< typename ...U,
          typename >
inline Tensor<T, N, M>::Tensor(const U... dim)
  : dim_{dim...},
    value_() {

  size_t n;
  n = std::accumulate(dim_.begin(), dim_.end(), 1, std::multiplies<size_t>());
  value_.reserve(n);

  for(size_t i = 0; i < n; i++) {
    value_[i] = T();
  }

}

template< typename T,
          size_t N,
          size_t M >
inline Tensor<T, N, M>::Tensor(NestedInitializerList_t<T, Order> list)
  : dim_(dim_initializer_list<T>(list)),
    value_(flatten_initializer_list<T>(list)) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T,
          size_t N,
          size_t M >
inline auto Tensor<T, N, M>::size() const -> size_type {
  return value_.size();
}

template< typename T,
          size_t N,
          size_t M >
inline auto Tensor<T, N, M>::dim(size_t d) const -> size_type {
  return dim_[d];
}

template< typename T,
          size_t N,
          size_t M >
template< typename ...U,
          typename >
inline auto Tensor<T, N, M>::operator()(U... dim) -> ValueType & {
  std::array<size_t, Order> pack = {dim...};
  size_t idx = 0;

  for(size_t i = Order; i --> 0; ) {
    idx += pack[i];
    for(size_t j = i; j --> 0; ) {
      pack[j] *= dim_[i];
    }
  }

  return value_[idx];
}

template< typename T,
          size_t N,
          size_t M >
template< typename ...U,
          typename >
inline auto Tensor<T, N, M>::operator()(U... dim) const -> const ValueType & {
  std::array<size_t, Order> pack = {dim...};
  size_t idx = 0;

  for(size_t i = Order; i --> 0; ) {
    idx += pack[i];
    for(size_t j = i; j --> 0; ) {
      pack[j] *= dim_[i];
    }
  }

  return value_[idx];
}

// -----------------------------------------------------------------------------
// Assign
template< typename T,
          size_t N,
          size_t M >
inline void Tensor<T, N, M>::assign(ConstRef rhs) {
  // value_ = rhs.value_;
}

template< typename T,
          size_t N,
          size_t M >
template< typename U >
inline void Tensor<T, N, M>::assign(const Other<U> &rhs) {
  // value_ = static_cast<const U&>(rhs).value();
}

template< typename T,
          size_t N,
          size_t M >
template< typename U >
inline auto Tensor<T, N, M>::assign(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Addition
template< typename T,
          size_t N,
          size_t M >
inline void Tensor<T, N, M>::assign_add(ConstRef rhs) {
  // value_ += rhs.value_;
}

template< typename T,
          size_t N,
          size_t M >
template< typename U >
inline void Tensor<T, N, M>::assign_add(const Other<U> &rhs) {
  // value_ += static_cast<const U&>(rhs).value();
}

template< typename T,
          size_t N,
          size_t M >
template< typename U >
inline auto Tensor<T, N, M>::assign_add(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_add_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Subtraction
template< typename T,
          size_t N,
          size_t M >
inline void Tensor<T, N, M>::assign_sub(ConstRef rhs) {
  // value_ += rhs.value_;
}

template< typename T,
          size_t N,
          size_t M >
template< typename U >
inline void Tensor<T, N, M>::assign_sub(const Other<U> &rhs) {
  // value_ += static_cast<const U&>(rhs).value();
}

template< typename T,
          size_t N,
          size_t M >
template< typename U >
inline auto Tensor<T, N, M>::assign_sub(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_sub_(*this, eval(rhs));
}

} // sym

#endif // SYMMATH_TENSORS_TENSOR_HPP
