#ifndef SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP
#define SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP

#include <type_traits>

#include "../number/number.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_number_helper {
private:

  template< typename U >
  static std::true_type test(Number<U> &);

  template< typename U >
  static std::true_type test(const Number<U> &);

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T >
struct is_number
  : is_number_helper<T>::type {};

template< typename T >
using is_number_t = typename is_number_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_NUMERIC_HPP
