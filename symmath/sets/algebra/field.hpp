#ifndef SYMMATH_SETS_ALGEBRA_FIELD_HPP
#define SYMMATH_SETS_ALGEBRA_FIELD_HPP

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
struct Field {};

// -----------------------------------------------------------------------------

template< typename T >
struct HasProperty<Field<T>, Addition>
  : TrueType {};

template< typename T >
struct HasProperty<Field<T>, AssociativeProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Field<T>, ClosureProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Field<T>, CommutativeProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Field<T>, DistributiveProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Field<T>, IdentityElement<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Field<T>, InverseElement<Addition>>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_ALGEBRA_FIELD_HPP
