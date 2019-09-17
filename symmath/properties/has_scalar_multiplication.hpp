#ifndef SYMMATH_PROPERTIES_HAS_SCALAR_MULTIPLICATION_HPP
#define SYMMATH_PROPERTIES_HAS_SCALAR_MULTIPLICATION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/scalar_mul.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_scalar_multiplication
  : private Property {

  template< typename U,
            bool Left = true >
  inline void assign_scalar_mul(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_scalar_mul_(T1 &lhs, const T2 &rhs) {
  lhs.assign_scalar_mul(rhs);
}

template< typename T >
template< typename U,
          bool Left = true >
inline void
has_scalar_multiplication<T>::assign_scalar_mul(const U &rhs) {
  static_cast<T&>(*this).assign_scalar_mul(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator*(const has_scalar_multiplication<T1> &lhs, const T2 &rhs)
-> std::enable_if_t<!is_scalar<T2>{}, const ScalarMul<T1, T2>> {
  return ScalarMul<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*(const T1 &lhs, const has_scalar_multiplication<T2> &rhs)
-> std::enable_if_t<!is_scalar<T1>{}, const ScalarMul<T1, T2>> {
  return ScalarMul<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto
scalar_mul(const has_scalar_multiplication<T1> &lhs, const T2 &rhs)
-> std::enable_if_t<!is_scalar<T2>{}, const ScalarMul<T1, T2>> {
  return ScalarMul<T1, T2>(static_cast<const T1&>(lhs), rhs);
}

template< typename T1,
          typename T2 >
inline auto
scalar_mul(const T1 &lhs, const has_scalar_multiplication<T2> &rhs)
-> std::enable_if_t<!is_scalar<T1>{}, const ScalarMul<T1, T2>> {
  return ScalarMul<T1, T2>(lhs, static_cast<const T2&>(rhs));
}

// template< typename T1,
//           typename T2 >
// inline auto
// operator*=(has_scalar_multiplication<T1> &lhs, const T2 &rhs)
// -> has_scalar_multiplication<T1> & {
//   assign_scalar_mul_(static_cast<T1&>(lhs), rhs);
//   return lhs;
// }

} // sym

#endif // SYMMATH_PROPERTIES_HAS_SCALAR_MULTIPLICATION_HPP
