#ifndef SYMMATH_PROPERTIES_HAS_SUBTRACTION_HPP
#define SYMMATH_PROPERTIES_HAS_SUBTRACTION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operation/sub.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_subtraction
  : private Property {

  template< typename U >
  inline void assign_sub(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_sub_(T1 &lhs, const T2 &rhs) {
  lhs.assign_sub(rhs);
}

template< typename T >
template< typename U >
inline void
has_subtraction<T>::assign_sub(const U &rhs) {
  static_cast<T&>(*this).assign_sub(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator-(const has_subtraction<T1> &lhs, const has_subtraction<T2> &rhs)
-> const Sub<T1, T2> {
  return Sub<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator-(const has_subtraction<T1> &lhs, const T2 &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Sub<T1, T2>> {
  return Sub<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-(const T1 &lhs, const has_subtraction<T2> &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
sub(const has_subtraction<T1> &lhs, const has_subtraction<T2> &rhs)
-> const Sub<T1, T2> {
  return Sub<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
sub(const has_subtraction<T1> &lhs, const T2 &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Sub<T1, T2>> {
  return Sub<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
sub(const T1 &lhs, const has_subtraction<T2> &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator-=(has_subtraction<T1> &lhs, const T2 &rhs)
-> has_subtraction<T1> & {
  assign_sub_(static_cast<T1&>(lhs), rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_SUBTRACTION_HPP
