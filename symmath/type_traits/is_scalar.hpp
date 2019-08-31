#ifndef SYMMATH_TYPE_TRAITS_IS_SCALAR_HPP
#define SYMMATH_TYPE_TRAITS_IS_SCALAR_HPP

#include <type_traits>

#include "../matrix/scalar.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_scalar_helper {
private:

  template< typename U >
  static std::true_type test(Scalar<U> &);

  template< typename U >
  static std::true_type test(const Scalar<U> &);

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T >
struct is_scalar
  : is_scalar_helper<T>::type {};

template< typename T >
using is_scalar_t = typename is_scalar_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_SCALAR_HPP
