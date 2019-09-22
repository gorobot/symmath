#ifndef SYMMATH_TYPE_TRAITS_IS_FIELD_HPP
#define SYMMATH_TYPE_TRAITS_IS_FIELD_HPP

#include <type_traits>

#include "has_property.hpp"
#include "../properties/addition.hpp"
#include "../properties/associative_property.hpp"
#include "../properties/closure_property.hpp"
#include "../properties/commutative_property.hpp"
#include "../properties/identity_element.hpp"
#include "../properties/inverse_element.hpp"
#include "../properties/multiplication.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_field
  : std::integral_constant<bool,
    HasProperty<T, addition>{} &&
    HasProperty<T, associative_property<addition>>{} &&
    HasProperty<T, closure_property<addition>>{} &&
    HasProperty<T, commutative_property<addition>>{} &&
    HasProperty<T, identity_element<addition>>{} &&
    HasProperty<T, inverse_element<addition>>{} &&
    HasProperty<T, multiplication>{} &&
    HasProperty<T, associative_property<multiplication>>{} &&
    HasProperty<T, closure_property<multiplication>>{} &&
    HasProperty<T, commutative_property<multiplication>>{} &&
    HasProperty<T, identity_element<multiplication>>{} &&
    HasProperty<T, inverse_element<multiplication>>{}> {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_FIELD_HPP
