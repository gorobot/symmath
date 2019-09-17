#ifndef SYMMATH_PROPERTIES_HAS_ADDITIVE_INVERSE_HPP
#define SYMMATH_PROPERTIES_HAS_ADDITIVE_INVERSE_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/neg.hpp"
#include "../operations/sub.hpp"
#include "../type_traits/has_property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

struct additive_inverse
  : private Property {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_neg_(T1 &lhs, const T2 &rhs) {
  lhs.assign_neg(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
operator-(const T1 &operand)
-> std::enable_if_t<has_property<T1, additive_inverse>{}, const Neg<T1>> {
  return Neg<T1>(operand);
}

template< typename T1 >
inline auto
neg(const T1 &operand)
-> std::enable_if_t<has_property<T1, additive_inverse>{}, const Neg<T1>> {
  return Neg<T1>(operand);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_sub_(T1 &lhs, const T2 &rhs) {
  lhs.assign_sub(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, additive_inverse>{} &&
                    has_property<T2, additive_inverse>{},
                    const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, additive_inverse>{} &&
                    !std::is_same<T1, T2>{},
                    const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T2, additive_inverse>{} &&
                    !std::is_same<T1, T2>{},
                    const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
sub(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, additive_inverse>{} &&
                    has_property<T2, additive_inverse>{},
                    const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
sub(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<(has_property<T1, additive_inverse>{} ||
                     has_property<T2, additive_inverse>{}) &&
                    !std::is_same<T1, T2>{},
                    const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-=(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, additive_inverse>{}, T1&> {
  assign_sub_(lhs, rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ADDITIVE_INVERSE_HPP
