#ifndef SYMMATH_PROPERTIES_HAS_CLOSURE_HPP
#define SYMMATH_PROPERTIES_HAS_CLOSURE_HPP

#include "property.hpp"
#include "../operations/operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_closure
  : private Property {};

} // sym

#endif // SYMMATH_PROPERTIES_HAS_CLOSURE_HPP
