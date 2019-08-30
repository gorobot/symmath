#ifndef SYMMATH_NUMBER_INTEGER_HPP
#define SYMMATH_NUMBER_INTEGER_HPP

#include <type_traits>

#include "number.hpp"
#include "../type_traits/is_integral.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Integer
  : public Number<Integer> {
public:

  using ValueType = int;

  using ResultType = Integer;

private:

  ValueType value_;

public:

  explicit inline Integer();
  inline Integer(const ValueType value);

  template< typename U >
  inline Integer &operator=(const Symbolic<U> &rhs);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}>;
  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Integer::Integer()
  : value_(0) {}

inline Integer::Integer(const ValueType value)
  : value_(value) {}

template< typename U >
inline Integer &
Integer::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

inline Integer::operator Integer::ValueType() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline auto
Integer::eval() const
-> const ResultType {
  return *this;
}

template< typename U >
inline auto
Integer::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}> {
  value_ = rhs.derived().eval();
}
template< typename U >
inline auto
Integer::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}> {
  value_ += rhs.derived().eval();
}
template< typename U >
inline auto
Integer::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}> {
  value_ *= rhs.derived().eval();
}
template< typename U >
inline auto
Integer::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<std::is_same<typename U::ResultType, Integer>{}> {
  value_ -= rhs.derived().eval();
}

} // sym

#endif // SYMMATH_NUMBER_INTEGER_HPP
