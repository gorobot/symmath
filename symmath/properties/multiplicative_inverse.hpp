#ifndef SYMMATH_PROPERTIES_HAS_MULTIPLICATIVE_INVERSE_HPP
#define SYMMATH_PROPERTIES_HAS_MULTIPLICATIVE_INVERSE_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/div.hpp"
#include "../operations/inv.hpp"
#include "../type_traits/has_property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

struct multiplicative_inverse
  : private Property {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_div_(T1 &lhs, const T2 &rhs) {
  lhs.assign_div(rhs);
}

template< typename T1,
          typename T2 >
inline void
assign_inv_(T1 &lhs, const T2 &rhs) {
  lhs.assign_inv(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplicative_inverse>{} &&
                    has_property<T2, multiplicative_inverse>{},
                    const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplicative_inverse>{} &&
                    !std::is_same<T1, T2>{},
                    const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T2, multiplicative_inverse>{} &&
                    !std::is_same<T1, T2>{},
                    const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
add(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplicative_inverse>{} &&
                    has_property<T2, multiplicative_inverse>{},
                    const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
add(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<(has_property<T1, multiplicative_inverse>{} ||
                     has_property<T2, multiplicative_inverse>{}) &&
                    !std::is_same<T1, T2>{},
                    const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator/=(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, multiplicative_inverse>{}, T1&> {
  assign_div_(lhs, rhs);
  return lhs;
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
inv(const T1 &operand)
-> std::enable_if_t<has_property<T1, multiplicative_inverse>{}, const Inv<T1>> {
  return Inv<T1>(operand);
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_MULTIPLICATIVE_INVERSE_HPP
