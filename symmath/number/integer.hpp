#ifndef SYMMATH_NUMBER_INTEGER_HPP
#define SYMMATH_NUMBER_INTEGER_HPP

#ifndef SYMMATH_INTEGER_UNDERLYING_TYPE
#define SYMMATH_INTEGER_UNDERLYING_TYPE int
#endif

#include <type_traits>

#include "number.hpp"

#include "../properties/has_value.hpp"
#include "../properties/has_assign.hpp"
#include "../properties/has_addition.hpp"
#include "../properties/has_multiplication.hpp"
#include "../properties/has_subtraction.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Integer
  : private Number,
    public has_value<SYMMATH_INTEGER_UNDERLYING_TYPE>,
    public has_assign<Integer>,
    public has_addition<Integer>,
    public has_multiplication<Integer>,
    public has_subtraction<Integer> {
public:

  using ValueType = SYMMATH_INTEGER_UNDERLYING_TYPE;
  using ResultType = Integer;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_INTEGER_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_INTEGER_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assign, Integer);

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
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ = tmp.value_;
}

template<>
inline void
Integer::assign<Integer>(const Integer &rhs) {
  this->value_ = rhs.value_;
}

template<>
inline void
Integer::assign<typename Integer::ValueType>(const ValueType &rhs) {
  this->value_ = rhs;
}

template< typename U >
inline void
Integer::assign_add(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ += tmp.value_;
}

template<>
inline void
Integer::assign_add<Integer>(const Integer &rhs) {
  this->value_ += rhs.value_;
}

template<>
inline void
Integer::assign_add<typename Integer::ValueType>(const ValueType &rhs) {
  this->value_ += rhs;
}

template< typename U >
inline void
Integer::assign_mul(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ *= tmp.value_;
}

template<>
inline void
Integer::assign_mul<Integer>(const Integer &rhs) {
  this->value_ *= rhs.value_;
}

template<>
inline void
Integer::assign_mul<typename Integer::ValueType>(const ValueType &rhs) {
  this->value_ *= rhs;
}

template< typename U >
inline void
Integer::assign_sub(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ -= tmp.value_;
}

template<>
inline void
Integer::assign_sub<Integer>(const Integer &rhs) {
  this->value_ -= rhs.value_;
}

template<>
inline void
Integer::assign_sub<typename Integer::ValueType>(const ValueType &rhs) {
  this->value_ -= rhs;
}

} // sym

#endif // SYMMATH_NUMBER_INTEGER_HPP
