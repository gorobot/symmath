#ifndef SYMMATH_NUMBER_INTEGER_HPP
#define SYMMATH_NUMBER_INTEGER_HPP

#include "number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Integer
  : public Number<Integer> {
public:

  using ValueType = int;

private:

  ValueType value_;

public:

  explicit inline Integer();
  inline Integer(const ValueType value);

  using Number<Integer>::operator=;

  inline void apply(const Integer &rhs);
  inline void apply_add(const Integer &rhs);
  inline void apply_mul(const Integer &rhs);
  inline void apply_sub(const Integer &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
inline Integer::Integer()
  : value_(0) {}

inline Integer::Integer(const ValueType value)
  : value_(value) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline void
Integer::apply(const Integer &rhs) {
  value_ = rhs.value_;
}
inline void
Integer::apply_add(const Integer &rhs) {
  value_ += rhs.value_;
}
inline void
Integer::apply_mul(const Integer &rhs) {
  value_ *= rhs.value_;
}
inline void
Integer::apply_sub(const Integer &rhs) {
  value_ -= rhs.value_;
}

} // sym

#endif // SYMMATH_NUMBER_INTEGER_HPP
