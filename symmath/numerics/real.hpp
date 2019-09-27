#ifndef SYMMATH_NUMERICS_REAL_HPP
#define SYMMATH_NUMERICS_REAL_HPP

#ifndef SYMMATH_REAL_UNDERLYING_TYPE
#define SYMMATH_REAL_UNDERLYING_TYPE double
#endif

#include <symmath/numerics/number.hpp>
#include <symmath/sets/numerics/reals.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_operation.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : public Number<Real> {
public:

  using This = Real;

  using ElementOf = Reals;

  using ValueType = SYMMATH_REAL_UNDERLYING_TYPE;
  using ResultType = Real;

private:

  ValueType value_;

public:

  // Constructor
  explicit inline Real();

  explicit inline Real(const ValueType &value);
  explicit inline Real(ValueType &&value);

                 explicit inline Real(const Real &other);
  template< typename U >  inline Real(const Number<U> &other);

  // Assignment Operator
  inline This &operator=(const ValueType &rhs);
  inline This &operator=(ValueType &&rhs);

                          inline This &operator=(const Real &rhs);
  template< typename U >  inline This &operator=(const Number<U> &rhs);
  template< typename U >  inline auto  operator=(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&>;

  inline This &operator+=(const ValueType &rhs);
  inline This &operator+=(ValueType &&rhs);

                          inline This &operator+=(const Real &rhs);
  template< typename U >  inline This &operator+=(const Number<U> &rhs);
  template< typename U >  inline auto  operator+=(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&>;

  inline This &operator/=(const ValueType &rhs);
  inline This &operator/=(ValueType &&rhs);

                          inline This &operator/=(const Real &rhs);
  template< typename U >  inline This &operator/=(const Number<U> &rhs);
  template< typename U >  inline auto  operator/=(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&>;

  inline This &operator*=(const ValueType &rhs);
  inline This &operator*=(ValueType &&rhs);

                          inline This &operator*=(const Real &rhs);
  template< typename U >  inline This &operator*=(const Number<U> &rhs);
  template< typename U >  inline auto  operator*=(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&>;

  inline This &operator-=(const ValueType &rhs);
  inline This &operator-=(ValueType &&rhs);

                          inline This &operator-=(const Real &rhs);
  template< typename U >  inline This &operator-=(const Number<U> &rhs);
  template< typename U >  inline auto  operator-=(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&>;

  // Assign
                          inline void assign(const ValueType &rhs);
                          inline void assign(const Real &rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Addition
                          inline void assign_add(const ValueType &rhs);
                          inline void assign_add(const Real &rhs);
  template< typename U >  inline auto assign_add(const Number<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Division
                          inline void assign_div(const ValueType &rhs);
                          inline void assign_div(const Real &rhs);
  template< typename U >  inline auto assign_div(const Number<U> &rhs);
  template< typename U >  inline auto assign_div(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Multiplication
                          inline void assign_mul(const ValueType &rhs);
                          inline void assign_mul(const Real &rhs);
  template< typename U >  inline auto assign_mul(const Number<U> &rhs);
  template< typename U >  inline auto assign_mul(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Subtraction
                          inline void assign_sub(const ValueType &rhs);
                          inline void assign_sub(const Real &rhs);
  template< typename U >  inline auto assign_sub(const Number<U> &rhs);
  template< typename U >  inline auto assign_sub(const U &rhs)
  -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Power
                          inline void assign_pow(const ValueType &rhs);
                          inline void assign_pow(const Real &rhs);
  template< typename U >  inline auto assign_pow(const Number<U> &rhs);
  // template< typename U >  inline auto assign_pow(const U &other)
  // -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Negative
                          inline void assign_neg(const Real &rhs);
  template< typename U >  inline auto assign_neg(const Number<U> &rhs);
  // template< typename U >  inline auto assign_neg(const U &other)
  // -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  // Assign Inverse
                          inline void assign_inv(const Real &rhs);
  template< typename U >  inline auto assign_inv(const Number<U> &rhs);
  // template< typename U >  inline auto assign_inv(const U &other)
  // -> EnableIf_t<IsCovariant<This, ResultType_t<U>>>;

  inline decltype(auto) value() const;

};

// -----------------------------------------------------------------------------
// Constructor
inline Real::Real()
  : value_(0.0) {}

inline Real::Real(const ValueType &value)
  : value_(value) {}

inline Real::Real(ValueType &&value)
  : value_(std::move(value)) {}

inline Real::Real(const Real &other)
  : value_(other.value_) {}

template< typename U >
inline Real::Real(const Number<U> &other)
  : value_(static_cast<const U&>(other).value()) {}

// template< typename U >
// inline Real::Real(const U &other)
//   : value_() {
//   assign_(*this, other);
// }

// -----------------------------------------------------------------------------
// Assignment Operator
inline Real &Real::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

inline Real &Real::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

inline Real &Real::operator=(const Real &other) {
  value_ = other.value_;
  return *this;
}

template< typename U >
inline Real &Real::operator=(const Number<U> &other) {
  value_ = static_cast<const U&>(other).value_;
  return *this;
}

template< typename U >
inline auto Real::operator=(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>, Real&> {
  assign_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Real &Real::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}

inline Real &Real::operator+=(ValueType &&rhs) {
  value_ += std::move(rhs);
  return *this;
}

inline Real &Real::operator+=(const Real &rhs) {
  value_ += rhs.value_;
  return *this;
}

template< typename U >
inline Real &Real::operator+=(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator+=(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&> {
  assign_add_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Real &Real::operator/=(const ValueType &rhs) {
  value_ /= rhs;
  return *this;
}

inline Real &Real::operator/=(ValueType &&rhs) {
  value_ /= std::move(rhs);
  return *this;
}

inline Real &Real::operator/=(const Real &rhs) {
  value_ /= rhs.value_;
  return *this;
}

template< typename U >
inline Real &Real::operator/=(const Number<U> &rhs) {
  value_ /= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator/=(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&> {
  assign_div_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Real &Real::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}

inline Real &Real::operator*=(ValueType &&rhs) {
  value_ *= std::move(rhs);
  return *this;
}

inline Real &Real::operator*=(const Real &rhs) {
  value_ *= rhs.value_;
  return *this;
}

template< typename U >
inline Real &Real::operator*=(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator*=(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&> {
  assign_mul_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Real &Real::operator-=(const ValueType &rhs) {
  value_ -= rhs;
  return *this;
}

inline Real &Real::operator-=(ValueType &&rhs) {
  value_ -= std::move(rhs);
  return *this;
}

inline Real &Real::operator-=(const Real &rhs) {
  value_ -= rhs.value_;
  return *this;
}

template< typename U >
inline Real &Real::operator-=(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Real::operator-=(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>, This&> {
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
inline void Real::assign(const ValueType &rhs) {
  value_ = rhs;
}

inline void Real::assign(const Real &rhs) {
  value_ = rhs.value_;
}

template< typename U >
inline void Real::assign(const Number<U> &rhs) {
  value_ = static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>> {
  assign_(*this, rhs);
}

// -----------------------------------------------------------------------------
// Assign Addition
inline void Real::assign_add(const ValueType &rhs) {
  value_ += rhs;
}

inline void Real::assign_add(const Real &rhs) {
  value_ += rhs.value_;
}

template< typename U >
inline auto Real::assign_add(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_add(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>> {
  assign_(*this, rhs);
}

// -----------------------------------------------------------------------------
// Assign Division
inline void Real::assign_div(const ValueType &rhs) {
  value_ /= rhs;
}

inline void Real::assign_div(const Real &rhs) {
  value_ /= rhs.value_;
}

template< typename U >
inline auto Real::assign_div(const Number<U> &rhs) {
  value_ /= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_div(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>> {
  assign_(*this, rhs);
}

// -----------------------------------------------------------------------------
// Assign Multiplication
inline void Real::assign_mul(const ValueType &rhs) {
  value_ *= rhs;
}

inline void Real::assign_mul(const Real &rhs) {
  value_ *= rhs.value_;
}

template< typename U >
inline auto Real::assign_mul(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_mul(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>> {
  assign_(*this, rhs);
}

// -----------------------------------------------------------------------------
// Assign Subtraction
inline void Real::assign_sub(const ValueType &rhs) {
  value_ -= rhs;
}

inline void Real::assign_sub(const Real &rhs) {
  value_ -= rhs.value_;
}

template< typename U >
inline auto Real::assign_sub(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Real::assign_sub(const U &rhs)
-> EnableIf_t<IsCovariant<This, ResultType_t<U>>> {
  assign_(*this, rhs);
}

} // sym

#endif // SYMMATH_NUMERICS_REAL_HPP
