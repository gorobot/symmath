#ifndef SYMMATH_SETS_FINITE_SET_HPP
#define SYMMATH_SETS_FINITE_SET_HPP

#include <algorithm>
#include <vector>

#include <symmath/sets/set.hpp>
#include <symmath/properties/countable.hpp>
#include <symmath/property_traits/has_property.hpp>
#include <symmath/type_traits/nested_initializer_list.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class FiniteSet
  : public Set<FiniteSet<T>> {
public:

  using This = FiniteSet<T>;

private:

  std::vector<T> value_;

public:

  // Constructor
  explicit inline FiniteSet();
  inline FiniteSet(NestedInitializerList_t<T, 1> list);

  // Assignment Operator
  inline This &operator=(NestedInitializerList_t<T, 1> list);

  // Iterable

  // Assign
                          inline void assign(const FiniteSet &rhs);
  template< typename U >  inline void assign(const Set<U> &rhs);

  // Assign Union
                          inline void assign_union(const FiniteSet &rhs);
  template< typename U >  inline void assign_union(const Set<U> &rhs);

  // Assign Intersection
                          inline void assign_intersection(const FiniteSet &rhs);
  template< typename U >  inline void assign_intersection(const Set<U> &rhs);

  // Assign Difference
                          inline void assign_difference(const FiniteSet &rhs);
  template< typename U >  inline void assign_difference(const Set<U> &rhs);

  // Assign Complement
                          inline void assign_complement(const FiniteSet &rhs);
  template< typename U >  inline void assign_complement(const Set<U> &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline FiniteSet<T>::FiniteSet()
  : value_() {}

template< typename T >
inline FiniteSet<T>::FiniteSet(NestedInitializerList_t<T, 1> list)
  : value_(list) {
  // value_.insert(list.begin(), list.end(), 0);
}

// -----------------------------------------------------------------------------
// Assignment Operator
template< typename T >
inline FiniteSet<T> &FiniteSet<T>::operator=(NestedInitializerList_t<T, 1> list) {
  // std::copy(list.begin(), list.end(), value_.begin());
}

// -----------------------------------------------------------------------------
// Set Property Specializations
template< typename T >
struct HasProperty<T, Countable>
  : TrueType {};

} // sym

#endif // SYMMATH_SETS_FINITE_SET_HPP
