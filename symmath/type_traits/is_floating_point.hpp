#ifndef SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP
#define SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsFloatingPoint
  : FalseType {};

template<>
struct IsFloatingPoint<float>
  : TrueType {};

template<>
struct IsFloatingPoint<double>
  : TrueType {};

template<>
struct IsFloatingPoint<long double>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP
