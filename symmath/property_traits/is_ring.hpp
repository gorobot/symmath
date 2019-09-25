#ifndef SYMMATH_TYPE_TRAITS_IS_RING_HPP
#define SYMMATH_TYPE_TRAITS_IS_RING_HPP

#include <type_traits>

#include <symmath/property_traits/has_property.hpp>
#include <symmath/properties/addition.hpp>
#include <symmath/properties/additive_inverse.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/commutative_property.hpp>
#include <symmath/properties/multiplication.hpp>
#include <symmath/properties/multiplicative_inverse.hpp>

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
