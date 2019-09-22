#ifndef SYMMATH_PROPERTIES_ASSIGNMENT_HPP
#define SYMMATH_PROPERTIES_ASSIGNMENT_HPP

#include <type_traits>

#include "property.hpp"
#include "../type_traits/enable_if.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_(T1 &lhs, const T2 &rhs) {
  lhs.assign(rhs);
}

} // sym

#endif // SYMMATH_PROPERTIES_ASSIGNMENT_HPP
