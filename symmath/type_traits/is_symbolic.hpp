#ifndef SYMMATH_TYPE_TRAITS_IS_SYMBOLIC_HPP
#define SYMMATH_TYPE_TRAITS_IS_SYMBOLIC_HPP

#include <type_traits>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_symbolic_helper {
private:

  template< typename U >
  static std::true_type test(Symbolic<U> &);

  template< typename U >
  static std::true_type test(const Symbolic<U> &);

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T >
struct is_symbolic
  : is_symbolic_helper<T>::type {};

template< typename T >
using is_symbolic_t = typename is_symbolic_helper<T>::type;

// -----------------------------------------------------------------------------

template< typename T,
          typename R = void >
struct enable_if_symbolic
  : std::enable_if<is_symbolic<T>::value, R> {};

template< typename T,
          typename R = void >
using enable_if_symbolic_t = typename enable_if_symbolic<T, R>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_SYMBOLIC_HPP
