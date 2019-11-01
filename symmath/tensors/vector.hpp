#ifndef SYMMATH_TENSORS_VECTOR_HPP
#define SYMMATH_TENSORS_VECTOR_HPP

#include <symmath/sets/tensors/vector_space.hpp>
#include <symmath/tensors/tensor.hpp>
#include <symmath/type_traits/nested_initializer_list.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using Vector = Tensor<T, 1, 0>;

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 1, 0> {
public:

  static constexpr size_t Order = (1);

                          using This      = Vector<T>;
                          using Reference = This&;
                          using ConstRef  = const This&;
                          using MoveRef   = This&&;
  template< typename U >  using Other     = Vector<U>;

  template< typename U >  using Scalar_   = Tensor<U, 0, 0>;
  template< typename U >  using Covector_ = Tensor<U, 0, 1>;
  template< typename U >  using Vector_   = Tensor<U, 1, 0>;
  template< typename U >  using Matrix_   = Tensor<U, 1, 1>;

  using ElementOf = VectorSpace;

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
  explicit inline Tensor() = default;

  explicit inline Tensor(const size_t n);
  explicit inline Tensor(NestedInitializerList_t<T, Order> list);

                          inline Tensor(ConstRef other) = default;
                          inline Tensor(MoveRef other) = default;
  template< typename U >  inline Tensor(const Other<U> &other);
  template< typename U >  inline Tensor(Other<U> &&other);

  // Assignment Operator
  inline This &operator=(NestedInitializerList_t<T, Order> list);

  template< typename U >  inline This &operator=(const Other<U> &other);
  template< typename U >  inline This &operator=(Other<U> &&other);

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
  template< typename U >  inline void assign_scalar_mul(const Scalar<U> &rhs);

  // Assign Tensor Product
  template< typename U, size_t N, size_t M >
  inline void assign_tensor_prod(const Tensor<U, N, M> &rhs);

  inline auto operator()(const size_t i_) -> ValueType &;
  inline auto operator()(const size_t i_) const -> const ValueType &;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Vector<T>::Tensor(const size_t n)
  : dim_{n},
    value_() {
  value_.reserve(n);
}

template< typename T >
inline Vector<T>::Tensor(NestedInitializerList_t<T, Order> list)
  : dim_{list.size()},
  value_(list) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline auto Vector<T>::operator()(const size_t i_) -> ValueType & {
  return value_[i_];
}

template< typename T >
inline auto Vector<T>::operator()(const size_t i_) const -> const ValueType & {
  return value_[i_];
}

} // sym

#endif // SYMMATH_TENSORS_VECTOR_HPP
