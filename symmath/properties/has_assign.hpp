#ifndef SYMMATH_PROPERTIES_HAS_ASSIGN_HPP
#define SYMMATH_PROPERTIES_HAS_ASSIGN_HPP

#include <type_traits>

#include "property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_assign
  : private Property {

  inline has_assign<T> &operator=(const has_assign<T> &other);

  inline void assign(const T &rhs);

};

// -----------------------------------------------------------------------------

template< typename T >
inline void
assign_(has_assign<T> &lhs, const has_assign<T> &rhs) {
  lhs.assign(static_cast<const T &>(rhs));
}

template< typename T >
inline has_assign<T> &
has_assign<T>::operator=(const has_assign<T> &other) {
  assign_(*this, other);
  return *this;
}

template< typename T >
inline void
has_assign<T>::assign(const T &rhs) {
  static_cast<T &>(*this).assign(rhs);
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ASSIGN_HPP
