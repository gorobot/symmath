#ifndef SYMMATH_SETS_EMPTY_SET_HPP
#define SYMMATH_SETS_EMPTY_SET_HPP

#include <symmath/sets/set.hpp>
#include <symmath/sets/subset.hpp>
#include <symmath/sets/superset.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class EmptySet
  : public Set<EmptySet> {
public:

  using This = EmptySet;

  using AbstractType = Set<EmptySet>;
  using ResultType = EmptySet;

};

// -----------------------------------------------------------------------------
// Set Property Specializations
template< typename T >
struct HasProperty<T, Subset<EmptySet>>
  : FalseType {};

template< typename T >
struct HasProperty<T, Subset<EmptySet>>
  : FalseType {};

template< typename T >
struct HasProperty<T, Superset<EmptySet>>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_EMPTY_SET_HPP
