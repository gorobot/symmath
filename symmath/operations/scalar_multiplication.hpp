#ifndef SYMMATH_OPERATIONS_SCALAR_MULTIPLICATION_HPP
#define SYMMATH_OPERATIONS_SCALAR_MULTIPLICATION_HPP

#include <type_traits>

#include <symmath/operations/scalar_mul.hpp>
#include <symmath/properties/scalar_multiplication.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/property_traits/is_scalar.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_scalar_mul_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, ScalarMultiplication>{} &&
              HasProperty<T2, ScalarMultiplication>{} &&
              std::is_same<T1, T2>{}> {
  lhs.assign_scalar_mul(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
auto
operator*(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, ScalarMultiplication>{} &&
              HasProperty<T2, ScalarMultiplication>{} &&
              std::is_same<T1, T2>{},
              const ScalarMul<T1, T2>> {
  return ScalarMul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
auto
mul(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, ScalarMultiplication>{} &&
              HasProperty<T2, ScalarMultiplication>{} &&
              std::is_same<T1, T2>{},
              const ScalarMul<T1, T2>> {
  return ScalarMul<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*=(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, ScalarMultiplication>{} &&
              HasProperty<T2, ScalarMultiplication>{} &&
              std::is_same<T1, T2>{},
              T1&> {
  assign_scalar_mul_(lhs, rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_OPERATIONS_SCALAR_MULTIPLICATION_HPP
