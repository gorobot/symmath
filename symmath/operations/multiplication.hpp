#ifndef SYMMATH_OPERATIONS_MULTIPLICATION_HPP
#define SYMMATH_OPERATIONS_MULTIPLICATION_HPP

#include <type_traits>

#include <symmath/operations/mul.hpp>
#include <symmath/properties/multiplication.hpp>
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_mul_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, Multiplication>{} &&
              HasProperty<T2, Multiplication>{} &&
              std::is_same<T1, T2>{}> {
  lhs.assign_mul(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
auto
operator*(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, Multiplication>{} &&
              HasProperty<T2, Multiplication>{} &&
              std::is_same<T1, T2>{},
              const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
auto
mul(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, Multiplication>{} &&
              HasProperty<T2, Multiplication>{} &&
              std::is_same<T1, T2>{},
              const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*=(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, Multiplication>{} &&
              HasProperty<T2, Multiplication>{} &&
              std::is_same<T1, T2>{},
              T1&> {
  assign_mul_(lhs, rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_OPERATIONS_MULTIPLICATION_HPP
