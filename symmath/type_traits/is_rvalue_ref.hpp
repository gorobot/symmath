#ifndef SYMMATH_TYPE_TRAITS_IS_RVALUE_REF_HPP
#define SYMMATH_TYPE_TRAITS_IS_RVALUE_REF_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsRValueRef
  : FalseType {};

template< typename T >
struct IsRValueRef<T&&>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_RVALUE_REF_HPP
