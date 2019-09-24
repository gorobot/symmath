#ifndef SYMMATH_TYPE_TRAITS_BOOLEAN_LOGIC_HPP
#define SYMMATH_TYPE_TRAITS_BOOLEAN_LOGIC_HPP

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/is_same.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< bool... >
struct Pack {};

} // detail

// -----------------------------------------------------------------------------

template< typename... T >
using And = Bool<IsSame<Pack<true, T::value...>, Pack<T::value..., true>>{}>;

// -----------------------------------------------------------------------------

template< typename... T >
using Or = Bool<!IsSame<Pack<false, T::value...>, Pack<T::value..., false>>{}>;

// -----------------------------------------------------------------------------

template< typename T >
using Not = Bool<!T{}>;

// -----------------------------------------------------------------------------

template< typename... T >
using All = And<T...>;

// -----------------------------------------------------------------------------

template< typename... T >
using Any = Or<T...>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_BOOLEAN_LOGIC_HPP
