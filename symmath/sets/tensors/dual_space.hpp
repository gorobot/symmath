#ifndef SYMMATH_SETS_NUMERICS_DUAL_SPACE_HPP
#define SYMMATH_SETS_NUMERICS_DUAL_SPACE_HPP

#include <type_traits>

#include <symmath/sets/set.hpp>
#include <symmath/properties/addition.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/closure_property.hpp>
#include <symmath/properties/commutative_property.hpp>
#include <symmath/properties/distributive_property.hpp>
#include <symmath/properties/identity_element.hpp>
#include <symmath/properties/inverse_element.hpp>
#include <symmath/properties/scalar_multiplication.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class DualSpace
  : private Set {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<DualSpace, Addition>
  : TrueType {};

template<>
struct HasProperty<DualSpace, AssociativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<DualSpace, ClosureProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<DualSpace, CommutativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<DualSpace, DistributiveProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<DualSpace, IdentityElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<DualSpace, InverseElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<DualSpace, ScalarMultiplication>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_DUAL_SPACE_HPP
