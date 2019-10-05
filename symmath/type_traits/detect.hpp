#ifndef SYMMATH_TYPE_TRAITS_DETECT_HPP
#define SYMMATH_TYPE_TRAITS_DETECT_HPP

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename,
          template<typename...> typename T,
          typename ...Args >
struct detect
  : FalseType {};

template< template<typename...> typename T,
          typename ...Args >
struct detect<void_t<T<Args...>>, T, Args...>
  : TrueType {};

} // detail

// -----------------------------------------------------------------------------

template< template<typename...> typename T,
          typename ...Args >
constexpr bool Detect = detect<void, T, Args...>{};

} // sym

#endif // SYMMATH_TYPE_TRAITS_DETECT_HPP
