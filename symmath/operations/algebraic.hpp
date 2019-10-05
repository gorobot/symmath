#ifndef SYMMATH_OPERATIONS_ALGEBRAIC_HPP
#define SYMMATH_OPERATIONS_ALGEBRAIC_HPP

#include <symmath/operations/algebraic/abs.hpp>
#include <symmath/operations/algebraic/add.hpp>
#include <symmath/operations/algebraic/conj.hpp>
#include <symmath/operations/algebraic/div.hpp>
#include <symmath/operations/algebraic/exp.hpp>
#include <symmath/operations/algebraic/factorial.hpp>
#include <symmath/operations/algebraic/inv.hpp>
#include <symmath/operations/algebraic/mul.hpp>
#include <symmath/operations/algebraic/neg.hpp>
#include <symmath/operations/algebraic/pow.hpp>
#include <symmath/operations/algebraic/prod.hpp>
#include <symmath/operations/algebraic/sub.hpp>
#include <symmath/operations/algebraic/sum.hpp>
#include <symmath/property_traits/addable.hpp>
#include <symmath/property_traits/comparable.hpp>
#include <symmath/property_traits/invertible.hpp>
#include <symmath/property_traits/multipliable.hpp>
#include <symmath/property_traits/negatable.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1, typename T2 >
inline auto assign_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>>;

