#ifndef SYMMATH_TYPE_TRAITS_IS_MONOID_HPP
#define SYMMATH_TYPE_TRAITS_IS_MONOID_HPP

#include <type_traits>

#include <symmath/property_traits/has_property.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/closure_property.hpp>
#include <symmath/properties/identity_element.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_monoid
  : std::integral_constant<bool,
    HasProperty<T, V>{} &&
    HasProperty<T, associative_property<V>>{} &&
    HasProperty<T, closure_property<V>>{} &&
    HasProperty<T, identity_element<V>>{}> {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_MONOID_HPP
