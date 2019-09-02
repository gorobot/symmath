#ifndef SYMMATH_PROPERTIES_HAS_ADDITION_HPP
#define SYMMATH_PROPERTIES_HAS_ADDITION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operation/add.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_addition
  : private Property {

  template< typename U >
  inline void assign_add(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_add_(T1 &lhs, const T2 &rhs) {
  lhs.assign_add(rhs);
}

template< typename T >
template< typename U >
inline void
has_addition<T>::assign_add(const U &rhs) {
  static_cast<T&>(*this).assign_add(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator+(const has_addition<T1> &lhs, const has_addition<T2> &rhs)
-> const Add<T1, T2> {
  return Add<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator+(const has_addition<T1> &lhs, const T2 &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator+(const T1 &lhs, const has_addition<T2> &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
add(const has_addition<T1> &lhs, const has_addition<T2> &rhs)
-> const Add<T1, T2> {
  return Add<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
add(const has_addition<T1> &lhs, const T2 &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
add(const T1 &lhs, const has_addition<T2> &rhs)
-> std::enable_if_t<!std::is_same<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator+=(has_addition<T1> &lhs, const T2 &rhs)
-> has_addition<T1> & {
  assign_add_(static_cast<T1&>(lhs), rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ADDITION_HPP
