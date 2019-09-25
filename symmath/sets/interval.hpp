#ifndef SYMMATH_SETS_INTERVAL_HPP
#define SYMMATH_SETS_INTERVAL_HPP

#include <symmath/sets/set.hpp>
#include <symmath/properties/partial_order.hpp>
#include <symmath/property_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Interval
  : public Set<Interval<T>> {
public:

private:

public:

};

// -----------------------------------------------------------------------------
// Set Property Specializations
template<>
struct HasProperty<Interval, PartialOrder>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_INTERVAL_HPP
