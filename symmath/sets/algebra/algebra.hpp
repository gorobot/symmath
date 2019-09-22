#ifndef SYMMATH_SETS_ALGEBRA_ALGEBRA_HPP
#define SYMMATH_SETS_ALGEBRA_ALGEBRA_HPP

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
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Algebra {};

// -----------------------------------------------------------------------------

template< typename T >
struct HasProperty<Algebra<T>, Addition>
  : std::true_type {};

template< typename T >
struct HasProperty<Algebra<T>, AssociativeProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Algebra<T>, ClosureProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Algebra<T>, CommutativeProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Algebra<T>, DistributiveProperty<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Algebra<T>, IdentityElement<Addition>>
  : std::true_type {};

template< typename T >
struct HasProperty<Algebra<T>, InverseElement<Addition>>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_ALGEBRA_ALGEBRA_HPP
