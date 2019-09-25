#ifndef SYMMATH_SETS_ALGEBRA_MODULE_HPP
#define SYMMATH_SETS_ALGEBRA_MODULE_HPP

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
struct Module {};

// -----------------------------------------------------------------------------

template< typename T >
struct HasProperty<Module<T>, Addition>
  : TrueType {};

template< typename T >
struct HasProperty<Module<T>, AssociativeProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Module<T>, ClosureProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Module<T>, CommutativeProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Module<T>, DistributiveProperty<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Module<T>, IdentityElement<Addition>>
  : TrueType {};

template< typename T >
struct HasProperty<Module<T>, InverseElement<Addition>>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_ALGEBRA_MODULE_HPP
