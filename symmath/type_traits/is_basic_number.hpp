#ifndef SYMMATH_TYPE_TRAITS_IS_BASIC_NUMBER_HPP
#define SYMMATH_TYPE_TRAITS_IS_BASIC_NUMBER_HPP

#include <symmath/type_traits/is_complex.hpp>
#include <symmath/type_traits/is_integral.hpp>
#include <symmath/type_traits/is_floating_point.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
inline constexpr bool IsBasicNumber =
  IsComplex<T>{} || IsIntegral<T>{} || IsFloatingPoint<T>{};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_BASIC_NUMBER_HPP
