#ifndef SYMMATH_TYPE_TRAITS_CONJUNCTION_HPP
#define SYMMATH_TYPE_TRAITS_CONJUNCTION_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< bool... >
struct bool_pack {};

template< typename... T >
using conjunction = std::is_same< bool_pack<true, T::value...>,
                                  bool_pack<T::value..., true> >;

} // sym

#endif // SYMMATH_TYPE_TRAITS_CONJUNCTION_HPP
