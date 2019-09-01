#ifndef SYMMATH_PROPERTIES_VALUE_TYPE_HPP
#define SYMMATH_PROPERTIES_VALUE_TYPE_HPP

#include <ostream>
#include <type_traits>

#include "property.hpp"

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
  inline has_value(const ValueType &value);
  inline has_value(ValueType &&value);

  inline has_value<ValueType> &operator=(const ValueType &value);
  inline has_value<ValueType> &operator=(ValueType &&value);

  // inline operator ValueType() const;

private:

  template< typename U >
  friend inline std::ostream&
  operator<<(std::ostream& os, const has_value<U>& m);

  template< typename T1,
            typename T2 >
  friend inline bool
  operator==(const has_value<T1> &lhs, const T2 &rhs);

  template< typename T1,
            typename T2 >
  friend inline bool
  operator==(const T1 &lhs, const has_value<T2> &rhs);

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
has_value<T>::operator=(const T &value) {
  value_ = value;
  return *this;
}

template< typename T >
inline has_value<T> &
has_value<T>::operator=(T &&value) {
  value_ = std::move(value);
  return *this;
}

// template< typename T >
// inline
// has_value<T>::operator has_value<T>::ValueType() const {
//   return value_;
// }

// -----------------------------------------------------------------------------

template< typename U >
inline std::ostream&
operator<<(std::ostream& os, const has_value<U>& m) {
  return os << m.value_;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline bool
operator==(const has_value<T1> &lhs, const T2 &rhs) {
  return (lhs.value_ == rhs);
}

template< typename T1,
          typename T2 >
inline bool
operator==(const T1 &lhs, const has_value<T2> &rhs) {
  return (lhs == rhs.value_);
}

} // sym

#endif // SYMMATH_PROPERTIES_VALUE_TYPE_HPP
