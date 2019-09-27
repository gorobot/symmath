#ifndef SYMMATH_PROPERTY_TRAITS_COMPARABLE_HPP
#define SYMMATH_PROPERTY_TRAITS_COMPARABLE_HPP

#include <symmath/properties/partial_order.hpp>
#include <symmath/properties/total_order.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/property_traits/requires.hpp>
#include <symmath/type_traits/boolean_logic.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
constexpr bool HasPartialOrderProperty = HasProperty<T, PartialOrder>{};

template< typename T >
constexpr bool HasTotalOrderProperty = HasProperty<T, TotalOrder>{};

// template< typename T >
// constexpr bool HasOrder = All<HasPartialOrderProperty<T> || HasTotalOrderProperty<T>>{};

} // detail

// -----------------------------------------------------------------------------

template< typename T >
constexpr bool IsComparable = Requires(HasPartialOrderProperty<T>);

template< typename T,
          typename = EnableIf_t<IsComparable<T>> >
using Comparable = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_COMPARABLE_HPP
