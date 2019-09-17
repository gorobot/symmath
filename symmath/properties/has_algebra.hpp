#ifndef SYMMATH_PROPERTIES_HAS_ALGEBRA_HPP
#define SYMMATH_PROPERTIES_HAS_ALGEBRA_HPP

#include "has_addition.hpp"
#include "has_assignment.hpp"
#include "has_multiplication.hpp"
#include "has_scalar_multiplication.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class has_algebra
  : public has_addition<T>,
    public has_assignment<T>,
    public has_multiplication<T>,
    public has_scalar_multiplication<T> {
public:

  FORWARD_ASSIGNMENT_OPERATOR(has_assignment, T);

};

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ALGEBRA_HPP
