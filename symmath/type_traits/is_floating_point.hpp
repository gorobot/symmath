#ifndef SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP
#define SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsFloatingPoint
  : std::false_type {};

template<>
struct IsFloatingPoint<float>
  : std::true_type {};

template<>
struct IsFloatingPoint<double>
  : std::true_type {};

template<>
struct IsFloatingPoint<long double>
  : std::true_type {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP
