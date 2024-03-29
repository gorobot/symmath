#ifndef SYMMATH_TYPE_TRAITS_IS_SCALAR_HPP
#define SYMMATH_TYPE_TRAITS_IS_SCALAR_HPP

#include <symmath/type_traits/boolean.hpp>
#include <symmath/sets/element_of.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_field.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_scalar_helper {
private:

  template< typename U >
  static auto
  test(ElementOf<U> &)
  -> EnableIf_t<is_field<U>{}, TrueType>;

  template< typename U >
  static auto
  test(const ElementOf<U> &)
  -> EnableIf_t<is_field<U>{}, TrueType>;

  static FalseType test(...);

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
