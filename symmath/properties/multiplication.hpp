#ifndef SYMMATH_PROPERTIES_HAS_MULTIPLICATION_HPP
#define SYMMATH_PROPERTIES_HAS_MULTIPLICATION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/mul.hpp"
#include "../operations/pow.hpp"
#include "../type_traits/has_property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

struct multiplication
  : private Property {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_mul_(T1 &lhs, const T2 &rhs) {
  lhs.assign_mul(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator*(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplication>{} &&
                    has_property<T2, multiplication>{},
                    const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<(has_property<T1, multiplication>{} ||
                     has_property<T2, multiplication>{}) &&
                    !std::is_same<T1, T2>{},
                    const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
mul(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplication>{} &&
                    has_property<T2, multiplication>{},
                    const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
mul(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<(has_property<T1, multiplication>{} ||
                     has_property<T2, multiplication>{}) &&
                    !std::is_same<T1, T2>{},
                    const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*=(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplication>{}, T1&> {
  assign_mul_(lhs, rhs);
  return lhs;
}

// -----------------------------------------------------------------------------


template< typename T1,
          typename T2 >
inline void
assign_pow_(T1 &operand, const T2 &p) {
  operand.assign_pow(p);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator^(const T1 &operand, const T2 &p)
-> std::enable_if_t<has_property<T1, multiplication>{}, const Pow<T1, T2>> {
  return Pow<T1, T2>(operand, p);
}

template< typename T1,
          typename T2 >
inline auto
pow(const T1 &operand, const T2 &p)
-> std::enable_if_t<has_property<T1, multiplication>{}, const Pow<T1, T2>> {
  return Pow<T1, T2>(operand, p);
}

template< typename T1,
          typename T2 >
inline auto
operator^=(T1 &operand, const T2 &p)
-> std::enable_if_t<has_property<T1, multiplication>{}, T1&> {
  assign_pow_(operand, p);
  return operand;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_MULTIPLICATION_HPP
