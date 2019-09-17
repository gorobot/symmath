#ifndef SYMMATH_TYPE_TRAITS_ENABLE_IF_HPP
#define SYMMATH_TYPE_TRAITS_ENABLE_IF_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< bool C,
          typename T = void >
struct EnableIf {
  using type = T;
};

template< typename T >
struct EnableIf<false, T> {};

template< bool C,
          typename T = void >
using EnableIf_t = typename EnableIf<C, T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_ENABLE_IF_HPP
