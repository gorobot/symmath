#ifndef SYMMATH_TYPE_TRAITS_IS_ABELIAN_GROUP_HPP
#define SYMMATH_TYPE_TRAITS_IS_ABELIAN_GROUP_HPP

#include <type_traits>

#include "has_property.hpp"
#include "../properties/associative_property.hpp"
#include "../properties/closure_property.hpp"
#include "../properties/commutative_property.hpp"
#include "../properties/identity_element.hpp"
#include "../properties/inverse_element.hpp"

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
