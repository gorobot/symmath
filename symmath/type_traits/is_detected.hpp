#ifndef SYMMATH_TYPE_TRAITS_IS_DETECTED_HPP
#define SYMMATH_TYPE_TRAITS_IS_DETECTED_HPP

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< template<typename...> class T,
          typename = void_t<>,
          typename ...Args >
struct detector
  : FalseType {};

template< template<typename...> class T,
          typename ...Args >
struct detector<T, void_t<T<Args...>>, Args...>
  : TrueType {};

} // detail

// -----------------------------------------------------------------------------

template< template<typename...> class T,
          typename ...Args >
constexpr bool IsDetected = detector<T, void, Args...>{};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_DETECTED_HPP
