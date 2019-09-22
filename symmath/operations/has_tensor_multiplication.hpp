#ifndef SYMMATH_PROPERTIES_HAS_TENSOR_MULTIPLICATION_HPP
#define SYMMATH_PROPERTIES_HAS_TENSOR_MULTIPLICATION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/mul.hpp"
#include "../type_traits/enable_if.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_tensor_multiplication
  : private Property {

  template< typename U >
  inline void assign_tensor_mul(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_tensor_mul_(T1 &lhs, const T2 &rhs) {
  lhs.assign_tensor_mul(rhs);
}

template< typename T >
template< typename U >
inline void
has_tensor_multiplication<T>::assign_tensor_mul(const U &rhs) {
  static_cast<T&>(*this).assign_tensor_mul(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator*(const has_tensor_multiplication<T1> &lhs, const has_tensor_multiplication<T2> &rhs)
-> const Mul<T1, T2> {
  return Mul<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator*(const has_tensor_multiplication<T1> &lhs, const T2 &rhs)
-> EnableIf_t<!std::is_same<T1, T2>{}, const Mul<T1, T2>> {
  return Mul<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*(const T1 &lhs, const has_tensor_multiplication<T2> &rhs)
-> EnableIf_t<!std::is_same<T1, T2>{}, const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
mul(const has_tensor_multiplication<T1> &lhs, const has_tensor_multiplication<T2> &rhs)
-> const Mul<T1, T2> {
  return Mul<T1, T2>(static_cast<const T1&>(lhs), static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
mul(const has_tensor_multiplication<T1> &lhs, const T2 &rhs)
-> EnableIf_t<!std::is_same<T1, T2>{}, const Mul<T1, T2>> {
  return Mul<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
mul(const T1 &lhs, const has_tensor_multiplication<T2> &rhs)
-> EnableIf_t<!std::is_same<T1, T2>{}, const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator*=(has_tensor_multiplication<T1> &lhs, const T2 &rhs)
-> has_tensor_multiplication<T1> & {
  assign_tensor_mul_(static_cast<T1&>(lhs), rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_TENSOR_MULTIPLICATION_HPP
