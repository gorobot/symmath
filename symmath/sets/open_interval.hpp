#ifndef SYMMATH_SETS_OPEN_INTERVAL_HPP
#define SYMMATH_SETS_OPEN_INTERVAL_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct OpenInterval
  : public T {};

template< typename T >
struct LeftOpenInterval
  : public T {};

template< typename T >
struct RightOpenInterval
  : public T {};

} // sym

#endif // SYMMATH_SETS_OPEN_INTERVAL_HPP
