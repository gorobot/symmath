#ifndef SYMMATH_PROPERTIES_HAS_VALUE_HPP
#define SYMMATH_PROPERTIES_HAS_VALUE_HPP

#include <ostream>
#include <type_traits>

#include "property.hpp"
#include "../type_traits/enable_if.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class has_value
  : private Property {
public:

  using ValueType = T;

  using ResultType = has_value<T>;

protected:

  T value_;

public:

  explicit inline has_value();
  explicit inline has_value(const ValueType &value);
  explicit inline has_value(ValueType &&value);

  inline has_value<ValueType> &operator=(const ValueType &value);
  inline has_value<ValueType> &operator=(ValueType &&value);

  inline const T &value() const;

private:

  template< typename U >
  friend inline std::ostream &
  operator<<(std::ostream &os, const has_value<U> &m);

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline
has_value<T>::has_value()
  : value_() {}

template< typename T >
inline
has_value<T>::has_value(const T &value)
  : value_(value) {}

template< typename T >
inline
has_value<T>::has_value(T &&value)
  : value_(std::move(value)) {}

template< typename T >
inline has_value<T> &
has_value<T>::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

template< typename T >
inline has_value<T> &
has_value<T>::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline const T &
has_value<T>::value() const {
  return value_;
}

// -----------------------------------------------------------------------------

template< typename U >
inline std::ostream &
operator<<(std::ostream &os, const has_value<U> &m) {
  return os << m.value_;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline bool
operator==(const has_value<T1> &lhs, const has_value<T2> &rhs) {
  return (lhs.value() == rhs.value());
}

template< typename T1,
          typename T2 >
inline auto
operator==(const T1 &lhs, const has_value<T2> &rhs)
-> EnableIf_t<!std::is_base_of<Number, T1>{}, bool> {
  return (lhs == rhs.value());
}

template< typename T1,
          typename T2 >
inline auto
operator==(const has_value<T1> &lhs, const T2 &rhs)
-> EnableIf_t<!std::is_base_of<Number, T2>{}, bool> {
  return (lhs.value() == rhs);
}

template< typename T1,
          typename T2 >
inline bool
operator!=(const has_value<T1> &lhs, const has_value<T2> &rhs) {
  return (lhs.value() != rhs.value());
}

template< typename T1,
          typename T2 >
inline auto
operator!=(const T1 &lhs, const has_value<T2> &rhs)
-> EnableIf_t<!std::is_base_of<Number, T1>{}, bool> {
  return (lhs != rhs.value());
}

template< typename T1,
          typename T2 >
inline auto
operator!=(const has_value<T1> &lhs, const T2 &rhs)
-> EnableIf_t<!std::is_base_of<Number, T2>{}, bool> {
  return (lhs.value() != rhs);
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_VALUE_HPP
