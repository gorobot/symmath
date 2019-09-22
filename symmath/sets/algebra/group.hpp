#ifndef SYMMATH_SETS_ALGEBRA_GROUP_HPP
#define SYMMATH_SETS_ALGEBRA_GROUP_HPP

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

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Group {};

// -----------------------------------------------------------------------------

template< typename T >
struct HasProperty<Group<T>, Addition>
  : std::true_type {};

template< typename T >
struct HasProperty<Group<T>, AssociativeProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Group<T>, ClosureProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Group<T>, CommutativeProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Group<T>, DistributiveProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Group<T>, IdentityElement<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Group<T>, InverseElement<Addition>>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_ALGEBRA_GROUP_HPP
