#ifndef SYMMATH_NUMERICS_COMPLEX_HPP
#define SYMMATH_NUMERICS_COMPLEX_HPP

#ifndef SYMMATH_COMPLEX_UNDERLYING_TYPE
#define SYMMATH_COMPLEX_UNDERLYING_TYPE std::complex<double>
#endif

#include <complex>
#include <type_traits>

#include "number.hpp"

#include "sets/complex_numbers.hpp"
#include "../properties/has_assignment.hpp"
#include "../properties/has_value.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Complex
  : private Number,
    public ElementOf<ComplexNumbers>,
    public has_assignment<Complex>,
    public has_value<SYMMATH_COMPLEX_UNDERLYING_TYPE> {
public:

  using ValueType = SYMMATH_COMPLEX_UNDERLYING_TYPE;
  using ResultType = Complex;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_COMPLEX_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_COMPLEX_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_assignment, Complex);

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

  template< typename U >
  inline void assign_neg(const U &p);
  template< typename U >
  inline void assign_inv(const U &p);
  template< typename U >
  inline void assign_pow(const U &p);

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename U >
inline void
Complex::assign(const U &rhs) {
  this->value_ = result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_add(const U &rhs) {
  this->value_ += result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_div(const U &rhs) {
  this->value_ /= result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_mul(const U &rhs) {
  this->value_ *= result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_sub(const U &rhs) {
  this->value_ -= result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_neg(const U &rhs) {
  this->value_ = -result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_inv(const U &rhs) {
  this->value_ = 1.0/result_of<U>::value(rhs);
}

template< typename U >
inline void
Complex::assign_pow(const U &p) {
  this->value_ = std::pow(this->value_, result_of<U>::value(p));
}

} // sym

#endif // SYMMATH_NUMERICS_COMPLEX_HPP
