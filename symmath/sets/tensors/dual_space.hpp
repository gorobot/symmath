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

namespace sym {

// -----------------------------------------------------------------------------

class DualSpace
  : private Set {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<DualSpace, Addition>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, AssociativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, ClosureProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, CommutativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, DistributiveProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, IdentityElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, InverseElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<DualSpace, ScalarMultiplication>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_DUAL_SPACE_HPP
