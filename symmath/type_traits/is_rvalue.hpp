#ifndef SYMMATH_TYPE_TRAITS_IS_RVALUE_HPP
#define SYMMATH_TYPE_TRAITS_IS_RVALUE_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsRValue
  : FalseType {};

template< typename T >
struct IsRValue<T&>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_RVALUE_HPP
