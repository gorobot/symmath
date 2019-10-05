#ifndef SYMMATH_NUMERICS_REAL_HPP
#define SYMMATH_NUMERICS_REAL_HPP

#ifndef SYMMATH_REAL_UNDERLYING_TYPE
#define SYMMATH_REAL_UNDERLYING_TYPE double
#endif

#include <iostream>

#include <symmath/numerics/number.hpp>
#include <symmath/sets/numerics/reals.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : public Number<Real> {
public:

  using This            = Real;
  using Reference       = This&;
  using ConstRef        = const This&;
  using MoveRef         = This&&;

  using ElementOf       = Reals;

  using ValueType       = SYMMATH_REAL_UNDERLYING_TYPE;
  using ResultType      = This;

private:

  ValueType value_;

public:

  // Constructor
  explicit inline Real();

  inline Real(const ValueType &value);
  inline Real(ValueType &&value);

                          inline Real(ConstRef other) = default;
                          inline Real(MoveRef other) = default;
  template< typename U >  inline Real(const Number<U> &other);

  // Assignment Operator
  inline Reference operator=(const ValueType &rhs);
  inline Reference operator=(ValueType &&rhs);

                          inline Reference operator=(ConstRef rhs) = default;
                          inline Reference operator=(MoveRef rhs) = default;
  template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator+=(const ValueType &rhs);
  inline Reference operator+=(ValueType &&rhs);

                          inline Reference operator+=(ConstRef rhs);
  template< typename U >  inline Reference operator+=(const Number<U> &rhs);
  template< typename U >  inline auto      operator+=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator/=(const ValueType &rhs);
  inline Reference operator/=(ValueType &&rhs);

                          inline Reference operator/=(ConstRef rhs);
  template< typename U >  inline Reference operator/=(const Number<U> &rhs);
  template< typename U >  inline auto      operator/=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator*=(const ValueType &rhs);
  inline Reference operator*=(ValueType &&rhs);

                          inline Reference operator*=(ConstRef rhs);
  template< typename U >  inline Reference operator*=(const Number<U> &rhs);
  template< typename U >  inline auto      operator*=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator-=(const ValueType &rhs);
  inline Reference operator-=(ValueType &&rhs);

                          inline Reference operator-=(ConstRef rhs);
  template< typename U >  inline Reference operator-=(const Number<U> &rhs);
  template< typename U >  inline auto      operator-=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

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
inline Real::Real()
  : value_(0.0) {
    std::cout << "Real: default ctor" << '\n';
  }

inline Real::Real(const ValueType &value)
  : value_(value) {
    std::cout << "Real: copy ctor" << '\n';
  }

inline Real::Real(ValueType &&value)
  : value_(std::move(value)) {
    std::cout << "Real: move ctor" << '\n';
  }

template< typename U >
inline Real::Real(const Number<U> &other)
  : value_(static_cast<const U&>(other).value()) {}

// -----------------------------------------------------------------------------
// Assignment Operator
inline Real::Reference Real::operator=(const ValueType &value) {
  std::cout << "Real: = copy" << '\n';
  value_ = value;
  return *this;
}

inline Real::Reference Real::operator=(ValueType &&value) {
  std::cout << "Real: = move" << '\n';
  value_ = std::move(value);
  return *this;
}

template< typename U >
inline Real::Reference Real::operator=(const Number<U> &other) {
  value_ = static_cast<const U&>(other).value_;
  return *this;
}

template< typename U >
inline auto Real::operator=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_(*this, eval(rhs));
  return *this;
}

// -----------------------------------------------------------------------------

inline Real::Reference Real::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}

inline Real::Reference Real::operator+=(ValueType &&rhs) {
  value_ += std::move(rhs);
  return *this;
}

inline Real::Reference Real::operator+=(ConstRef rhs) {
  value_ += rhs.value_;
  return *this;
}

template< typename U >
inline Real::Reference Real::operator+=(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator+=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_add_(*this, eval(rhs));
  return *this;
}

// -----------------------------------------------------------------------------

inline Real::Reference Real::operator/=(const ValueType &rhs) {
  value_ /= rhs;
  return *this;
}

inline Real::Reference Real::operator/=(ValueType &&rhs) {
  value_ /= std::move(rhs);
  return *this;
}

inline Real::Reference Real::operator/=(ConstRef rhs) {
  value_ /= rhs.value_;
  return *this;
}

template< typename U >
inline Real::Reference Real::operator/=(const Number<U> &rhs) {
  value_ /= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator/=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_div_(*this, eval(rhs));
  return *this;
}

// -----------------------------------------------------------------------------

inline Real::Reference Real::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}

inline Real::Reference Real::operator*=(ValueType &&rhs) {
  value_ *= std::move(rhs);
  return *this;
}

inline Real::Reference Real::operator*=(ConstRef rhs) {
  value_ *= rhs.value_;
  return *this;
}

template< typename U >
inline Real::Reference Real::operator*=(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator*=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_mul_(*this, eval(rhs));
  return *this;
}

// -----------------------------------------------------------------------------

inline Real::Reference Real::operator-=(const ValueType &rhs) {
  value_ -= rhs;
  return *this;
}

inline Real::Reference Real::operator-=(ValueType &&rhs) {
  value_ -= std::move(rhs);
  return *this;
}

inline Real::Reference Real::operator-=(ConstRef rhs) {
  value_ -= rhs.value_;
  return *this;
}

template< typename U >
inline Real::Reference Real::operator-=(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator-=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_sub_(*this, eval(rhs));
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline decltype(auto) Real::value() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Assign
inline void Real::assign(ConstRef rhs) {
  value_ = rhs.value_;
}

template< typename U >
inline void Real::assign(const Number<U> &rhs) {
  value_ = static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Addition
inline void Real::assign_add(ConstRef rhs) {
  value_ += rhs.value_;
}

template< typename U >
inline auto Real::assign_add(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_add(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_add_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Division
inline void Real::assign_div(ConstRef rhs) {
  value_ /= rhs.value_;
}

template< typename U >
inline auto Real::assign_div(const Number<U> &rhs) {
  value_ /= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_div(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_div_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Multiplication
inline void Real::assign_mul(ConstRef rhs) {
  value_ *= rhs.value_;
}

template< typename U >
inline auto Real::assign_mul(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_mul(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_mul_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Subtraction
inline void Real::assign_sub(ConstRef rhs) {
  value_ -= rhs.value_;
}

template< typename U >
inline auto Real::assign_sub(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_sub(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_sub_(*this, eval(rhs));
}

} // sym

#endif // SYMMATH_NUMERICS_REAL_HPP
