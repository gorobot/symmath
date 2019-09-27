#ifndef SYMMATH_NUMERICS_NUMBER_HPP
#define SYMMATH_NUMERICS_NUMBER_HPP

#include <symmath/operations/basic.hpp>
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
          typename T2 >
inline auto operator+(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Add<T1, T1>>;

template< typename T1,
          typename T2 >
inline auto operator+(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Add<T2, T2>>;

template< typename T1,
          typename T2 >
inline auto operator/(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Div<T1, T1>>;

template< typename T1,
          typename T2 >
inline auto operator/(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Div<T2, T2>>;

template< typename T1,
          typename T2 >
inline auto operator*(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Mul<T1, T1>>;

template< typename T1,
          typename T2 >
inline auto operator*(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Mul<T2, T2>>;

template< typename T1,
          typename T2 >
inline auto operator-(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Sub<T1, T1>>;

template< typename T1,
          typename T2 >
inline auto operator-(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Sub<T2, T2>>;

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto operator+(const Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, const Add<T1, T1>> {
  return Add<T1, T1>(static_cast<const T1&>(lhs), T1(rhs));
}

template< typename T1,
          typename T2 >
inline auto operator+(const T1 &lhs, const Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, const Add<T2, T2>> {
  return Add<T2, T2>(T2(lhs), static_cast<const T2&>(rhs));
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto operator-(Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Number<T1>> {
  // static_cast<T1&>(lhs).assign_sub(rhs);
  return lhs;
}

template< typename T1,
          typename T2 >
inline auto operator-(const T1 &lhs, Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Number<T2>> {
  // static_cast<T2&>(rhs).assign_sub(lhs);
  return rhs;
}

template< typename T1,
          typename T2 >
inline auto operator-=(Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Number<T1>> {
  // static_cast<T1&>(lhs).assign_sub(rhs);
  return lhs;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto operator*(Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Number<T1>> {
  // static_cast<T1&>(lhs).assign_mul(rhs);
  return lhs;
}

template< typename T1,
          typename T2 >
inline auto operator*(const T1 &lhs, Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Number<T2>> {
  // static_cast<T2&>(rhs).assign_mul(lhs);
  return rhs;
}

template< typename T1,
          typename T2 >
inline auto operator*=(Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Number<T1>> {
  // static_cast<T1&>(lhs).assign_mul(rhs);
  return lhs;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto operator/(Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Number<T1>> {
  // static_cast<T1&>(lhs).assign_div(rhs);
  return lhs;
}

template< typename T1,
          typename T2 >
inline auto operator/(const T1 &lhs, Number<T2> &rhs)
-> EnableIf_t<IsBasicNumber<T1>, Number<T2>> {
  // static_cast<T2&>(rhs).assign_div(lhs);
  return rhs;
}

template< typename T1,
          typename T2 >
inline auto operator/=(Number<T1> &lhs, const T2 &rhs)
-> EnableIf_t<IsBasicNumber<T2>, Number<T1>> {
  // static_cast<T1&>(lhs).assign_div(rhs);
  return lhs;
}

// -----------------------------------------------------------------------------

template< typename T >
inline std::ostream &
operator<<(std::ostream &os, const Number<T> &m) {
  return os << static_cast<const T&>(m).value();
}

} // sym

#endif // SYMMATH_NUMERICS_NUMBER_HPP
