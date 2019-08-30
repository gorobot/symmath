#ifndef SYMMATH_NUMBER_COMPLEX_HPP
#define SYMMATH_NUMBER_COMPLEX_HPP

#include <complex>

#include "number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Complex
  : public Number<Complex> {
public:

  using SubType = double;
  using ValueType = std::complex<SubType>;

  using ResultType = Complex;

protected:

  ValueType value_;

public:

  explicit inline Complex();
  inline Complex(const ValueType value);
  inline Complex(const SubType re, const SubType im = 0.0);

  template< typename U >
  inline Complex &operator=(const Symbolic<U> &rhs);

  inline operator ValueType() const;

  inline auto eval() -> const ResultType;

  inline void apply(const Complex &rhs);
  inline void apply_add(const Complex &rhs);
  inline void apply_div(const Complex &rhs);
  inline void apply_mul(const Complex &rhs);
  inline void apply_sub(const Complex &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
inline Complex::Complex()
  : value_(0.0) {}

inline Complex::Complex(const ValueType value)
  : value_(value) {}

inline Complex::Complex(const SubType re, const SubType im)
  : value_(re, im) {}

template< typename U >
inline Complex &
Complex::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

inline Complex::operator Complex::ValueType() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline auto
Complex::eval()
-> const ResultType {
  return *this;
}

inline void
Complex::apply(const Complex &rhs) {
  value_ = rhs.value_;
}
inline void
Complex::apply_add(const Complex &rhs) {
  value_ += rhs.value_;
}
inline void
Complex::apply_div(const Complex &rhs) {
  value_ /= rhs.value_;
}
inline void
Complex::apply_mul(const Complex &rhs) {
  value_ *= rhs.value_;
}
inline void
Complex::apply_sub(const Complex &rhs) {
  value_ -= rhs.value_;
}

} // sym

#endif // SYMMATH_NUMBER_COMPLEX_HPP
