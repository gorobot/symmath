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
#include <symmath/property_traits/has_property.hpp>
#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Naturals
  : public Set<Naturals> {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Naturals, Addition>
  : TrueType {};

template<>
struct HasProperty<Naturals, AssociativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Naturals, ClosureProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Naturals, CommutativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Naturals, DistributiveProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<Naturals, Multiplication>
  : TrueType {};

template<>
struct HasProperty<Naturals, AssociativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Naturals, ClosureProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Naturals, CommutativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Naturals, DistributiveProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<Naturals, TotalOrder>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_NATURALS_HPP
