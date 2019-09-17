#ifndef SYMMATH_PROPERTIES_COMMUTATIVE_PROPERTY_HPP
#define SYMMATH_PROPERTIES_COMMUTATIVE_PROPERTY_HPP

#include "property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct commutative_property
  : private Property {};

} // sym

#endif // SYMMATH_PROPERTIES_COMMUTATIVE_PROPERTY_HPP
