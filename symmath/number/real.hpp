#ifndef SYMMATH_NUMBER_REAL_HPP
#define SYMMATH_NUMBER_REAL_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "number.hpp"

#include "../type_traits/is_applicable.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : public Symbolic<Real>,
    private Number {
public:

  using ValueType = double;

  using ResultType = Real;

protected:

  ValueType value_;

public:

  explicit inline Real();
  inline Real(const ValueType &value);
  inline Real(ValueType &&value);

  template< typename U >
  inline Real(const Symbolic<U> &rhs);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  template< typename U >
  inline Real &operator=(const Symbolic<U> &rhs);

  inline Real &operator+=(const ValueType &rhs);
  inline Real &operator/=(const ValueType &rhs);
  inline Real &operator*=(const ValueType &rhs);
  inline Real &operator-=(const ValueType &rhs);

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Real, U>{}>;

  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Real, U>{}>;
  template< typename U >
  inline auto apply_div(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Real, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Real, U>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Real, U>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Real::Real()
  : value_(0.0) {}

inline Real::Real(const ValueType &value)
  : value_(value) {}

inline Real::Real(ValueType &&value)
  : value_(std::move(value)) {}

template< typename U >
inline Real::Real(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
}

inline Real::operator Real::ValueType() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline auto
Real::eval() const
-> const ResultType {
  return *this;
}

template< typename U >
inline Real &
Real::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

inline Real &Real::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}
inline Real &Real::operator/=(const ValueType &rhs) {
  value_ /= rhs;
  return *this;
}
inline Real &Real::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}
inline Real &Real::operator-=(const ValueType &rhs) {
  value_ -= rhs;
  return *this;
}

template< typename U >
inline auto
Real::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Real, U>{}> {
  value_ = rhs.derived().eval();
}

template< typename U >
inline auto
Real::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Real, U>{}> {
  value_ += rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_div(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Real, U>{}> {
  value_ /= rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Real, U>{}> {
  value_ *= rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Real, U>{}> {
  value_ -= rhs.derived().eval();
}

} // sym

#endif // SYMMATH_NUMBER_REAL_HPP
