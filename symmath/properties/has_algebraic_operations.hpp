#ifndef SYMMATH_PROPERTIES_HAS_ALGEBRAIC_OPERATIONS_HPP
#define SYMMATH_PROPERTIES_HAS_ALGEBRAIC_OPERATIONS_HPP

#include "has_value.hpp"
#include "has_assignment.hpp"
#include "has_addition.hpp"
#include "has_division.hpp"
#include "has_exponentiation.hpp"
#include "has_multiplication.hpp"
#include "has_subtraction.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class has_algebraic_operations
  : public has_assignment<T>,
    public has_addition<T>,
    public has_division<T>,
    public has_exponentiation<T>,
    public has_multiplication<T>,
    public has_subtraction<T> {
public:

  FORWARD_ASSIGNMENT_OPERATOR(has_assignment, T);

};

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ALGEBRAIC_OPERATIONS_HPP
