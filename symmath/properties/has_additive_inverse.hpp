#ifndef SYMMATH_PROPERTIES_HAS_ADDITIVE_INVERSE_HPP
#define SYMMATH_PROPERTIES_HAS_ADDITIVE_INVERSE_HPP

#include <type_traits>

#include "property.hpp"
#include "../operation/neg.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_additive_inverse
  : private Property {

  template< typename U >
  inline void assign_neg(const U &operand);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_neg_(T1 &lhs, const T2 &rhs) {
  lhs.assign_neg(rhs);
}

template< typename T >
template< typename U >
inline void
has_additive_inverse<T>::assign_neg(const U &rhs) {
  static_cast<T&>(*this).assign_neg(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
operator-(const has_additive_inverse<T1> &operand)
-> const Neg<T1> {
  return Neg<T1>(static_cast<const T1&>(operand));
}

template< typename T1 >
inline auto
neg(const has_additive_inverse<T1> &operand)
-> const Neg<T1> {
  return Neg<T1>(static_cast<const T1&>(operand));
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ADDITIVE_INVERSE_HPP
