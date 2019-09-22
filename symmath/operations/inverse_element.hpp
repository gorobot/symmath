#ifndef SYMMATH_OPERATIONS_INVERSE_ELEMENT_HPP
#define SYMMATH_OPERATIONS_INVERSE_ELEMENT_HPP

#include <symmath/properties/addition.hpp>
#include <symmath/properties/inverse_element.hpp>
#include <symmath/properties/multiplication.hpp>
#include <symmath/operations/div.hpp>
#include <symmath/operations/inv.hpp>
#include <symmath/operations/neg.hpp>
#include <symmath/operations/sub.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/has_property.hpp>

namespace sym {

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
-> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{},
              const Neg<T1>> {
  return Neg<T1>(operand);
}

template< typename T1 >
inline auto
neg(const T1 &operand)
-> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{},
              const Neg<T1>> {
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
-> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{} &&
              HasProperty<T2, InverseElement<Addition>>{},
              const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{} &&
              !std::is_same<T1, T2>{},
              const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T2, InverseElement<Addition>>{} &&
              !std::is_same<T1, T2>{},
              const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
sub(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{} &&
              HasProperty<T2, InverseElement<Addition>>{},
              const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
sub(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<(HasProperty<T1, InverseElement<Addition>>{} ||
               HasProperty<T2, InverseElement<Addition>>{}) &&
              !std::is_same<T1, T2>{},
              const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator-=(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Addition>>{}, T1&> {
  assign_sub_(lhs, rhs);
  return lhs;
}

// -----------------------------------------------------------------------------

template< typename T1,
        typename T2 >
inline void
assign_div_(T1 &lhs, const T2 &rhs) {
  lhs.assign_div(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
        typename T2 >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Multiplication>>{} &&
              HasProperty<T2, InverseElement<Multiplication>>{},
              const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
        typename T2 >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Multiplication>>{} &&
              !std::is_same<T1, T2>{},
              const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
        typename T2 >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T2, InverseElement<Multiplication>>{} &&
              !std::is_same<T1, T2>{},
              const Div<T1, T2>> {
return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
        typename T2 >
inline auto
div(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Multiplication>>{} &&
              HasProperty<T2, InverseElement<Multiplication>>{},
              const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
        typename T2 >
inline auto
div(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<(HasProperty<T1, InverseElement<Multiplication>>{} ||
               HasProperty<T2, InverseElement<Multiplication>>{}) &&
              !std::is_same<T1, T2>{},
              const Div<T1, T2>> {
  return Div<T1, T2>(lhs, rhs);
}

template< typename T1,
        typename T2 >
inline auto
operator/=(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, InverseElement<Multiplication>>{}, T1&> {
  assign_div_(lhs, rhs);
  return lhs;
}

// -----------------------------------------------------------------------------

template< typename T1,
        typename T2 >
inline void
assign_inv_(T1 &lhs, const T2 &rhs) {
  lhs.assign_inv(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
inv(const T1 &operand)
-> EnableIf_t<HasProperty<T1, InverseElement<Multiplication>>{},
              const Inv<T1>> {
  return Inv<T1>(operand);
}

} // sym

#endif // SYMMATH_OPERATIONS_INVERSE_ELEMENT_HPP
