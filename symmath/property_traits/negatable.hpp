#ifndef SYMMATH_PROPERTY_TRAITS_NEGATABLE_HPP
#define SYMMATH_PROPERTY_TRAITS_NEGATABLE_HPP

#include <symmath/properties/addition.hpp>
#include <symmath/properties/identity_element.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/property_traits/requires.hpp>
#include <symmath/type_traits/boolean_logic.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename ...T >
constexpr bool HasAddition = All<HasProperty<T, Addition>...>{};

template< typename ...T >
constexpr bool HasAdditiveInverse =
  All<HasProperty<T, InverseElement<Addition>>...>{};

} // detail

// -----------------------------------------------------------------------------

template< typename ...T >
constexpr bool IsNegatable =
  Requires(HasAddition<T...> && HasAdditiveInverse<T...>);

template< typename T,
          typename = EnableIf_t<IsNegatable<T>> >
using Negatable = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_NEGATABLE_HPP
