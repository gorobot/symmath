#ifndef SYMMATH_PROPERTY_TRAITS_INVERTIBLE_HPP
#define SYMMATH_PROPERTY_TRAITS_INVERTIBLE_HPP

#include <symmath/properties/multiplication.hpp>
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
constexpr bool HasMultiplication = All<HasProperty<T, Multiplication>...>{};

template< typename ...T >
constexpr bool HasMultiplicativeInverse =
  All<HasProperty<T, InverseElement<Multiplication>>...>{};

} // detail

// -----------------------------------------------------------------------------

template< typename ...T >
constexpr bool IsInvertible =
  Requires(HasMultiplication<T...> && HasMultiplicativeInverse<T...>);

template< typename T,
          typename = EnableIf_t<IsInvertible<T>> >
using Invertible = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_INVERTIBLE_HPP
