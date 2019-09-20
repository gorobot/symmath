#ifndef SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
#define SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP

#include <type_traits>

#include "../operations/operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsOperation
  : std::is_base_of<Operation, T> {};

template< typename T >
using IsOperation_t = typename IsOperation<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
