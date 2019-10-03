#ifndef SYMMATH_NUMERICS_REAL_HPP
#define SYMMATH_NUMERICS_REAL_HPP

#ifndef SYMMATH_REAL_UNDERLYING_TYPE
#define SYMMATH_REAL_UNDERLYING_TYPE double
#endif

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
  using Reference       = Real&;
  using ConstReference  = const Real&;
  using RValueReference = Real&&;

  using ElementOf       = Reals;

  using ValueType       = SYMMATH_REAL_UNDERLYING_TYPE;
  using ResultType      = Real;

private:

  ValueType value_;

public:

  // Constructor
  explicit inline Real();

  explicit inline Real(const ValueType &value);
  explicit inline Real(ValueType &&value);

                 explicit inline Real(ConstReference other);
                 explicit inline Real(RValueReference other);
  template< typename U >  inline Real(const Number<U> &other);

  // Assignment Operator
  inline Reference operator=(const ValueType &rhs);
  inline Reference operator=(ValueType &&rhs);

                          inline Reference operator=(ConstReference rhs);
                          inline Reference operator=(RValueReference rhs);
  template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator+=(const ValueType &rhs);
  inline Reference operator+=(ValueType &&rhs);

                          inline Reference operator+=(ConstReference rhs);
  template< typename U >  inline Reference operator+=(const Number<U> &rhs);
  template< typename U >  inline auto      operator+=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator/=(const ValueType &rhs);
  inline Reference operator/=(ValueType &&rhs);

                          inline Reference operator/=(ConstReference rhs);
  template< typename U >  inline Reference operator/=(const Number<U> &rhs);
  template< typename U >  inline auto      operator/=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator*=(const ValueType &rhs);
  inline Reference operator*=(ValueType &&rhs);

                          inline Reference operator*=(ConstReference rhs);
  template< typename U >  inline Reference operator*=(const Number<U> &rhs);
  template< typename U >  inline auto      operator*=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator-=(const ValueType &rhs);
  inline Reference operator-=(ValueType &&rhs);

                          inline Reference operator-=(ConstReference rhs);
  template< typename U >  inline Reference operator-=(const Number<U> &rhs);
  template< typename U >  inline auto      operator-=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

  // Assign
                          inline void assign(ConstReference rhs);
                          inline void assign(RValueReference rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Addition
                          inline void assign_add(ConstReference rhs);
  template< typename U >  inline auto assign_add(const Number<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Division
                          inline void assign_div(ConstReference rhs);
  template< typename U >  inline auto assign_div(const Number<U> &rhs);
  template< typename U >  inline auto assign_div(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Multiplication
                          inline void assign_mul(ConstReference rhs);
  template< typename U >  inline auto assign_mul(const Number<U> &rhs);
  template< typename U >  inline auto assign_mul(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Subtraction
                          inline void assign_sub(ConstReference rhs);
  template< typename U >  inline auto assign_sub(const Number<U> &rhs);
  template< typename U >  inline auto assign_sub(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Power
                          inline void assign_pow(ConstReference rhs);
  template< typename U >  inline auto assign_pow(const Number<U> &rhs);
  template< typename U >  inline auto assign_pow(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Negative
                          inline void assign_neg(ConstReference rhs);
  template< typename U >  inline auto assign_neg(const Number<U> &rhs);
  template< typename U >  inline auto assign_neg(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Inverse
                          inline void assign_inv(ConstReference rhs);
  template< typename U >  inline auto assign_inv(const Number<U> &rhs);
  template< typename U >  inline auto assign_inv(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Real::Real()
  : value_(0.0) {}

inline Real::Real(const ValueType &value)
  : value_(value) {}

inline Real::Real(ValueType &&value)
  : value_(std::move(value)) {}

inline Real::Real(ConstReference other)
  : value_(other.value_) {}

inline Real::Real(RValueReference other)
  : value_(std::move(other.value_)) {}

template< typename U >
inline Real::Real(const Number<U> &other)
  : value_(static_cast<const U&>(other).value()) {}

// -----------------------------------------------------------------------------
// Assignment Operator
inline Real::Reference Real::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

inline Real::Reference Real::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

inline Real::Reference Real::operator=(ConstReference other) {
  value_ = other.value_;
  return *this;
}

inline Real::Reference Real::operator=(RValueReference other) {
  value_ = std::move(other.value_);
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
  assign_(*this, rhs);
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

inline Real::Reference Real::operator+=(ConstReference rhs) {
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
  assign_add_(*this, rhs);
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

inline Real::Reference Real::operator/=(ConstReference rhs) {
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
  assign_div_(*this, rhs);
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

inline Real::Reference Real::operator*=(ConstReference rhs) {
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
  assign_mul_(*this, rhs);
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

inline Real::Reference Real::operator-=(ConstReference rhs) {
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
  assign_sub_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline decltype(auto) Real::value() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Assign
inline void Real::assign(ConstReference rhs) {
  value_ = rhs.value_;
}

inline void Real::assign(RValueReference rhs) {
  value_ = std::move(rhs.value_);
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
inline void Real::assign_add(ConstReference rhs) {
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
inline void Real::assign_div(ConstReference rhs) {
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
inline void Real::assign_mul(ConstReference rhs) {
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
inline void Real::assign_sub(ConstReference rhs) {
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
