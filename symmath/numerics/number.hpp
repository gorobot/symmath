#ifndef SYMMATH_NUMERICS_NUMBER_HPP
#define SYMMATH_NUMERICS_NUMBER_HPP

#include <symmath/operations/basic.hpp>
#include <symmath/type_traits/covariant.hpp>
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

// template< typename T1,
//           typename T2 >
// inline auto operator+(const T1 &lhs, const T2 &rhs)
// -> EnableIf_t<IsBasicNumber<T2> &&
//               IsCovariant<ResultType_t<T1>, ResultType_t<T2>>,
//               const Add<T1, T1>>;
//
// template< typename T1,
//           typename T2 >
// inline auto operator+(const T1 &lhs, const T2 &rhs)
// -> EnableIf_t<IsBasicNumber<T1> &&
//               IsCovariant<ResultType_t<T1>, ResultType_t<T2>>,
//               const Add<T2, T2>>;

// template< typename T1,
//           typename T2 >
// inline auto operator/(const Number<T1> &lhs, const T2 &rhs)
// -> EnableIf_t<IsBasicNumber<T2>, const Div<T1, T1>>;
//
// template< typename T1,
//           typename T2 >
// inline auto operator/(const T1 &lhs, const Number<T2> &rhs)
// -> EnableIf_t<IsBasicNumber<T1>, const Div<T2, T2>>;
//
// template< typename T1,
//           typename T2 >
// inline auto operator*(const Number<T1> &lhs, const T2 &rhs)
// -> EnableIf_t<IsBasicNumber<T2>, const Mul<T1, T1>>;
//
// template< typename T1,
//           typename T2 >
// inline auto operator*(const T1 &lhs, const Number<T2> &rhs)
// -> EnableIf_t<IsBasicNumber<T1>, const Mul<T2, T2>>;
//
// template< typename T1,
//           typename T2 >
// inline auto operator-(const Number<T1> &lhs, const T2 &rhs)
// -> EnableIf_t<IsBasicNumber<T2>, const Sub<T1, T1>>;
//
// template< typename T1,
//           typename T2 >
// inline auto operator-(const T1 &lhs, const Number<T2> &rhs)
// -> EnableIf_t<IsBasicNumber<T1>, const Sub<T2, T2>>;

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Add<T1, CT>> {
  return Add<T1, CT>(lhs, CT(rhs));
}

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Add<CT, T2>> {
  return Add<CT, T2>(CT(lhs), rhs);
}

// -----------------------------------------------------------------------------


template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Div<T1, CT>> {
  return Div<T1, CT>(lhs, CT(rhs));
}

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator/(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Div<CT, T2>> {
  return Div<CT, T2>(CT(lhs), rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator*(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Mul<T1, CT>> {
  return Mul<T1, CT>(lhs, CT(rhs));
}

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator*(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Mul<CT, T2>> {
  return Mul<CT, T2>(CT(lhs), rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Sub<T1, CT>> {
  return Sub<T1, CT>(lhs, CT(rhs));
}

template< typename T1,
          typename T2,
          typename CT = Covariant_t<ResultType_t<T1>, ResultType_t<T2>> >
inline auto
operator-(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Sub<CT, T2>> {
  return Sub<CT, T2>(CT(lhs), rhs);
}

// -----------------------------------------------------------------------------

template< typename T >
inline std::ostream &
operator<<(std::ostream &os, const Number<T> &m) {
  return os << static_cast<const T&>(m).value();
}

} // sym

#endif // SYMMATH_NUMERICS_NUMBER_HPP
