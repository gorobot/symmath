#ifndef SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP
#define SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP

#include <type_traits>

#include "is_integral.hpp"
#include "is_floating_point.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_numeric
  : std::integral_constant<bool,
      is_integral<T>{} ||
      is_floating_point<T>{}> {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP
