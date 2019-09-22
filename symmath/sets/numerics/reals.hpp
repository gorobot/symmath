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
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Reals
  : private Set {
public:
  // using ElementType = Real;
};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Reals, Addition>
  : std::true_type {};

template<>
struct HasProperty<Reals, AssociativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Reals, ClosureProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Reals, CommutativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Reals, DistributiveProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Reals, IdentityElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Reals, InverseElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Reals, Multiplication>
  : std::true_type {};

template<>
struct HasProperty<Reals, AssociativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Reals, ClosureProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Reals, CommutativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Reals, DistributiveProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Reals, IdentityElement<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Reals, InverseElement<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Reals, TotalOrder>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_REALS_HPP
