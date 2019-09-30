#ifndef SYMMATH_TYPE_TRAITS_IS_LVALUE_HPP
#define SYMMATH_TYPE_TRAITS_IS_LVALUE_HPP

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/is_basic_number.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/is_rvalue.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
constexpr bool IsTemporary =
  IsBasicNumber<T> || IsOperation<T> || IsRValue<T>{};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_LVALUE_HPP
