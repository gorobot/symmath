#ifndef SYMMATH_TYPE_TRAITS_NESTED_INITIALIZER_HPP
#define SYMMATH_TYPE_TRAITS_NESTED_INITIALIZER_HPP

#include <initializer_list>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t D >
struct NestedInitializerList;

template< typename T,
          size_t D >
using NestedInitializerList_t = typename NestedInitializerList<T, D>::type;

template< typename T,
          size_t D >
struct NestedInitializerList {
  using type = std::initializer_list<NestedInitializerList_t<T, D-1>>;
};

template< typename T >
struct NestedInitializerList<T, 0> {
  using type = T;
};

} // sym

#endif // SYMMATH_TYPE_TRAITS_NESTED_INITIALIZER_HPP