template< typename T1, typename T2 >
inline auto assign_add_(Addable<T1> &lhs, const Addable<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>>;

template< typename T1, typename T2 >
inline auto assign_div_(Invertible<T1> &lhs, const Invertible<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>>;

template< typename T1, typename T2 >
inline auto assign_mul_(Multipliable<T1> &lhs, const Multipliable<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>>;

template< typename T1, typename T2 >
inline auto assign_sub_(Negatable<T1> &lhs, const Negatable<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>>;

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>> {
  lhs.assign(rhs);
}

template< typename T1,
          typename T2 >
inline auto
assign_add_(Addable<T1> &lhs, const Addable<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>> {
  lhs.assign_add(rhs);
}

template< typename T1,
          typename T2 >
inline auto
assign_div_(Invertible<T1> &lhs, const Invertible<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>> {
  lhs.assign_div(rhs);
}

template< typename T1,
          typename T2 >
inline auto
assign_mul_(Multipliable<T1> &lhs, const Multipliable<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>> {
  lhs.assign_mul(rhs);
}

template< typename T1,
          typename T2 >
inline auto
assign_sub_(Negatable<T1> &lhs, const Negatable<T2> &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>> {
  lhs.assign_sub(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1, typename T2 >
inline bool operator<(const Comparable<T1> &lhs, const Comparable<T2> &rhs);
template< typename T1, typename T2 >
inline bool operator<=(const Comparable<T1> &lhs, const Comparable<T2> &rhs);
template< typename T1, typename T2 >
inline bool operator>(const Comparable<T1> &lhs, const Comparable<T2> &rhs);
template< typename T1, typename T2 >
inline bool operator>=(const Comparable<T1> &lhs, const Comparable<T2> &rhs);

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline bool
operator<(const Comparable<T1> &lhs, const Comparable<T2> &rhs) {
  return lhs < rhs;
}

template< typename T1,
          typename T2 >
inline bool
operator<=(const Comparable<T1> &lhs, const Comparable<T2> &rhs) {
  return lhs <= rhs;
}

template< typename T1,
          typename T2 >
inline bool
operator>(const Comparable<T1> &lhs, const Comparable<T2> &rhs) {
  return lhs > rhs;
}

template< typename T1,
          typename T2 >
inline bool
operator>=(const Comparable<T1> &lhs, const Comparable<T2> &rhs) {
  return lhs >= rhs;
}

// -----------------------------------------------------------------------------

template< typename T1, typename T2 >
inline auto operator+(Addable<T1> &&lhs, Addable<T2> &&rhs)
-> const Add<T1, T2>;

template< typename T1, typename T2 >
inline auto operator/(Invertible<T1> &&lhs, Invertible<T2> &&rhs)
-> const Div<T1, T2>;

template< typename T1, typename T2 >
inline auto operator*(Multipliable<T1> &&lhs, Multipliable<T2> &&rhs)
-> const Mul<T1, T2>;

template< typename T1, typename T2 >
inline auto operator-(Negatable<T1> &&lhs, Negatable<T2> &&rhs)
-> const Sub<T1, T2>;

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto operator+(Addable<T1> &&lhs, Addable<T2> &&rhs)
-> const Add<T1, T2> {
  return Add<T1, T2>(std::forward<T1>(lhs), std::forward<T2>(rhs));
}

template< typename T1,
          typename T2 >
inline auto operator/(Invertible<T1> &&lhs, Invertible<T2> &&rhs)
-> const Div<T1, T2> {
  return Div<T1, T2>(std::forward<T1>(lhs), std::forward<T2>(rhs));
}

template< typename T1,
          typename T2 >
inline auto operator*(Multipliable<T1> &&lhs, Multipliable<T2> &&rhs)
-> const Mul<T1, T2> {
  return Mul<T1, T2>(std::forward<T1>(lhs), std::forward<T2>(rhs));
}

template< typename T1,
          typename T2 >
inline auto operator-(Negatable<T1> &&lhs, Negatable<T2> &&rhs)
-> const Sub<T1, T2> {
  return Sub<T1, T2>(std::forward<T1>(lhs), std::forward<T2>(rhs));
}

// -----------------------------------------------------------------------------

// template< typename T1, typename T2 >
// inline T1 &operator+=(Addable<T1> &lhs, const Addable<T2> &rhs);
//
// template< typename T1, typename T2 >
// inline T1 &operator/=(Invertible<T1> &lhs, const Invertible<T2> &rhs);
//
// template< typename T1, typename T2 >
// inline T1 &operator*=(Multipliable<T1> &lhs, const Multipliable<T2> &rhs);
//
// template< typename T1, typename T2 >
// inline T1 &operator-=(Negatable<T1> &lhs, const Negatable<T2> &rhs);

// -----------------------------------------------------------------------------

template< typename T >
inline auto abs(T &&operand)
-> const Abs<T>;

template< typename T1, typename T2 >
inline auto add(Addable<T1> &&lhs, Addable<T2> &&rhs)
-> const Add<T1, T2>;

template< typename T >
inline auto conj(T &&operand)
-> const Conj<T>;

template< typename T1, typename T2 >
inline auto div(Invertible<T1> &&lhs, Invertible<T2> &&rhs)
-> const Div<T1, T2>;

template< typename T >
inline auto exp(T &&operand)
-> const Exp<T>;

template< typename T >
inline auto factorial(T &&operand)
-> const Factorial<T>;

template< typename T >
inline auto inv(T &&operand)
-> const Inv<T>;

template< typename T1, typename T2 >
inline auto mul(Multipliable<T1> &&lhs, Multipliable<T2> &&rhs)
-> const Mul<T1, T2>;

template< typename T >
inline auto neg(T &&operand)
-> const Neg<T>;

template< typename T1, typename T2 >
inline auto pow(T1 &&base, T2 &&exponent)
-> const Pow<T1, T2>;

// template< typename ...T >
// inline auto prod(T&&... operand)
// -> const Prod<T>;

template< typename T1, typename T2 >
inline auto sub(Negatable<T1> &&lhs, Negatable<T2> &&rhs)
-> const Sub<T1, T2>;

// template< typename ...T >
// inline auto sum(T&&... operand)
// -> const Sum<T>;

// -----------------------------------------------------------------------------

template< typename T >
inline auto abs(T &&operand)
-> const Abs<T> {
  return Abs<T>(std::forward<T>(operand));
}

template< typename T1,
          typename T2 >
inline auto add(Addable<T1> &&lhs, Addable<T2> &&rhs)
-> const Add<T1, T2> {
  return Add<T1, T2>(std::forward<T1>(lhs), std::forward<T2>(rhs));
}

template< typename T >
inline auto conj(T &&operand)
-> const Conj<T> {
  return Conj<T>(std::forward<T>(operand));
}

} // sym

#endif // SYMMATH_OPERATIONS_ALGEBRAIC_HPP
