#ifndef SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP
#define SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP

#include <type_traits>

#include "../sets/element_of.hpp"
#include "enable_if.hpp"
#include "void_t.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename V >
struct has_property_helper {
private:

  template< typename U >
  static auto
  test(ElementOf<U> &)
  -> EnableIf_t<std::is_base_of<V, U>{}, std::true_type >;

  template< typename U >
  static auto
  test(const ElementOf<U> &)
  -> EnableIf_t<std::is_base_of<V, U>{}, std::true_type >;

  template< typename U >
  static auto
  test(const U &)
  -> EnableIf_t<std::is_base_of<V, typename U::ResultType>{}, std::true_type >;

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T,
          typename V >
struct has_property
  : has_property_helper<T, V>::type {};

template< typename T,
          typename V >
using has_property_t = typename has_property_helper<T, V>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP
