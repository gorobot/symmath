#ifndef SYMMATH_PROPERTIES_HAS_OPERATION_HPP
#define SYMMATH_PROPERTIES_HAS_OPERATION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/void_t.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename = std::enable_if_t<is_operation<T>{}, void> >
struct has_operation {};

} // sym

#endif // SYMMATH_PROPERTIES_HAS_OPERATION_HPP
