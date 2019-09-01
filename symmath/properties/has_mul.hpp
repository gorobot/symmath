#ifndef SYMMATH_PROPERTIES_HAS_MUL_HPP
#define SYMMATH_PROPERTIES_HAS_MUL_HPP

#include <type_traits>

#include "property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Mul;

template< typename T >
struct has_mul
  : private Property {

  inline has_mul<T> &operator=(const Mul<T, T> &other);

  inline void assign_mul(const T &rhs);

};

// -----------------------------------------------------------------------------

template< typename T >
inline void
assign_mul_(has_mul<T> &lhs, const has_mul<T> &rhs) {
  lhs.assign_mul(static_cast<const T &>(rhs));
}

template< typename T >
inline void
assign_mul_(has_mul<T> &lhs, const typename T::ValueType &rhs) {
  static_cast<T &>(lhs).assign_mul(rhs);
}

template< typename T >
inline has_mul<T> &
has_mul<T>::operator=(const Mul<T, T> &other) {
  assign_(*this, other);
  return *this;
}

template< typename T >
inline void
has_mul<T>::assign_mul(const T &rhs) {
  static_cast<T &>(*this).assign_mul(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Mul {
public:

private:

  T1 lhs_;
  T2 rhs_;

public:

  Mul(const has_mul<T1> &lhs, const has_mul<T2> &rhs);

private:

  template< typename U >
  friend void
  assign_(has_mul<U> &lhs, const Mul<T1, T2> &rhs) {
    assign_(static_cast<U &>(lhs), rhs.lhs_);
    assign_mul_(static_cast<U &>(lhs), rhs.rhs_);
  }
};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
Mul<T1, T2>::Mul(const has_mul<T1> &lhs, const has_mul<T2> &rhs)
  : lhs_(static_cast<const T1 &>(lhs)),
    rhs_(static_cast<const T2 &>(rhs)) {}

// -----------------------------------------------------------------------------

template< typename T >
inline auto
operator*(const has_mul<T> &lhs, const has_mul<T> &rhs)
-> const Mul<T, T> {
  return Mul<T, T>(lhs, rhs);
}

template< typename T >
inline auto
operator*(const has_mul<T> &lhs, const typename T::ValueType &rhs)
-> const Mul<T, T> {
  const T tmp(rhs);
  return Mul<T, T>(static_cast<const T &>(lhs), tmp);
}

template< typename T >
inline auto
operator*(const typename T::ValueType &lhs, const has_mul<T> &rhs)
-> const Mul<T, T> {
  const T tmp(lhs);
  return Mul<T, T>(tmp, static_cast<const T &>(rhs));
}

// template< typename T >
// inline auto
// operator*(const has_mul<T> &lhs, const typename T::ValueType &rhs)
// -> const Mul<T, typename T::ValueType> {
//   return Mul<T, typename T::ValueType>(static_cast<const T &>(lhs), rhs);
// }
//
// template< typename T >
// inline auto
// operator*(const typename T::ValueType &lhs, const has_mul<T> &rhs)
// -> const Mul<typename T::ValueType, T> {
//   return Mul<typename T::ValueType, T>(lhs, static_cast<const T &>(rhs));
// }

template< typename T >
inline auto
operator*=(has_mul<T> &lhs, const has_mul<T> &rhs)
-> has_mul<T> & {
  assign_mul_(static_cast<T &>(lhs), static_cast<const T &>(rhs));
  return lhs;
}

template< typename T >
inline auto
operator*=(has_mul<T> &lhs, const typename T::ValueType &rhs)
-> has_mul<T> & {
  assign_mul_(static_cast<T &>(lhs), rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_MUL_HPP
