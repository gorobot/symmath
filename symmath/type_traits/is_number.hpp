#ifndef SYMMATH_TYPE_TRAITS_IS_NUMBER_HPP
#define SYMMATH_TYPE_TRAITS_IS_NUMBER_HPP

#include <symmath/numerics/number.hpp>
#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
struct IsNumber_helper {
private:

  template< typename U >
  static TrueType test(Number<U> &);

  template< typename U >
  static TrueType test(const Number<U> &);

  static FalseType test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

} // detail

// -----------------------------------------------------------------------------

template< typename T >
struct IsNumber
  : IsNumber_helper<T>::type {};

template< typename T >
using IsNumber_t = typename IsNumber_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_NUMBER_HPP
