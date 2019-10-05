#ifndef SYMMATH_TYPE_TRAITS_ADD_CONST_REF_HPP
#define SYMMATH_TYPE_TRAITS_ADD_CONST_REF_HPP

#include <symmath/type_traits/remove_ref.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct AddConstRef {
  using type = const RemoveRef_t<T>&;
};

template< typename T >
using AddConstRef_t = typename AddConstRef<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_ADD_CONST_REF_HPP
