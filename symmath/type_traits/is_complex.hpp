#ifndef SYMMATH_TYPE_TRAITS_IS_COMPLEX_HPP
#define SYMMATH_TYPE_TRAITS_IS_COMPLEX_HPP

#include <complex>

#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct IsComplex
  : FalseType {};

template< typename T >
struct IsComplex<std::complex<T>>
  : TrueType {};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_COMPLEX_HPP
