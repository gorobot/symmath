#ifndef SYMMATH_SETS_NUMERICS_INTEGERS_HPP
#define SYMMATH_SETS_NUMERICS_INTEGERS_HPP

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

class Integers
  : private Set {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Integers, Addition>
  : TrueType {};

template<>
struct HasProperty<Integers, AssociativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Integers, ClosureProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Integers, CommutativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Integers, DistributiveProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Integers, IdentityElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<Integers, InverseElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<Integers, Multiplication>
  : TrueType {};

template<>
struct HasProperty<Integers, AssociativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Integers, ClosureProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Integers, CommutativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Integers, DistributiveProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Integers, IdentityElement<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Integers, TotalOrder>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_INTEGERS_HPP
