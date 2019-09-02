#ifndef SYMMATH_TYPE_TRAITS_RESULT_OF_HPP
#define SYMMATH_TYPE_TRAITS_RESULT_OF_HPP

#include <type_traits>

#include "void_t.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename = void_t<> >
struct result_of {

  static inline decltype(auto) value(const T &m) {
    return m;
  }

};

template< typename T >
using use_value = decltype(std::declval<T>().value());

template< typename T >
struct result_of<T, void_t<use_value<T>>> {

  static inline decltype(auto) value(const T &m) {
    return m.value();
  }

};

template< typename T >
using use_eval = decltype(std::declval<T>().eval());

template< typename T >
struct result_of<T, void_t<use_eval<T>>> {

  static inline decltype(auto) value(const T &m) {
    auto res = m.eval();
    return result_of<decltype(res)>::value(res);
  }

};

} // sym

#endif // SYMMATH_TYPE_TRAITS_RESULT_OF_HPP
