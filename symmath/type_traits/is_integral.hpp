#ifndef SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP
#define SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsIntegral
  : FalseType {};

template<>
struct IsIntegral<short>
  : TrueType {};

template<>
struct IsIntegral<unsigned short>
  : TrueType {};

template<>
struct IsIntegral<int>
  : TrueType {};

template<>
struct IsIntegral<unsigned int>
  : TrueType {};

template<>
struct IsIntegral<long>
  : TrueType {};

template<>
struct IsIntegral<unsigned long>
  : TrueType {};

template<>
struct IsIntegral<long long>
  : TrueType {};

template<>
struct IsIntegral<unsigned long long>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_INTEGRAL_HPP
