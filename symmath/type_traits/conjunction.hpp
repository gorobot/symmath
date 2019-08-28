#ifndef SYMMATH_TYPE_TRAITS_CONJUNCTION_HPP
#define SYMMATH_TYPE_TRAITS_CONJUNCTION_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

// template< typename... >
// struct conjunction
//   : std::true_type {};
//
// template< typename T >
// struct conjunction<T>
//   : T {};
//
// template< typename T,
//           typename ...U >
// struct conjunction<T, U...>
//   : std::conditional_t<bool(T::value), conjunction<U...>, T> {};

template< bool... >
struct bool_pack {};

template< typename... T >
using conjunction = std::is_same< bool_pack<true, T::value...>,
                                  bool_pack<T::value..., true> >;

} // sym

#endif // SYMMATH_TYPE_TRAITS_CONJUNCTION_HPP
