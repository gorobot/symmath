#ifndef SYMMATH_PROPERTIES_HAS_ASSIGN_HPP
#define SYMMATH_PROPERTIES_HAS_ASSIGN_HPP

#include <type_traits>

#include "property.hpp"
#include "../type_traits/is_operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_assign
  : private Property {

  template< typename U >
  inline has_assign<T> &operator=(const U &other);

  template< typename U >
  inline void assign(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_(T1 &lhs, const T2 &rhs) {
  lhs.assign(rhs);
}

// -> std::enable_if_t<!is_operation<T2>{}>

template< typename T1,
          typename T2 >
inline void
assign_(has_assign<T1> &lhs, const has_assign<T2> &rhs) {
  lhs.assign(static_cast<const T2&>(rhs));
}

template< typename T >
template< typename U >
inline has_assign<T> &
has_assign<T>::operator=(const U &other) {
  assign_(static_cast<T&>(*this), other);
  return *this;
}

template< typename T >
template< typename U >
inline void
has_assign<T>::assign(const U &rhs) {
  static_cast<T&>(*this).assign(rhs);
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ASSIGN_HPP
