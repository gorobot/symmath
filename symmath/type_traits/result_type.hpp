#ifndef SYMMATH_TYPE_TRAITS_RESULT_TYPE_HPP
#define SYMMATH_TYPE_TRAITS_RESULT_TYPE_HPP

#include <type_traits>

#include "void_t.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename = void_t<> >
struct result_type {
  using type = T;
};

template< typename T >
struct result_type<T, void_t<typename T::ResultType>> {
  using type = typename T::ResultType;
};

template< typename T >
using result_type_t = typename result_type<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_RESULT_TYPE_HPP
