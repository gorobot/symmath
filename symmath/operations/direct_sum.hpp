#ifndef SYMMATH_OPERATIONS_DIRECT_SUM_HPP
#define SYMMATH_OPERATIONS_DIRECT_SUM_HPP

#include <type_traits>

#include <symmath/operations/dsum.hpp>
#include <symmath/properties/direct_sum.hpp>
#include <symmath/property_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_dsum_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, DirectSum>{} &&
              HasProperty<T2, DirectSum>{} &&
              std::is_same<T1, T2>{}> {
  lhs.assign_dsum(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
auto
operator*(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, DirectSum>{} &&
              HasProperty<T2, DirectSum>{} &&
              std::is_same<T1, T2>{},
              const DSum<T1, T2>> {
  return DSum<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
auto
mul(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, DirectSum>{} &&
              HasProperty<T2, DirectSum>{} &&
              std::is_same<T1, T2>{},
              const DSum<T1, T2>> {
  return DSum<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*=(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, DirectSum>{} &&
              HasProperty<T2, DirectSum>{} &&
              std::is_same<T1, T2>{},
              T1&> {
  assign_dsum_(lhs, rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_OPERATIONS_DIRECT_SUM_HPP
