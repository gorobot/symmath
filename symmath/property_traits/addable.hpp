#ifndef SYMMATH_PROPERTY_TRAITS_ADDABLE_HPP
#define SYMMATH_PROPERTY_TRAITS_ADDABLE_HPP

#include <symmath/properties/addition.hpp>
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

} // detail

// -----------------------------------------------------------------------------

template< typename ...T >
constexpr bool IsAddable = Requires(HasAddition<T...>);

template< typename T,
          typename = EnableIf_t<IsAddable<T>> >
using Addable = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_ADDABLE_HPP
