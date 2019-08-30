#ifndef SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP
#define SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_floating_point
  : std::false_type {};

template<>
struct is_floating_point<float>
  : std::true_type {};

template<>
struct is_floating_point<double>
  : std::true_type {};

template<>
struct is_floating_point<long double>
  : std::true_type {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_FLOATING_POINT_HPP
