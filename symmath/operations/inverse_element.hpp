#ifndef SYMMATH_OPERATIONS_INVERSE_ELEMENT_HPP
#define SYMMATH_OPERATIONS_INVERSE_ELEMENT_HPP

#include <symmath/operations/basic/div.hpp>
#include <symmath/operations/basic/inv.hpp>
#include <symmath/operations/basic/neg.hpp>
#include <symmath/operations/basic/sub.hpp>
#include <symmath/properties/addition.hpp>
#include <symmath/properties/inverse_element.hpp>
#include <symmath/properties/multiplication.hpp>
#include <symmath/property_traits/invertible.hpp>
#include <symmath/property_traits/negatable.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_neg_(Negatable<T1> &lhs, const Negatable<T2> &rhs) {
  lhs.assign_neg(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
operator-(const Negatable<T1> &operand)
-> const Neg<T1> {
  return Neg<T1>(operand);
}

template< typename T1 >
inline auto
neg(const Negatable<T1> &operand)
-> const Neg<T1> {
  return Neg<T1>(operand);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_sub_(Negatable<T1> &lhs, const Negatable<T2> &rhs) {
  lhs.assign_sub(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator-(const Negatable<T1> &lhs, const Negatable<T2> &rhs)
-> const Sub<T1, T2> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
sub(const Negatable<T1> &lhs, const Negatable<T2> &rhs)
-> const Sub<T1, T2> {
  return Sub<T1, T2>(lhs, rhs);
}

// template< typename T1,
//           typename T2 >
// inline auto
// operator-=(T1 &lhs, const T2 &rhs)
// -> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{}, T1&> {
//   assign_sub_(lhs, rhs);
//   return lhs;
// }

// -----------------------------------------------------------------------------

template< typename T1,
        typename T2 >
inline void
assign_div_(Invertible<T1> &lhs, const Invertible<T2> &rhs) {
  lhs.assign_div(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
        typename T2 >
inline auto
operator/(const Invertible<T1> &lhs, const Invertible<T2> &rhs)
-> const Div<T1, T2> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
        typename T2 >
inline auto
div(const Invertible<T1> &lhs, const Invertible<T2> &rhs)
-> const Div<T1, T2> {
  return Div<T1, T2>(lhs, rhs);
}

// template< typename T1,
//         typename T2 >
// inline auto
// operator/=(T1 &lhs, const T2 &rhs)
// -> EnableIf_t<HasProperty<T1, InverseElement<Multiplication>>{}, T1&> {
//   assign_div_(lhs, rhs);
//   return lhs;
// }

// -----------------------------------------------------------------------------

template< typename T1,
        typename T2 >
inline void
assign_inv_(Invertible<T1> &lhs, const Invertible<T2> &rhs) {
  lhs.assign_inv(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
inv(const Invertible<T1> &operand)
-> const Inv<T1> {
  return Inv<T1>(operand);
}

} // sym

#endif // SYMMATH_OPERATIONS_INVERSE_ELEMENT_HPP
