#ifndef SYMMATH_TYPE_TRAITS_IS_TENSOR_HPP
#define SYMMATH_TYPE_TRAITS_IS_TENSOR_HPP

#include <type_traits>

#include "../tensor/tensor.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_tensor
  : std::is_base_of<Tensor, T> {};

template< typename T >
using is_tensor_t = typename is_tensor<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_TENSOR_HPP
