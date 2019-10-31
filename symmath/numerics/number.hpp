#ifndef SYMMATH_NUMERICS_NUMBER_HPP
#define SYMMATH_NUMERICS_NUMBER_HPP

#include <symmath/operations/algebraic.hpp>
#include <symmath/property_traits/addable.hpp>
#include <symmath/property_traits/comparable.hpp>
#include <symmath/property_traits/invertible.hpp>
#include <symmath/property_traits/multipliable.hpp>
#include <symmath/property_traits/negatable.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_basic_number.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Number {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline bool operator==(const Number<T1> &lhs, const Number<T2> &rhs) {
  return (static_cast<const T1&>(lhs).value() ==
          static_cast<const T2&>(rhs).value());
}

template< typename T1,
          typename T2 >
inline auto operator==(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, bool> {
  return (static_cast<const T1&>(lhs).value() == rhs);
}

template< typename T1,
          typename T2 >
inline auto operator==(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, bool> {
  return (lhs == static_cast<const T2&>(rhs).value());
}

template< typename T1,
          typename T2 >
inline bool operator!=(const Number<T1> &lhs, const Number<T2> &rhs) {
  return !(static_cast<const T1&>(lhs) == static_cast<const T2&>(rhs));
}

template< typename T1,
          typename T2 >
inline auto operator!=(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, bool> {
  return !(static_cast<const T1&>(lhs) == rhs);
}

template< typename T1,
          typename T2 >
inline auto operator!=(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, bool> {
  return !(lhs == static_cast<const T2&>(rhs));
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator+(Addable<T1> &&lhs, T2 &&rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Add<T1, CT>> {
  return Add<T1, CT>(std::forward<T1>(lhs), std::forward<CT>(CT(rhs)));
}

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator+(T1 &&lhs, Addable<T2> &&rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Add<CT, T2>> {
  return Add<CT, T2>(std::forward<CT>(CT(lhs)), std::forward<T2>(rhs));
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator/(Invertible<T1> &&lhs, T2 &&rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Div<T1, CT>> {
  return Div<T1, CT>(std::forward<T1>(lhs), std::forward<CT>(CT(rhs)));
}

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator/(T1 &&lhs, Invertible<T2> &&rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Div<CT, T2>> {
  return Div<CT, T2>(std::forward<CT>(CT(lhs)), std::forward<T2>(rhs));
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator*(Multipliable<T1> &&lhs, T2 &&rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Mul<T1, CT>> {
  return Mul<T1, CT>(std::forward<T1>(lhs), std::forward<CT>(CT(rhs)));
}

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator*(T1 &&lhs, Multipliable<T2> &&rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Mul<CT, T2>> {
  return Mul<CT, T2>(std::forward<CT>(CT(lhs)), std::forward<T2>(rhs));
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator-(Negatable<T1> &&lhs, T2 &&rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Sub<T1, CT>> {
  return Sub<T1, CT>(std::forward<T1>(lhs), std::forward<CT>(CT(rhs)));
}

template< typename T1,
          typename T2,
          typename CT = CovariantResult_t<T1, T2> >
inline auto
operator-(T1 &&lhs, Negatable<T2> &&rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Sub<CT, T2>> {
  return Sub<CT, T2>(std::forward<CT>(CT(lhs)), std::forward<T2>(rhs));
}

// -----------------------------------------------------------------------------

// template< typename T >
// inline auto abs(T &&operand)
// -> EnableIf_t<IsBasicNumber<T>, const Abs<T>>;
//
// template< typename T1, typename T2 >
// inline auto add(Addable<T1> &&lhs, Addable<T2> &&rhs)
// -> const Add<T1, T2>;
//
// template< typename T >
// inline auto conj(T &&operand)
// -> EnableIf_t<IsBasicNumber<T>, const Conj<T>>;
//
// template< typename T1, typename T2 >
// inline auto div(Invertible<T1> &&lhs, Invertible<T2> &&rhs)
// -> const Div<T1, T2>;
//
// template< typename T >
// inline auto exp(T &&operand)
// -> const Exp<T>;
//
// template< typename T >
// inline auto factorial(T &&operand)
// -> const Factorial<T>;
//
// template< typename T >
// inline auto inv(T &&operand)
// -> const Inv<T>;
//
// template< typename T1, typename T2 >
// inline auto mul(Multipliable<T1> &&lhs, Multipliable<T2> &&rhs)
// -> const Mul<T1, T2>;
//
// template< typename T >
// inline auto neg(T &&operand)
// -> const Neg<T>;
//
// template< typename T1, typename T2 >
// inline auto pow(T1 &&lhs, T2 &&rhs)
// -> const Pow<T1, T2>;
//
// template< typename T1, typename T2 >
// inline auto prod(T1 &&lhs, T2 &&rhs)
// -> const Prod<T1, T2>;
//
// template< typename T1, typename T2 >
// inline auto sub(Negatable<T1> &&lhs, Negatable<T2> &&rhs)
// -> const Sub<T1, T2>;
//
// template< typename T1, typename T2 >
// inline auto sum(T1 &&lhs, T2 &&rhs)
// -> const Sum<T1, T2>;

// -----------------------------------------------------------------------------

// template< typename T >
// inline auto abs(T &&operand)
// -> const Abs<T> {
//   return Abs<T>(std::forward<T>(operand));
// }
//
// template< typename T1,
//           typename T2 >
// inline auto add(Addable<T1> &&lhs, Addable<T2> &&rhs)
// -> const Add<T1, T2> {
//   return Add<T1, T2>(std::forward<T1>(lhs), std::forward<T2>(rhs));
// }
//
// template< typename T >
// inline auto conj(T &&operand)
// -> const Conj<T> {
//   return Conj<T>(std::forward<T>(operand));
// }

// -----------------------------------------------------------------------------

template< typename T >
inline std::ostream &
operator<<(std::ostream &os, const Number<T> &m) {
  return os << static_cast<const T&>(m).value();
}

} // sym

#endif // SYMMATH_NUMERICS_NUMBER_HPP
