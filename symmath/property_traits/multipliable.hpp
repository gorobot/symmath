#ifndef SYMMATH_PROPERTY_TRAITS_MULTIPLIABLE_HPP
#define SYMMATH_PROPERTY_TRAITS_MULTIPLIABLE_HPP

#include <symmath/property/multiplication.hpp>
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

} // detail

// -----------------------------------------------------------------------------

template< typename ...T >
constexpr bool IsMultipliable = Requires(HasMultiplication<T...>);

template< typename T,
          typename = EnableIf_t<IsMultipliable<T>> >
using Multipliable = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_MULTIPLIABLE_HPP
