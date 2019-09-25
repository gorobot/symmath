#ifndef SYMMATH_SETS_ALGEBRA_RING_HPP
#define SYMMATH_SETS_ALGEBRA_RING_HPP

#include <type_traits>

#include <symmath/sets/set.hpp>
#include <symmath/properties/addition.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/closure_property.hpp>
#include <symmath/properties/commutative_property.hpp>
#include <symmath/properties/distributive_property.hpp>
#include <symmath/properties/identity_element.hpp>
#include <symmath/properties/inverse_element.hpp>
#include <symmath/properties/multiplication.hpp>
#include <symmath/properties/total_order.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Ring {};

// -----------------------------------------------------------------------------

template< typename T >
struct HasProperty<Ring<T>, Addition>
  : TrueType {};

template< typename T >
struct HasProperty<Ring<T>, AssociativeProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Ring<T>, ClosureProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Ring<T>, CommutativeProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Ring<T>, DistributiveProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Ring<T>, IdentityElement<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Ring<T>, InverseElement<Addition>>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_ALGEBRA_RING_HPP
