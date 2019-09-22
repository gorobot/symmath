#ifndef SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP
#define SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP

#include <type_traits>

#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_operation.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename P >
struct HasProperty;

template< typename T,
          typename P >
struct HasProperty_helper {
private:

  template< typename U >
  static auto test(U &)
  -> EnableIf_t<HasProperty<typename U::ElementOf, P>{}, std::true_type>;

  template< typename U >
  static auto test(const U &)
  -> EnableIf_t<HasProperty<typename U::ElementOf, P>{}, std::true_type>;

  template< typename U >
  static auto test(U &)
  -> EnableIf_t<IsOperation<U>{} &&
                HasProperty<typename U::ResultType, P>{}, std::true_type>;

  template< typename U >
  static auto test(const U &)
  -> EnableIf_t<IsOperation<U>{} &&
                HasProperty<typename U::ResultType, P>{}, std::true_type>;

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T,
          typename P >
struct HasProperty
  : HasProperty_helper<T, P>::type {};

template< typename T,
          typename P >
using HasProperty_t = typename HasProperty_helper<T, P>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP
