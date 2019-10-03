#ifndef SYMMATH_TYPE_TRAITS_REMOVE_REF_HPP
#define SYMMATH_TYPE_TRAITS_REMOVE_REF_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct RemoveRef {
  using type = T;
};

template< typename T >
struct RemoveRef<T&> {
  using type = T;
};

template< typename T >
struct RemoveRef<T&&> {
  using type = T;
};

template< typename T >
using RemoveRef_t = typename RemoveRef<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_REMOVE_REF_HPP
