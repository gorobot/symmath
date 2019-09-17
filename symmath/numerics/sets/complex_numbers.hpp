#ifndef SYMMATH_NUMERICS_SETS_COMPLEX_NUMBERS_HPP
#define SYMMATH_NUMERICS_SETS_COMPLEX_NUMBERS_HPP

#include "../../sets/set.hpp"
#include "../../properties/addition.hpp"
#include "../../properties/additive_inverse.hpp"
#include "../../properties/associative_property.hpp"
#include "../../properties/commutative_property.hpp"
#include "../../properties/multiplication.hpp"
#include "../../properties/multiplicative_inverse.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class ComplexNumbers
  : private Set,
    public addition,
    public additive_inverse,
    public associative_property<addition>,
    public associative_property<multiplication>,
    public commutative_property<addition>,
    public commutative_property<multiplication>,
    public multiplication,
    public multiplicative_inverse {};

} // sym

#endif // SYMMATH_NUMERICS_SETS_COMPLEX_NUMBERS_HPP
