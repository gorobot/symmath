#ifndef SYMMATH_NUMBER_REAL_HPP
#define SYMMATH_NUMBER_REAL_HPP

#include "number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : public Number<Real> {
public:

  using ValueType = double;

protected:

  ValueType value_;

public:

  explicit inline Real();
  inline Real(const ValueType value);

  using Number<Real>::operator=;

  inline void apply(const Real &rhs);
  inline void apply_add(const Real &rhs);
  inline void apply_div(const Real &rhs);
  inline void apply_mul(const Real &rhs);
  inline void apply_sub(const Real &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
inline Real::Real()
  : value_(0.0) {}

inline Real::Real(const ValueType value)
  : value_(value) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline void
Real::apply(const Real &rhs) {
  value_ = rhs.value_;
}
inline void
Real::apply_add(const Real &rhs) {
  value_ += rhs.value_;
}
inline void
Real::apply_div(const Real &rhs) {
  value_ /= rhs.value_;
}
inline void
Real::apply_mul(const Real &rhs) {
  value_ *= rhs.value_;
}
inline void
Real::apply_sub(const Real &rhs) {
  value_ -= rhs.value_;
}

} // sym

#endif // SYMMATH_NUMBER_REAL_HPP
