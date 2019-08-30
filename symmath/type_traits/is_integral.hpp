#ifndef SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP
#define SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_integral
  : std::false_type {};

template<>
struct is_integral<short>
  : std::true_type {};

template<>
struct is_integral<unsigned short>
  : std::true_type {};

template<>
struct is_integral<int>
  : std::true_type {};

template<>
struct is_integral<unsigned int>
  : std::true_type {};

template<>
struct is_integral<long>
  : std::true_type {};

template<>
struct is_integral<unsigned long>
  : std::true_type {};

template<>
struct is_integral<long long>
  : std::true_type {};

template<>
struct is_integral<unsigned long long>
  : std::true_type {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP
