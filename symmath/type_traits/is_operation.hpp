#ifndef SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
#define SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP

#include <type_traits>

#include "../operations/operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_operation
  : std::is_base_of<Operation, T> {};

template< typename T >
using is_operation_t = typename is_operation<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
