#ifndef SYMMATH_TYPE_TRAITS_DISABLE_IF_HPP
#define SYMMATH_TYPE_TRAITS_DISABLE_IF_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< bool C,
          typename T = void >
struct DisableIf {
  using type = T;
};

template< typename T >
struct DisableIf<true, T> {};

template< bool C,
          typename T = void >
using DisableIf_t = typename DisableIf<C, T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_DISABLE_IF_HPP
