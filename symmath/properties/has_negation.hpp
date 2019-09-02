#ifndef SYMMATH_PROPERTIES_HAS_SUBTRACTION_HPP
#define SYMMATH_PROPERTIES_HAS_SUBTRACTION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operation/neg.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_negation
  : private Property {

  template< typename U >
  inline void assign_neg(const U &operand);

};

// -----------------------------------------------------------------------------

template< typename T1 >
inline void
assign_neg_(const T1 &operand) {
  lhs.assign_neg(operand);
}

template< typename T >
template< typename U >
inline void
has_negation<T>::assign_neg(const U &operand) {
  static_cast<T&>(*this).assign_neg(operand);
}

// -----------------------------------------------------------------------------

template< typename T1 >
inline auto
operator-(const has_negation<T1> &operand)
-> const Neg<T1> {
  return Neg<T1>(static_cast<const T1&>(operand));
}

template< typename T1 >
inline auto
neg(const has_negation<T1> &operand)
-> const Neg<T1> {
  return Neg<T1>(static_cast<const T1&>(operand));
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_SUBTRACTION_HPP
