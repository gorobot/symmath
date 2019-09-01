#ifndef SYMMATH_NUMBER_NATURAL_HPP
#define SYMMATH_NUMBER_NATURAL_HPP

#ifndef SYMMATH_NATURAL_UNDERLYING_TYPE
#define SYMMATH_NATURAL_UNDERLYING_TYPE int
#endif

#include <type_traits>

#include "number.hpp"

#include "../properties/has_value.hpp"
#include "../properties/has_assign.hpp"
#include "../properties/has_addition.hpp"
#include "../properties/has_multiplication.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Natural
  : private Number,
    public has_value<SYMMATH_NATURAL_UNDERLYING_TYPE>,
    public has_assign<Natural>,
    public has_addition<Natural>,
    public has_multiplication<Natural> {
public:

  using ValueType = SYMMATH_NATURAL_UNDERLYING_TYPE;
  using ResultType = Natural;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_NATURAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_NATURAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assign, Natural);

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
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ = tmp.value_;
}

template<>
inline void
Natural::assign<Natural>(const Natural &rhs) {
  this->value_ = rhs.value_;
}

template<>
inline void
Natural::assign<typename Natural::ValueType>(const ValueType &rhs) {
  this->value_ = rhs;
}

template< typename U >
inline void
Natural::assign_add(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ += tmp.value_;
}

template<>
inline void
Natural::assign_add<Natural>(const Natural &rhs) {
  this->value_ += rhs.value_;
}

template<>
inline void
Natural::assign_add<typename Natural::ValueType>(const ValueType &rhs) {
  this->value_ += rhs;
}

template< typename U >
inline void
Natural::assign_mul(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ *= tmp.value_;
}

template<>
inline void
Natural::assign_mul<Natural>(const Natural &rhs) {
  this->value_ *= rhs.value_;
}

template<>
inline void
Natural::assign_mul<typename Natural::ValueType>(const ValueType &rhs) {
  this->value_ *= rhs;
}

} // sym

#endif // SYMMATH_NUMBER_NATURAL_HPP
