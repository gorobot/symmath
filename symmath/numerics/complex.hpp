#ifndef SYMMATH_NUMERICS_COMPLEX_HPP
#define SYMMATH_NUMERICS_COMPLEX_HPP

#ifndef SYMMATH_COMPLEX_UNDERLYING_TYPE
#define SYMMATH_COMPLEX_UNDERLYING_TYPE std::complex<double>
#endif

#include <complex>

#include <symmath/numerics/number.hpp>
#include <symmath/numerics/scalar.hpp>
#include <symmath/sets/numerics/complex_numbers.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Complex
  : public Number<Complex>,
    public Scalar<Complex> {
public:

  using This            = Complex;
  using Reference       = This&;
  using ConstRef        = const This&;
  using MoveRef         = This&&;

  using ElementOf       = ComplexNumbers;

  using ValueType       = SYMMATH_COMPLEX_UNDERLYING_TYPE;
  using ResultType      = This;

private:

  ValueType value_;

public:

  // Constructor
  explicit inline Complex();

  explicit inline Complex(const ValueType &value);
  explicit inline Complex(ValueType &&value);

                          inline Complex(ConstRef other) = default;
                          inline Complex(MoveRef other) = default;
  template< typename U >  inline Complex(const Number<U> &other);

  // Assignment Operator
  inline Reference operator=(const ValueType &rhs);
  inline Reference operator=(ValueType &&rhs);
  inline Reference operator=(const double &rhs);
  inline Reference operator=(double &&rhs);

                          inline Reference operator=(ConstRef rhs) = default;
                          inline Reference operator=(MoveRef rhs) = default;
  template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator+=(const ValueType &rhs);
  inline Reference operator+=(ValueType &&rhs);
  inline Reference operator+=(const double &rhs);
  inline Reference operator+=(double &&rhs);

                          inline Reference operator+=(ConstRef rhs);
  template< typename U >  inline Reference operator+=(const Number<U> &rhs);
  template< typename U >  inline auto      operator+=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator/=(const ValueType &rhs);
  inline Reference operator/=(ValueType &&rhs);
  inline Reference operator/=(const double &rhs);
  inline Reference operator/=(double &&rhs);

                          inline Reference operator/=(ConstRef rhs);
  template< typename U >  inline Reference operator/=(const Number<U> &rhs);
  template< typename U >  inline auto      operator/=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator*=(const ValueType &rhs);
  inline Reference operator*=(ValueType &&rhs);
  inline Reference operator*=(const double &rhs);
  inline Reference operator*=(double &&rhs);

                          inline Reference operator*=(ConstRef rhs);
  template< typename U >  inline Reference operator*=(const Number<U> &rhs);
  template< typename U >  inline auto      operator*=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator-=(const ValueType &rhs);
  inline Reference operator-=(ValueType &&rhs);
  inline Reference operator-=(const double &rhs);
  inline Reference operator-=(double &&rhs);

                          inline Reference operator-=(ConstRef rhs);
  template< typename U >  inline Reference operator-=(const Number<U> &rhs);
  template< typename U >  inline auto      operator-=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

  inline This conj();

  // Assign
                          inline void assign(ConstRef rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Addition
                          inline void assign_add(ConstRef rhs);
  template< typename U >  inline auto assign_add(const Number<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Division
                          inline void assign_div(ConstRef rhs);
  template< typename U >  inline auto assign_div(const Number<U> &rhs);
  template< typename U >  inline auto assign_div(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Multiplication
                          inline void assign_mul(ConstRef rhs);
  template< typename U >  inline auto assign_mul(const Number<U> &rhs);
  template< typename U >  inline auto assign_mul(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Subtraction
                          inline void assign_sub(ConstRef rhs);
  template< typename U >  inline auto assign_sub(const Number<U> &rhs);
  template< typename U >  inline auto assign_sub(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Power
                          inline void assign_pow(ConstRef rhs);
  template< typename U >  inline auto assign_pow(const Number<U> &rhs);
  template< typename U >  inline auto assign_pow(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Negative
                          inline void assign_neg(ConstRef rhs);
  template< typename U >  inline auto assign_neg(const Number<U> &rhs);
  template< typename U >  inline auto assign_neg(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Inverse
                          inline void assign_inv(ConstRef rhs);
  template< typename U >  inline auto assign_inv(const Number<U> &rhs);
  template< typename U >  inline auto assign_inv(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Complex::Complex()
  : value_(0.0) {}

inline Complex::Complex(const ValueType &value)
  : value_(value) {}

inline Complex::Complex(ValueType &&value)
  : value_(std::move(value)) {}

template< typename U >
inline Complex::Complex(const Number<U> &other)
  : value_(static_cast<const U&>(other).value()) {}

// -----------------------------------------------------------------------------
// Assignment Operator
inline Complex::Reference Complex::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

inline Complex::Reference Complex::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

inline Complex::Reference Complex::operator=(const double &value) {
  value_ = value;
  return *this;
}

inline Complex::Reference Complex::operator=(double &&value) {
  value_ = std::move(value);
  return *this;
}

template< typename U >
inline Complex::Reference Complex::operator=(const Number<U> &other) {
  value_ = static_cast<const U&>(other).value_;
  return *this;
}

template< typename U >
inline auto Complex::operator=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Complex::Reference Complex::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}

inline Complex::Reference Complex::operator+=(ValueType &&rhs) {
  value_ += std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator+=(const double &rhs) {
  value_ += rhs;
  return *this;
}

inline Complex::Reference Complex::operator+=(double &&rhs) {
  value_ += std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator+=(ConstRef rhs) {
  value_ += rhs.value_;
  return *this;
}

template< typename U >
inline Complex::Reference Complex::operator+=(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Complex::operator+=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_add_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Complex::Reference Complex::operator/=(const ValueType &rhs) {
  value_ /= rhs;
  return *this;
}

inline Complex::Reference Complex::operator/=(ValueType &&rhs) {
  value_ /= std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator/=(const double &rhs) {
  value_ /= rhs;
  return *this;
}

inline Complex::Reference Complex::operator/=(double &&rhs) {
  value_ /= std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator/=(ConstRef rhs) {
  value_ /= rhs.value_;
  return *this;
}

template< typename U >
inline Complex::Reference Complex::operator/=(const Number<U> &rhs) {
  value_ /= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Complex::operator/=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_div_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Complex::Reference Complex::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}

inline Complex::Reference Complex::operator*=(ValueType &&rhs) {
  value_ *= std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator*=(const double &rhs) {
  value_ *= rhs;
  return *this;
}

inline Complex::Reference Complex::operator*=(double &&rhs) {
  value_ *= std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator*=(ConstRef rhs) {
  value_ *= rhs.value_;
  return *this;
}

template< typename U >
inline Complex::Reference Complex::operator*=(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Complex::operator*=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_mul_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Complex::Reference Complex::operator-=(const ValueType &rhs) {
  value_ -= rhs;
  return *this;
}

inline Complex::Reference Complex::operator-=(ValueType &&rhs) {
  value_ -= std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator-=(const double &rhs) {
  value_ -= rhs;
  return *this;
}

inline Complex::Reference Complex::operator-=(double &&rhs) {
  value_ -= std::move(rhs);
  return *this;
}

inline Complex::Reference Complex::operator-=(ConstRef rhs) {
  value_ -= rhs.value_;
  return *this;
}

template< typename U >
inline Complex::Reference Complex::operator-=(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Complex::operator-=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_sub_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline decltype(auto) Complex::value() const {
  return value_;
}

inline Complex::This Complex::conj() {
  This tmp;
  return tmp;
}

// -----------------------------------------------------------------------------
// Assign
inline void Complex::assign(ConstRef rhs) {
  value_ = rhs.value_;
}

template< typename U >
inline void Complex::assign(const Number<U> &rhs) {
  value_ = static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Complex::assign(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Addition
inline void Complex::assign_add(ConstRef rhs) {
  value_ += rhs.value_;
}

template< typename U >
inline auto Complex::assign_add(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Complex::assign_add(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_add_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Division
inline void Complex::assign_div(ConstRef rhs) {
  value_ /= rhs.value_;
}

template< typename U >
inline auto Complex::assign_div(const Number<U> &rhs) {
  value_ /= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Complex::assign_div(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_div_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Multiplication
inline void Complex::assign_mul(ConstRef rhs) {
  value_ *= rhs.value_;
}

template< typename U >
inline auto Complex::assign_mul(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Complex::assign_mul(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_mul_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Subtraction
inline void Complex::assign_sub(ConstRef rhs) {
  value_ -= rhs.value_;
}

template< typename U >
inline auto Complex::assign_sub(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Complex::assign_sub(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_sub_(*this, eval(rhs));
}

} // sym

#endif // SYMMATH_NUMERICS_COMPLEX_HPP
