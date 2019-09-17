#ifndef SYMMATH_PROPERTIES_HAS_EXPONENTIATION_HPP
#define SYMMATH_PROPERTIES_HAS_EXPONENTIATION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/pow.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct has_exponentiation
  : private Property {

  template< typename U >
  inline void assign_pow(const U &p);

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_pow_(T1 &operand, const T2 &p) {
  operand.assign_pow(p);
}

template< typename T >
template< typename U >
inline void
has_exponentiation<T>::assign_pow(const U &p) {
  static_cast<T&>(*this).assign_pow(p);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline decltype(auto)
operator^(const has_exponentiation<T1> &operand, const T2 &p) {
  return Pow<T1, T2>(static_cast<const T1&>(operand), p);
}

template< typename T1,
          typename T2 >
inline auto
pow(const has_exponentiation<T1> &operand, const T2 &p)
-> const Pow<T1, T2> {
  return Pow<T1, T2>(static_cast<const T1&>(operand), p);
}

template< typename T1,
          typename T2 >
inline auto
operator^=(has_exponentiation<T1> &operand, const T2 &p)
-> has_exponentiation<T1> & {
  assign_pow_(static_cast<T1&>(operand), p);
  return operand;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_EXPONENTIATION_HPP
