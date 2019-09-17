#ifndef SYMMATH_NUMERICS_INTEGER_HPP
#define SYMMATH_NUMERICS_INTEGER_HPP

#ifndef SYMMATH_INTEGER_UNDERLYING_TYPE
#define SYMMATH_INTEGER_UNDERLYING_TYPE int
#endif

#include <type_traits>

#include "number.hpp"

#include "sets/integers.hpp"
#include "../properties/has_assignment.hpp"
#include "../properties/has_value.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Integer
  : private Number,
    public ElementOf<Integers>,
    public has_assignment<Integer>,
    public has_value<SYMMATH_INTEGER_UNDERLYING_TYPE> {
public:

  using ValueType = SYMMATH_INTEGER_UNDERLYING_TYPE;
  using ResultType = Integer;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_INTEGER_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_INTEGER_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assignment, Integer);

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_mul(const U &rhs);
  template< typename U >
  inline void assign_sub(const U &rhs);

  template< typename U >
  inline void assign_neg(const U &rhs);

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename U >
inline void
Integer::assign(const U &rhs) {
  this->value_ = result_of<U>::value(rhs);
}

template< typename U >
inline void
Integer::assign_add(const U &rhs) {
  this->value_ += result_of<U>::value(rhs);
}

template< typename U >
inline void
Integer::assign_mul(const U &rhs) {
  this->value_ *= result_of<U>::value(rhs);
}

template< typename U >
inline void
Integer::assign_sub(const U &rhs) {
  this->value_ -= result_of<U>::value(rhs);
}

template< typename U >
inline void
Integer::assign_neg(const U &rhs) {
  this->value_ = -result_of<U>::value(rhs);
}

} // sym

#endif // SYMMATH_NUMERICS_INTEGER_HPP
