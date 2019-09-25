#ifndef SYMMATH_TYPE_TRAITS_IS_FIELD_HPP
#define SYMMATH_TYPE_TRAITS_IS_FIELD_HPP

#include <symmath/properties/addition.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/closure_property.hpp>
#include <symmath/properties/commutative_property.hpp>
#include <symmath/properties/identity_element.hpp>
#include <symmath/properties/inverse_element.hpp>
#include <symmath/properties/multiplication.hpp>
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
constexpr bool IsAssociative =
  All<HasProperty<T, AssociativeProperty<Addition>>...>{};

template< typename ...T >
constexpr bool IsClosedUnderAddition =
  All<HasProperty<T, closure_property<Addition>>...>{};

// template< typename ...T >
// constexpr bool HasProperty<T, commutative_property<Addition>>{}
// template< typename ...T >
// constexpr bool HasProperty<T, identity_element<Addition>>{}
// template< typename ...T >
// constexpr bool HasProperty<T, inverse_element<Addition>>{}

template< typename ...T >
constexpr bool HasMultiplication = All<HasProperty<T, Multiplication>...>{};

// template< typename ...T >
// constexpr bool HasProperty<T, associative_property<Multiplication>>{}
// template< typename ...T >
// constexpr bool HasProperty<T, closure_property<Multiplication>>{}
// template< typename ...T >
// constexpr bool HasProperty<T, commutative_property<Multiplication>>{}
// template< typename ...T >
// constexpr bool HasProperty<T, identity_element<Multiplication>>{}
// template< typename ...T >
// constexpr bool HasProperty<T, inverse_element<Multiplication>>{}

} // detail

// -----------------------------------------------------------------------------

template< typename ...T >
constexpr bool IsField = Requires(
  HasAddition<T...> &&
  IsAssociative<T...> &&
  IsClosedUnderAddition<T...> &&
  HasMultiplication<T...>
);

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_FIELD_HPP
