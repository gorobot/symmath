#ifndef SYMMATH_TYPE_TRAITS_IS_ABELIAN_GROUP_HPP
#define SYMMATH_TYPE_TRAITS_IS_ABELIAN_GROUP_HPP

#include <type_traits>

#include <symmath/property_traits/has_property.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/closure_property.hpp>
#include <symmath/properties/commutative_property.hpp>
#include <symmath/properties/identity_element.hpp>
#include <symmath/properties/inverse_element.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename V >
struct is_abelian_group
  : std::integral_constant<bool,
    HasProperty<T, V>{} &&
    HasProperty<T, associative_property<V>>{} &&
    HasProperty<T, closure_property<V>>{} &&
    HasProperty<T, commutative_property<V>>{} &&
    HasProperty<T, identity_element<V>>{} &&
    HasProperty<T, inverse_element<V>>{}> {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_ABELIAN_GROUP_HPP
