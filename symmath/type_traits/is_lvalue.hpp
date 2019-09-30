#ifndef SYMMATH_TYPE_TRAITS_IS_LVALUE_HPP
#define SYMMATH_TYPE_TRAITS_IS_LVALUE_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsLValue
  : FalseType {};

template< typename T >
struct IsLValue<T&>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_LVALUE_HPP
