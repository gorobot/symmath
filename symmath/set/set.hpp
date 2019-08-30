#ifndef SYMMATH_SET_SET_HPP
#define SYMMATH_SET_SET_HPP

#include <type_traits>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Set
  : public Symbolic<Set> {
private:

public:

  template< typename T >
  inline Set &operator=(const Symbolic<T> &rhs);

  bool empty();

  template< typename T1,
            typename T2 >
  inline void apply(const Union<T1, T2> &rhs);

  template< typename T1,
            typename T2 >
  inline void apply(const Intersection<T1, T2> &rhs);

};

// -----------------------------------------------------------------------------

template< typename T >
struct is_set
  : std::false_type {};

template<>
struct is_set<Set>
  : std::true_type {};

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline Set &
Set::operator=(const Symbolic<T> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T1,
          typename T2 >
inline void
Set::apply(const Union<T1, T2> &rhs) {

}

template< typename T1,
          typename T2 >
inline void
Set::apply(const Intersection<T1, T2> &rhs) {

}

} // sym

#endif // SYMMATH_SET_SET_HPP
