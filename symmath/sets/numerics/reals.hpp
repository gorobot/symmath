#ifndef SYMMATH_SETS_NUMERICS_REALS_HPP
#define SYMMATH_SETS_NUMERICS_REALS_HPP

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

class Reals
  : public Set<Reals> {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Reals, Addition>
  : TrueType {};

template<>
struct HasProperty<Reals, AssociativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Reals, ClosureProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Reals, CommutativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Reals, DistributiveProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Reals, IdentityElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<Reals, InverseElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<Reals, Multiplication>
  : TrueType {};

template<>
struct HasProperty<Reals, AssociativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Reals, ClosureProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Reals, CommutativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Reals, DistributiveProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Reals, IdentityElement<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Reals, InverseElement<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Reals, TotalOrder>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_REALS_HPP
