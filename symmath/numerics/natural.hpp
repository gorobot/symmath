#ifndef SYMMATH_NUMERICS_NATURAL_HPP
#define SYMMATH_NUMERICS_NATURAL_HPP

#ifndef SYMMATH_NATURAL_UNDERLYING_TYPE
#define SYMMATH_NATURAL_UNDERLYING_TYPE int
#endif

#include <type_traits>

#include <symmath/numerics/number.hpp>

#include <symmath/sets/naturals.hpp>
#include "../properties/has_assignment.hpp"
#include "../properties/has_value.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Natural
  : private Number<Natural>,
    public has_assignment<Natural>,
    public has_value<SYMMATH_NATURAL_UNDERLYING_TYPE> {
public:

  using ElementOf = Naturals;

  using ValueType = SYMMATH_NATURAL_UNDERLYING_TYPE;
  using ResultType = Natural;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_NATURAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_NATURAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assignment, Natural);

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_mul(const U &rhs);

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename U >
inline void
Natural::assign(const U &rhs) {
  this->value_ = result_of<U>::value(rhs);
}

template< typename U >
inline void
Natural::assign_add(const U &rhs) {
  this->value_ += result_of<U>::value(rhs);
}

template< typename U >
inline void
Natural::assign_mul(const U &rhs) {
  this->value_ *= result_of<U>::value(rhs);
}

} // sym

#endif // SYMMATH_NUMERICS_NATURAL_HPP
