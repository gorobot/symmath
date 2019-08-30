#ifndef SYMMATH_NUMBER_NATURAL_HPP
#define SYMMATH_NUMBER_NATURAL_HPP

#include "number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Natural
  : public Number<Natural> {
public:

  using ValueType = unsigned;

  using ResultType = Natural;

private:

  ValueType value_;

public:

  explicit inline Natural();
  inline Natural(const ValueType value);

  template< typename U >
  inline Natural &operator=(const Symbolic<U> &rhs);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Natural>{}>;
  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Natural>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Natural>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Natural::Natural()
  : value_(0) {}

inline Natural::Natural(const ValueType value)
  : value_(value) {}

template< typename U >
inline Natural &
Natural::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
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
inline auto
Natural::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Natural>{}> {
  value_ = rhs.derived().eval();
}
template< typename U >
inline auto
Natural::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Natural>{}> {
  value_ += rhs.derived().eval();
}
template< typename U >
inline auto
Natural::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Natural>{}> {
  value_ *= rhs.derived().eval();
}

} // sym

#endif // SYMMATH_NUMBER_NATURAL_HPP
