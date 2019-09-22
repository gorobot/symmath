#ifndef SYMMATH_TYPE_TRAITS_HAS_HPP
#define SYMMATH_TYPE_TRAITS_HAS_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename V >
struct HasProperty_helper {
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
  test(U &)
  -> EnableIf_t<std::is_base_of<V, U>{}, std::true_type >;

  template< typename U >
  static auto
  test(const U &)
  -> EnableIf_t<std::is_base_of<V, U>{}, std::true_type >;

  template< typename U >
  static auto
  test(U &)
  -> EnableIf_t<std::is_base_of<V, typename U::ResultType>{}, std::true_type >;

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
struct HasProperty
  : HasProperty_helper<T, V>::type {};

template< typename T,
          typename V >
using HasProperty_t = typename HasProperty_helper<T, V>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_HAS_HPP
