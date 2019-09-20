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
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class ComplexNumbers
  : private Set {
public:
  // using ElementType = Complex;
};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<ComplexNumbers, Addition>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, AssociativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, ClosureProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, CommutativeProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, DistributiveProperty<Addition>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, IdentityElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, InverseElement<Addition>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, Multiplication>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, AssociativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, ClosureProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, CommutativeProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, DistributiveProperty<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, IdentityElement<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, InverseElement<Multiplication>>
  : std::true_type {};

template<>
struct HasProperty<ComplexNumbers, TotalOrder>
  : std::true_type {};

} // sym

#endif // SYMMATH_SETS_NUMERICS_COMPLEX_NUMBERS_HPP
