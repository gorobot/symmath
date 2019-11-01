#ifndef SYMMATH_TYPE_TRAITS_COVARIANT_HPP
#define SYMMATH_TYPE_TRAITS_COVARIANT_HPP

#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_constructible.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T1,
          typename T2 >
struct covariant {

  template< typename U1,
            typename U2 >
  static auto test(const U1&, const U2&)
  -> EnableIf_t<IsConstructible<U1, U2> && IsConstructible<U2, U1>, U1>;

  template< typename U1,
            typename U2 >
  static auto test(const U1&, const U2&)
  -> EnableIf_t<IsConstructible<U1, U2> && !IsConstructible<U2, U1>, U1>;

  template< typename U1,
            typename U2 >
  static auto test(const U1&, const U2&)
  -> EnableIf_t<!IsConstructible<U1, U2> && IsConstructible<U2, U1>, U2>;

  static void test(...);

  using type = decltype(test(std::declval<T1&>(), std::declval<T2&>()));

};

} // detail

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
struct Covariant
  : covariant<T1, T2>::type {};

template< typename T1,
          typename T2 >
using Covariant_t = typename covariant<T1, T2>::type;

template< typename T1,
          typename T2 >
constexpr bool IsCovariant = IsConstructible<T1, T2> || IsConstructible<T2, T1>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_COVARIANT_HPP
