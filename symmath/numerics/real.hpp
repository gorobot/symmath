#ifndef SYMMATH_NUMERICS_REAL_HPP
#define SYMMATH_NUMERICS_REAL_HPP

#ifndef SYMMATH_REAL_UNDERLYING_TYPE
#define SYMMATH_REAL_UNDERLYING_TYPE double
#endif

#include <type_traits>

#include <symmath/numerics/number.hpp>
#include <symmath/sets/numerics/reals.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_same_result.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : public Number<Real> {
public:

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
  template< typename T >  inline Real(const Number<T> &other);

  // Assignment Operator
  inline Real &operator=(const ValueType &rhs);
  inline Real &operator=(ValueType &&rhs);

                          inline Real &operator=(const Real &rhs);
  template< typename T >  inline Real &operator=(const Number<T> &rhs);
  template< typename T >  inline auto  operator=(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}, Real&>;

  inline Real &operator+=(const ValueType &rhs);
  inline Real &operator+=(ValueType &&rhs);

                          inline Real &operator+=(const Real &rhs);
  template< typename T >  inline Real &operator+=(const Number<T> &rhs);
  template< typename T >  inline auto  operator+=(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}, Real&>;

  inline Real &operator/=(const ValueType &rhs);
  inline Real &operator/=(ValueType &&rhs);

                          inline Real &operator/=(const Real &rhs);
  template< typename T >  inline Real &operator/=(const Number<T> &rhs);
  template< typename T >  inline auto  operator/=(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}, Real&>;

  inline Real &operator*=(const ValueType &rhs);
  inline Real &operator*=(ValueType &&rhs);

                          inline Real &operator*=(const Real &rhs);
  template< typename T >  inline Real &operator*=(const Number<T> &rhs);
  template< typename T >  inline auto  operator*=(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}, Real&>;

  inline Real &operator-=(const ValueType &rhs);
  inline Real &operator-=(ValueType &&rhs);

                          inline Real &operator-=(const Real &rhs);
  template< typename T >  inline Real &operator-=(const Number<T> &rhs);
  template< typename T >  inline auto  operator-=(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}, Real&>;

  // Assign
  inline void assign(const ValueType &rhs);

                          inline void assign(const Real &rhs);
  template< typename T >  inline void assign(const Number<T> &rhs);
  template< typename T >  inline auto assign(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Addition
  inline void assign_add(const ValueType &rhs);

                          inline void assign_add(const Real &rhs);
  template< typename T >  inline auto assign_add(const Number<T> &rhs);
  template< typename T >  inline auto assign_add(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Division
  inline void assign_div(const ValueType &rhs);

                          inline void assign_div(const Real &rhs);
  template< typename T >  inline auto assign_div(const Number<T> &rhs);
  template< typename T >  inline auto assign_div(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Multiplication
  inline void assign_mul(const ValueType &rhs);

                          inline void assign_mul(const Real &rhs);
  template< typename T >  inline auto assign_mul(const Number<T> &rhs);
  template< typename T >  inline auto assign_mul(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Subtraction
  inline void assign_sub(const ValueType &rhs);

                          inline void assign_sub(const Real &rhs);
  template< typename T >  inline auto assign_sub(const Number<T> &rhs);
  template< typename T >  inline auto assign_sub(const T &rhs)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Power
  inline void assign_pow(const ValueType &rhs);

                          inline void assign_pow(const Real &rhs);
  template< typename T >  inline auto assign_pow(const Number<T> &rhs);
  template< typename T >  inline auto assign_pow(const T &other)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Negative
                          inline void assign_neg(const Real &rhs);
  template< typename T >  inline auto assign_neg(const Number<T> &rhs);
  template< typename T >  inline auto assign_neg(const T &other)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  // Assign Inverse
                          inline void assign_inv(const Real &rhs);
  template< typename T >  inline auto assign_inv(const Number<T> &rhs);
  template< typename T >  inline auto assign_inv(const T &other)
  -> EnableIf_t<IsSameResult<Real, T>{}>;

  inline const ValueType value() const;

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

template< typename T >
inline Real::Real(const Number<T> &other)
  : value_(static_cast<const T&>(other).value()) {}

// template< typename T >
// inline Real::Real(const T &other)
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

template< typename T >
inline Real &Real::operator=(const Number<T> &other) {
  value_ = static_cast<const T&>(other).value_;
  return *this;
}

template< typename T >
inline auto Real::operator=(const T &rhs)
-> EnableIf_t<IsSameResult<Real, T>{}, Real&> {
  assign_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline const Real::ValueType Real::value() const {
  return value_;
}

// inline void Real::assign(const Real &rhs) {
//   value_ = rhs.value_;
// }
// inline void Real::assign_add(const Real &rhs) {
//   value_ += rhs.value_;
// }
// inline void Real::assign_div(const Real &rhs) {
//   value_ /= rhs.value_;
// }
// inline void Real::assign_mul(const Real &rhs) {
//   value_ *= rhs.value_;
// }
// inline void Real::assign_sub(const Real &rhs) {
//   value_ -= rhs.value_;
// }
// inline void Real::assign_neg(const Real &p) {
//   value_ = -p.value_;
// }
// inline void Real::assign_inv(const Real &p) {
//   value_ = 1.0/p.value_;
// }
// inline void Real::assign_pow(const Real &p) {
//   value_ = std::pow(value_, p.value_);
// }
//
// template< typename U >
// inline auto Real::assign(const U &rhs)
// -> EnableIf_t<IsBasicNumber<U>{}> {
//   value_ = rhs;
// }
// template< typename U >
// inline auto Real::assign_add(const U &rhs)
// -> EnableIf_t<IsBasicNumber<U>{}> {
//   value_ += rhs;
// }
// template< typename U >
// inline auto Real::assign_div(const U &rhs)
// -> EnableIf_t<IsBasicNumber<U>{}> {
//   value_ /= rhs;
// }
// template< typename U >
// inline auto Real::assign_mul(const U &rhs)
// -> EnableIf_t<IsBasicNumber<U>{}> {
//   value_ *= rhs;
// }
// template< typename U >
// inline auto Real::assign_sub(const U &rhs)
// -> EnableIf_t<IsBasicNumber<U>{}> {
//   value_ -= rhs;
// }

// template< typename U >
// inline void
// Real::assign_add(const U &rhs) {
//   value_ += result_of<U>::value(rhs);
// }
//
// template< typename U >
// inline void
// Real::assign_div(const U &rhs) {
//   value_ /= result_of<U>::value(rhs);
// }
//
// template< typename U >
// inline void
// Real::assign_mul(const U &rhs) {
//   value_ *= result_of<U>::value(rhs);
// }
//
// template< typename U >
// inline void
// Real::assign_sub(const U &rhs) {
//   value_ -= result_of<U>::value(rhs);
// }

// template< typename U >
// inline void
// Real::assign_neg(const U &rhs) {
//   value_ = -result_of<U>::value(rhs);
// }
//
// template< typename U >
// inline void
// Real::assign_inv(const U &rhs) {
//   value_ = 1.0/result_of<U>::value(rhs);
// }
//
// template< typename U >
// inline void
// Real::assign_pow(const U &p) {
//   value_ = std::pow(value_, result_of<U>::value(p));
// }

} // sym

#endif // SYMMATH_NUMERICS_REAL_HPP
