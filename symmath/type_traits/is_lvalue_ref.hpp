#ifndef SYMMATH_TYPE_TRAITS_IS_LVALUE_REF_HPP
#define SYMMATH_TYPE_TRAITS_IS_LVALUE_REF_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsLValueRef
  : FalseType {};

template< typename T >
struct IsLValueRef<T&>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_LVALUE_REF_HPP
