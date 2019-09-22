#ifndef SYMMATH_TYPE_TRAITS_IS_RING_HPP
#define SYMMATH_TYPE_TRAITS_IS_RING_HPP

#include <type_traits>

#include "has_property.hpp"
#include "../properties/addition.hpp"
#include "../properties/additive_inverse.hpp"
#include "../properties/associative_property.hpp"
#include "../properties/commutative_property.hpp"
#include "../properties/multiplication.hpp"
#include "../properties/multiplicative_inverse.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_ring
  : std::integral_constant<bool,
    HasProperty<T, addition>{} &&
    HasProperty<T, additive_inverse>{} &&
    HasProperty<T, associative_property<addition>>{} &&
    HasProperty<T, associative_property<multiplication>>{} &&
    HasProperty<T, commutative_property<addition>>{} &&
    HasProperty<T, commutative_property<multiplication>>{} &&
    HasProperty<T, multiplication>{} &&
    HasProperty<T, multiplicative_inverse>{}> {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_RING_HPP
