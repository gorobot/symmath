#ifndef SYMMATH_TYPE_TRAITS_IS_SAME_HPP
#define SYMMATH_TYPE_TRAITS_IS_SAME_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
struct IsSame
  : FalseType {};

template< typename T >
struct IsSame<T, T>
  : TrueType {};

template< typename T1,
          typename T2 >
inline constexpr bool IsSame_v = IsSame<T1, T2>::value;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_SAME_HPP
