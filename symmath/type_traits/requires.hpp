#ifndef SYMMATH_TYPE_TRAITS_REQUIRES_HPP
#define SYMMATH_TYPE_TRAITS_REQUIRES_HPP

#include "conjunction.hpp"

namespace sym {

// -----------------------------------------------------------------------------

// template< bool B, typename T = void >
// struct enable_if {};
//
// template< typename T >
// struct enable_if<true, T> {
//   typedef T type;
// };
//
// template< bool B, typename T = void >
// using enable_if_t = typename enable_if<B, T>::type;

template< typename R,
          typename U,
          template <typename> class ... T >
using requires = std::enable_if_t<conjunction<T<U>...>::value, R>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_REQUIRES_HPP
