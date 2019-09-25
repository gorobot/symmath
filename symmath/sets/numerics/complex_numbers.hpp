#ifndef SYMMATH_SETS_NUMERICS_COMPLEX_NUMBERS_HPP
#define SYMMATH_SETS_NUMERICS_COMPLEX_NUMBERS_HPP

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

class ComplexNumbers
  : public Set<ComplexNumbers> {};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<ComplexNumbers, Addition>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, AssociativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, ClosureProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, CommutativeProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, DistributiveProperty<Addition>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, IdentityElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, InverseElement<Addition>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, Multiplication>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, AssociativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, ClosureProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, CommutativeProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, DistributiveProperty<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, IdentityElement<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, InverseElement<Multiplication>>
  : TrueType {};

template<>
struct HasProperty<ComplexNumbers, TotalOrder>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_COMPLEX_NUMBERS_HPP
