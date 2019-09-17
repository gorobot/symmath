#ifndef SYMMATH_PROPERTIES_HAS_VALUE_HPP
#define SYMMATH_PROPERTIES_HAS_VALUE_HPP

#include <ostream>
#include <type_traits>

#include "property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class has_order
  : private Property {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline bool
operator<(const has_order<T1> &lhs, const has_order<T2> &rhs) {
  return (lhs == rhs);
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_VALUE_HPP
