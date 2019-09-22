#ifndef SYMMATH_PROPERTIES_PROPERTY_HPP
#define SYMMATH_PROPERTIES_PROPERTY_HPP

#ifndef FORWARD_CONSTRUCTOR
#define FORWARD_CONSTRUCTOR(base, T) using base<T>::base
#endif

#ifndef FORWARD_ASSIGNMENT_OPERATOR
#define FORWARD_ASSIGNMENT_OPERATOR(base, T) using base<T>::operator=
#endif

namespace sym {

// -----------------------------------------------------------------------------

struct Property {};

} // sym

#endif // SYMMATH_PROPERTIES_PROPERTY_HPP
