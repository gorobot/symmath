#ifndef SYMMATH_PROPERTIES_HAS_DIVISION_HPP
#define SYMMATH_PROPERTIES_HAS_DIVISION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/div.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_division
  : private Property {

  template< typename U >
  inline void assign_div(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_div_(T1 &lhs, const T2 &rhs) {
  lhs.assign_div(rhs);
}

template< typename T >
template< typename U >
inline void
has_division<T>::assign_div(const U &rhs) {
  static_cast<T&>(*this).assign_div(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator/(const has_division<T1> &lhs,
          const has_division<T2> &rhs)
-> const Div<T1, T2> {
  return Div<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator/(const has_division<T1> &lhs,
          const T2 &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Div<T1, T2>> {
  return Div<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator/(const T1 &lhs,
          const has_division<T2> &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Div<T1, T2>> {
  return Div<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
div(const has_division<T1> &lhs,
    const has_division<T2> &rhs)
-> const Div<T1, T2> {
  return Div<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
div(const has_division<T1> &lhs,
    const T2 &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Div<T1, T2>> {
  return Div<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
div(const T1 &lhs,
    const has_division<T2> &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Div<T1, T2>> {
  return Div<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator/=( has_division<T1> &lhs,
            const T2 &rhs )
-> has_division<T1> & {
  assign_div_(static_cast<T1&>(lhs), rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_DIVISION_HPP
