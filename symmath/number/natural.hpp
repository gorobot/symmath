#ifndef SYMMATH_NUMBER_NATURAL_HPP
#define SYMMATH_NUMBER_NATURAL_HPP

#include "number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Natural
  : public Number<Natural> {
public:

  using ValueType = unsigned;

private:

  ValueType value_;

public:

  explicit inline Natural();
  inline Natural(const ValueType value);

  using Number<Natural>::operator=;

  inline void apply(const Natural &rhs);
  inline void apply_add(const Natural &rhs);
  inline void apply_mul(const Natural &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
inline Natural::Natural()
  : value_(0) {}

inline Natural::Natural(const ValueType value)
  : value_(value) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline void
Natural::apply(const Natural &rhs) {
  value_ = rhs.value_;
}
inline void
Natural::apply_add(const Natural &rhs) {
  value_ += rhs.value_;
}
inline void
Natural::apply_mul(const Natural &rhs) {
  value_ *= rhs.value_;
}

} // sym

#endif // SYMMATH_NUMBER_NATURAL_HPP
