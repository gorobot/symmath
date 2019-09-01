#ifndef SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP
#define SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP

#include <type_traits>

#include "../number/number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_number
  : std::is_base_of<Number, T> {};

template< typename T >
using is_number_t = typename is_number<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP
