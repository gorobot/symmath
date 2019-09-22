#ifndef SYMMATH_TENSORS_TENSOR_HPP
#define SYMMATH_TENSORS_TENSOR_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include <symmath/sets/numerics/vector_space.hpp>
#include <symmath/type_traits/product.hpp>
#include <symmath/type_traits/disable_if.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/nested_initializer.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t N,
          size_t M >
class Tensor {
public:

  static constexpr size_t Order = (N + M);

  using This = Tensor<T, N, M>;

  template< typename U > using Other = Tensor<U, N, M>;

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

  size_t dim_[Order];

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();
  template< typename ...U, typename = EnableIf_t<sizeof...(U) == Order> >
  explicit inline Tensor(const U... dim);
  explicit inline Tensor(NestedInitializer_t<T, Order> list);

  template< typename U >  explicit inline Tensor(const Other<U> &other);
  template< typename U >  explicit inline Tensor(Other<U> &&other);

  // Assignment Operator
  inline This &operator=(NestedInitializer_t<T, Order> list);

  template< typename U >  inline This &operator=(const Other<U> &other);
  template< typename U >  inline This &operator=(Other<U> &&other);

  // Assign
  template< typename U >  inline void assign(const Other<U> &rhs);

  // Assign Tensor Product
  template< typename U, size_t P, size_t Q >
  inline void assign_tensor_prod(const Tensor<U, P, Q> &rhs);

  inline auto size() const -> size_type;

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

  size_t n = std::accumulate(dim_, dim_ + Order, 1, std::multiplies<size_t>());
  value_.reserve(n);

  for(size_t i = 0; i < n; i++) {
    value_[i] = T();
  }

}

template< typename T >
struct is_list
  : std::false_type {};

template< typename T >
struct is_list<std::initializer_list<T>>
  : std::true_type {};

template< typename T >
struct is_nested_list
  : std::false_type {};

template< typename T >
struct is_nested_list<std::initializer_list<std::initializer_list<T>>>
  : std::true_type {};

template< typename L,
          typename T >
auto extract(L list, size_t level, size_t dim[], std::vector<T> &v)
-> EnableIf_t<!is_nested_list<L>{}> {}

template< typename L,
          typename T >
auto extract(L list, size_t level, size_t dim[], std::vector<T> &v)
-> EnableIf_t<is_nested_list<L>{}> {

  dim[level] = list.size();

  for(const auto &l : list) {

    if(is_nested_list<decltype(l)>{}) {
      extract(l, ++level, dim, v);
    } else {
      dim[level + 1] = l.size();
      v.insert(v.end(), l);
    }

  }
}

template< typename T,
          size_t N,
          size_t M >
inline Tensor<T, N, M>::Tensor(NestedInitializer_t<T, Order> list)
  : dim_{0},
    value_() {

  extract(list, 0, dim_, value_);

  std::cout << "dim: ";
  std::cout << dim_[0];
  std::cout << dim_[1] << '\n';

}

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
template< typename ...U,
          typename >
inline auto Tensor<T, N, M>::operator()(U... dim) -> ValueType & {
  size_t pack[] = {dim...};
  // size_t idx = pack[Order];
  size_t idx = 0;
  std::cout << "idx = 0";
  for(size_t i = Order; i--; ) {
    std::cout << " + " << pack[i];
    idx += pack[i];
    for(size_t j = i; j--; ) {
      std::cout << "*" << dim_[j];
      idx *= dim_[j];
    }
  }
  std::cout << " = " << idx << '\n';
  // for(size_t i = 1; i < Order; i++) {
  //   idx += dim_[i] * pack[i];
  // }
  return value_[idx];
}

template< typename T,
          size_t N,
          size_t M >
template< typename ...U,
          typename >
inline auto Tensor<T, N, M>::operator()(U... dim) const -> const ValueType & {
  size_t pack[] = {dim...};
  // size_t idx = pack[Order];
  size_t idx = 0;
  for(size_t i = Order; i--; ) {
    idx += pack[i];
    for(size_t j = i; j--; ) {
      idx *= dim_[j];
    }
  }
  // for(size_t i = 1; i < Order; i++) {
  //   idx += dim_[i] * pack[i];
  // }

  // for(size_t i = Order; i--; ) {
  //   idx += pack[i];
  //   for(size_t j = i; j--; ) {
  //     idx *= dim_[j];
  //   }
  // }
  return value_[idx];
}

} // sym

#endif // SYMMATH_TENSORS_TENSOR_HPP
