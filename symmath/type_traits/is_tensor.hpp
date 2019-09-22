#ifndef SYMMATH_TYPE_TRAITS_IS_TENSOR_HPP
#define SYMMATH_TYPE_TRAITS_IS_TENSOR_HPP

#include <type_traits>

#include <symmath/tensors/tensor.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsTensor
  : std::is_base_of<Tensor, T> {};

template< typename T >
using IsTensor_t = typename IsTensor<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_TENSOR_HPP
