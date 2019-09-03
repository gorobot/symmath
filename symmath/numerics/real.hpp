#ifndef SYMMATH_NUMERICS_REAL_HPP
#define SYMMATH_NUMERICS_REAL_HPP

#ifndef SYMMATH_REAL_UNDERLYING_TYPE
#define SYMMATH_REAL_UNDERLYING_TYPE double
#endif

#include <type_traits>

#include "number.hpp"

#include "../properties/has_value.hpp"
#include "../properties/has_algebraic_operations.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : private Number,
    public has_value<SYMMATH_REAL_UNDERLYING_TYPE>,
    public has_algebraic_operations<Real> {
public:

  using ValueType = SYMMATH_REAL_UNDERLYING_TYPE;
  using ResultType = Real;

  FORWARD_CONSTRUCTOR(has_value, SYMMATH_REAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_value, SYMMATH_REAL_UNDERLYING_TYPE);
  FORWARD_ASSIGNMENT_OPERATOR(has_algebraic_operations, Real);

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
Real::assign(const U &rhs) {
  this->value_ = result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_add(const U &rhs) {
  this->value_ += result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_div(const U &rhs) {
  this->value_ /= result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_mul(const U &rhs) {
  this->value_ *= result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_sub(const U &rhs) {
  this->value_ -= result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_neg(const U &rhs) {
  this->value_ = -result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_inv(const U &rhs) {
  this->value_ = 1.0/result_of<U>::value(rhs);
}

template< typename U >
inline void
Real::assign_pow(const U &p) {
  this->value_ = std::pow(this->value_, result_of<U>::value(p));
}

} // sym

#endif // SYMMATH_NUMERICS_REAL_HPP
