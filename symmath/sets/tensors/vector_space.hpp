#ifndef SYMMATH_SETS_NUMERICS_VECTOR_SPACE_HPP
#define SYMMATH_SETS_NUMERICS_VECTOR_SPACE_HPP

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
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class VectorSpace
  : private Set {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<VectorSpace, Addition>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, AssociativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, ClosureProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, CommutativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, DistributiveProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, IdentityElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, InverseElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<VectorSpace, ScalarMultiplication>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_VECTOR_SPACE_HPP
