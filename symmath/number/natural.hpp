#ifndef SYMMATH_NUMBER_NATURAL_HPP
#define SYMMATH_NUMBER_NATURAL_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "number.hpp"

#include "../type_traits/is_applicable.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Natural
  : public Symbolic<Natural>,
    private Number {
public:

  using ValueType = unsigned;

  using ResultType = Natural;

private:

  ValueType value_;

public:

  explicit inline Natural();
  inline Natural(const ValueType &value);
  inline Natural(ValueType &&value);

  template< typename U >
  inline Natural(const Symbolic<U> &rhs);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  template< typename U >
  inline Natural &operator=(const Symbolic<U> &rhs);

  inline Natural &operator+=(const ValueType &rhs);
  inline Natural &operator*=(const ValueType &rhs);

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Natural, U>{}>;

  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Natural, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Natural, U>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Natural::Natural()
  : value_(0) {}

inline Natural::Natural(const ValueType &value)
  : value_(value) {}

inline Natural::Natural(ValueType &&value)
  : value_(std::move(value)) {}

template< typename U >
inline Natural::Natural(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
}

inline Natural::operator Natural::ValueType() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline auto
Natural::eval() const
-> const ResultType {
  return *this;
}

template< typename U >
inline Natural &
Natural::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

inline Natural &Natural::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}
inline Natural &Natural::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}

template< typename U >
inline auto
Natural::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Natural, U>{}> {
  value_ = rhs.derived().eval();
}

template< typename U >
inline auto
Natural::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Natural, U>{}> {
  value_ += rhs.derived().eval();
}
template< typename U >
inline auto
Natural::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Natural, U>{}> {
  value_ *= rhs.derived().eval();
}

} // sym

#endif // SYMMATH_NUMBER_NATURAL_HPP
