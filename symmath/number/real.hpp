#ifndef SYMMATH_NUMBER_REAL_HPP
#define SYMMATH_NUMBER_REAL_HPP

#ifndef SYMMATH_REAL_UNDERLYING_TYPE
#define SYMMATH_REAL_UNDERLYING_TYPE double
#endif

#include <type_traits>

#include "number.hpp"

#include "../properties/has_value.hpp"
#include "../properties/has_assign.hpp"
#include "../properties/has_addition.hpp"
#include "../properties/has_division.hpp"
#include "../properties/has_multiplication.hpp"
#include "../properties/has_subtraction.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : private Number,
    public has_value<SYMMATH_REAL_UNDERLYING_TYPE>,
    public has_assign<Real>,
    public has_addition<Real>,
    public has_division<Real>,
    public has_multiplication<Real>,
    public has_subtraction<Real> {
public:

  using ValueType = SYMMATH_REAL_UNDERLYING_TYPE;
  using ResultType = Real;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_REAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_REAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assign, Real);

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_div(const U &rhs);
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
Real::assign(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ = tmp.value_;
}

template<>
inline void
Real::assign<Real>(const Real &rhs) {
  this->value_ = rhs.value_;
}

template<>
inline void
Real::assign<typename Real::ValueType>(const ValueType &rhs) {
  this->value_ = rhs;
}

template< typename U >
inline void
Real::assign_add(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ += tmp.value_;
}

template<>
inline void
Real::assign_add<Real>(const Real &rhs) {
  this->value_ += rhs.value_;
}

template<>
inline void
Real::assign_add<typename Real::ValueType>(const ValueType &rhs) {
  this->value_ += rhs;
}

template< typename U >
inline void
Real::assign_div(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ /= tmp.value_;
}

template<>
inline void
Real::assign_div<Real>(const Real &rhs) {
  this->value_ /= rhs.value_;
}

template<>
inline void
Real::assign_div<typename Real::ValueType>(const ValueType &rhs) {
  this->value_ /= rhs;
}

template< typename U >
inline void
Real::assign_mul(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ *= tmp.value_;
}

template<>
inline void
Real::assign_mul<Real>(const Real &rhs) {
  this->value_ *= rhs.value_;
}

template<>
inline void
Real::assign_mul<typename Real::ValueType>(const ValueType &rhs) {
  this->value_ *= rhs;
}

template< typename U >
inline void
Real::assign_sub(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ -= tmp.value_;
}

template<>
inline void
Real::assign_sub<Real>(const Real &rhs) {
  this->value_ -= rhs.value_;
}

template<>
inline void
Real::assign_sub<typename Real::ValueType>(const ValueType &rhs) {
  this->value_ -= rhs;
}

} // sym

#endif // SYMMATH_NUMBER_REAL_HPP
