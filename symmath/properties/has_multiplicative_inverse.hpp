#ifndef SYMMATH_PROPERTIES_HAS_MULTIPLICATIVE_INVERSE_HPP
#define SYMMATH_PROPERTIES_HAS_MULTIPLICATIVE_INVERSE_HPP

#include <type_traits>

#include "property.hpp"
#include "../operation/inv.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_multiplicative_inverse
  : private Property {

  template< typename U >
  inline void assign_inv(const U &operand);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_inv_(T1 &lhs, const T2 &rhs) {
  lhs.assign_inv(rhs);
}

template< typename T >
template< typename U >
inline void
has_multiplicative_inverse<T>::assign_inv(const U &rhs) {
  static_cast<T&>(*this).assign_inv(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
inv(const has_multiplicative_inverse<T1> &operand)
-> const Inv<T1> {
  return Inv<T1>(static_cast<const T1&>(operand));
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_MULTIPLICATIVE_INVERSE_HPP
