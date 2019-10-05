#ifndef SYMMATH_TYPE_TRAITS_TEMPORARY_HPP
#define SYMMATH_TYPE_TRAITS_TEMPORARY_HPP

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Temporary {};

// -----------------------------------------------------------------------------

namespace {

template< typename T >
struct Temporary_helper {
  using type = T;
};

template< typename T >
struct Temporary_helper<Temporary<T>> {
  using type = T;
};

template< typename T >
struct IsTemporary_helper
  : FalseType {};

template< typename T >
struct IsTemporary_helper<Temporary<T>>
  : TrueType {};

} //detail

// -----------------------------------------------------------------------------

template< typename T >
constexpr bool IsTemporary = IsTemporary_helper<T>{};

// -----------------------------------------------------------------------------

template< typename T >
using Temporary_t = typename Temporary_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_TEMPORARY_HPP
