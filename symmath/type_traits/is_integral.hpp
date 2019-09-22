#ifndef SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP
#define SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsIntegral
  : std::false_type {};

template<>
struct IsIntegral<short>
  : std::true_type {};

template<>
struct IsIntegral<unsigned short>
  : std::true_type {};

template<>
struct IsIntegral<int>
  : std::true_type {};

template<>
struct IsIntegral<unsigned int>
  : std::true_type {};

template<>
struct IsIntegral<long>
  : std::true_type {};

template<>
struct IsIntegral<unsigned long>
  : std::true_type {};

template<>
struct IsIntegral<long long>
  : std::true_type {};

template<>
struct IsIntegral<unsigned long long>
  : std::true_type {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP
