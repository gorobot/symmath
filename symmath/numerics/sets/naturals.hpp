#ifndef SYMMATH_NUMERICS_SETS_NATURALS_HPP
#define SYMMATH_NUMERICS_SETS_NATURALS_HPP

#include "../../sets/set.hpp"
#include "../../properties/addition.hpp"
#include "../../properties/associative_property.hpp"
#include "../../properties/commutative_property.hpp"
#include "../../properties/multiplication.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Naturals
  : private Set,
    public addition,
    public associative_property<addition>,
    public associative_property<multiplication>,
    public commutative_property<addition>,
    public commutative_property<multiplication>,
    public multiplication {};

} // sym

#endif // SYMMATH_NUMERICS_SETS_NATURALS_HPP
