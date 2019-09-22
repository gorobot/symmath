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

namespace sym {

// -----------------------------------------------------------------------------

class Integers
  : private Set {
public:
  // using ElementType = Integer;
};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Integers, Addition>
  : std::true_type {};

template<>
struct HasProperty<Integers, AssociativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Integers, ClosureProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Integers, CommutativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Integers, DistributiveProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Integers, IdentityElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Integers, InverseElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Integers, Multiplication>
  : std::true_type {};

template<>
struct HasProperty<Integers, AssociativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Integers, ClosureProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Integers, CommutativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Integers, DistributiveProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Integers, IdentityElement<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Integers, TotalOrder>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_INTEGERS_HPP
