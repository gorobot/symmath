#ifndef SYMMATH_NUMBER_INTEGER_HPP
#define SYMMATH_NUMBER_INTEGER_HPP

#ifndef SYMMATH_INTEGER_UNDERLYING_TYPE
#define SYMMATH_INTEGER_UNDERLYING_TYPE int
#endif

#include <type_traits>

#include "number.hpp"

#include "../properties/has_value.hpp"
#include "../properties/has_assignment.hpp"
#include "../properties/has_addition.hpp"
#include "../properties/has_multiplication.hpp"
#include "../properties/has_subtraction.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Integer
  : private Number,
    public has_value<SYMMATH_INTEGER_UNDERLYING_TYPE>,
    public has_assignment<Integer>,
    public has_addition<Integer>,
    public has_multiplication<Integer>,
    public has_subtraction<Integer> {
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

} // sym

#endif // SYMMATH_NUMBER_INTEGER_HPP
