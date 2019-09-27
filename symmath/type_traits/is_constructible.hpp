#ifndef SYMMATH_TYPE_TRAITS_IS_CONSTRUCTIBLE_HPP
#define SYMMATH_TYPE_TRAITS_IS_CONSTRUCTIBLE_HPP

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename,
          typename T,
          typename ...Args >
struct constructible
  : FalseType {};

template< typename T,
          typename ...Args >
struct constructible<void_t<decltype(T(std::declval<Args>()...))>, T, Args...>
  : TrueType {};

} // detail

// -----------------------------------------------------------------------------

template< typename T,
          typename ...Args >
constexpr bool IsConstructible = constructible<void, T, Args...>{};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_CONSTRUCTIBLE_HPP
