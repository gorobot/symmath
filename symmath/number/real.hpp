#ifndef SYMMATH_NUMBER_REAL_HPP
#define SYMMATH_NUMBER_REAL_HPP

#include <type_traits>

#include "number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Real
  : public Number<Real> {
public:

  using ValueType = double;

  using ResultType = Real;

protected:

  ValueType value_;

public:

  explicit inline Real();
  inline Real(const ValueType value);

  template< typename U >
  inline Real &operator=(const Symbolic<U> &rhs);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}>;
  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}>;
  template< typename U >
  inline auto apply_div(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Real::Real()
  : value_(0.0) {}

inline Real::Real(const ValueType value)
  : value_(value) {}

template< typename U >
inline Real &
Real::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
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
inline auto
Real::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}> {
  value_ = rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}> {
  value_ += rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_div(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}> {
  value_ /= rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}> {
  value_ *= rhs.derived().eval();
}
template< typename U >
inline auto
Real::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Real>{}> {
  value_ -= rhs.derived().eval();
}

} // sym

#endif // SYMMATH_NUMBER_REAL_HPP
