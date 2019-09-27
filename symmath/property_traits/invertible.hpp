#ifndef SYMMATH_PROPERTY_TRAITS_INVERTIBLE_HPP
#define SYMMATH_PROPERTY_TRAITS_INVERTIBLE_HPP

#include <symmath/properties/multiplication.hpp>
#include <symmath/properties/inverse_element.hpp>
#include <symmath/property_traits/multipliable.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/property_traits/requires.hpp>
#include <symmath/type_traits/boolean_logic.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
constexpr bool HasMultiplicativeInverseProperty =
  All<HasProperty<T, InverseElement<Multiplication>>>{};

} // detail

// -----------------------------------------------------------------------------

template< typename T >
constexpr bool IsInvertible =
  Requires(IsMultipliable<T> && HasMultiplicativeInverseProperty<T>);

template< typename T,
          typename = EnableIf_t<IsInvertible<T>> >
using Invertible = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_INVERTIBLE_HPP
