#ifndef SYMMATH_NUMBER_COMPLEX_HPP
#define SYMMATH_NUMBER_COMPLEX_HPP

#ifndef SYMMATH_COMPLEX_UNDERLYING_TYPE
#define SYMMATH_COMPLEX_UNDERLYING_TYPE std::complex<double>
#endif

#include <complex>
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

class Complex
  : private Number,
    public has_value<SYMMATH_COMPLEX_UNDERLYING_TYPE>,
    public has_assign<Complex>,
    public has_addition<Complex>,
    public has_division<Complex>,
    public has_multiplication<Complex>,
    public has_subtraction<Complex> {
public:

  using ValueType = SYMMATH_COMPLEX_UNDERLYING_TYPE;
  using ResultType = Complex;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_COMPLEX_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_COMPLEX_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assign, Complex);

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
Complex::assign(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ = tmp.value_;
}

template<>
inline void
Complex::assign<Complex>(const Complex &rhs) {
  this->value_ = rhs.value_;
}

template<>
inline void
Complex::assign<typename Complex::ValueType>(const ValueType &rhs) {
  this->value_ = rhs;
}

template< typename U >
inline void
Complex::assign_add(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ += tmp.value_;
}

template<>
inline void
Complex::assign_add<Complex>(const Complex &rhs) {
  this->value_ += rhs.value_;
}

template<>
inline void
Complex::assign_add<typename Complex::ValueType>(const ValueType &rhs) {
  this->value_ += rhs;
}

template< typename U >
inline void
Complex::assign_div(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ /= tmp.value_;
}

template<>
inline void
Complex::assign_div<Complex>(const Complex &rhs) {
  this->value_ /= rhs.value_;
}

template<>
inline void
Complex::assign_div<typename Complex::ValueType>(const ValueType &rhs) {
  this->value_ /= rhs;
}

template< typename U >
inline void
Complex::assign_mul(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ *= tmp.value_;
}

template<>
inline void
Complex::assign_mul<Complex>(const Complex &rhs) {
  this->value_ *= rhs.value_;
}

template<>
inline void
Complex::assign_mul<typename Complex::ValueType>(const ValueType &rhs) {
  this->value_ *= rhs;
}

template< typename U >
inline void
Complex::assign_sub(const U &rhs) {
  typename U::ResultType tmp;
  assign_(tmp, rhs);
  this->value_ -= tmp.value_;
}

template<>
inline void
Complex::assign_sub<Complex>(const Complex &rhs) {
  this->value_ -= rhs.value_;
}

template<>
inline void
Complex::assign_sub<typename Complex::ValueType>(const ValueType &rhs) {
  this->value_ -= rhs;
}

} // sym

#endif // SYMMATH_NUMBER_COMPLEX_HPP
