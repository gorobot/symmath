#ifndef SYMMATH_TYPE_TRAITS_IS_SAME_HPP
#define SYMMATH_TYPE_TRAITS_IS_SAME_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
struct IsSame
  : std::false_type {};

template< typename T >
struct IsSame<T, T>
  : std::true_type {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_SAME_HPP
