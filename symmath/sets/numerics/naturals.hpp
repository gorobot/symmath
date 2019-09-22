#ifndef SYMMATH_SETS_NUMERICS_NATURALS_HPP
#define SYMMATH_SETS_NUMERICS_NATURALS_HPP

#include <type_traits>

#include <symmath/sets/set.hpp>
#include <symmath/properties/addition.hpp>
#include <symmath/properties/associative_property.hpp>
#include <symmath/properties/closure_property.hpp>
#include <symmath/properties/commutative_property.hpp>
#include <symmath/properties/distributive_property.hpp>
#include <symmath/properties/multiplication.hpp>
#include <symmath/properties/total_order.hpp>
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Naturals
  : private Set {
public:
  // using ElementType = Natural;
};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Naturals, Addition>
  : std::true_type {};

template<>
struct HasProperty<Naturals, AssociativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, ClosureProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, CommutativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, DistributiveProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, Multiplication>
  : std::true_type {};

template<>
struct HasProperty<Naturals, AssociativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, ClosureProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, CommutativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, DistributiveProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<Naturals, TotalOrder>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_NATURALS_HPP
