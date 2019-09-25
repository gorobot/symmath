#ifndef SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
#define SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP

#include <type_traits>

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using IsOperation = Bool<std::is_base_of<Operation, T>{}>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
