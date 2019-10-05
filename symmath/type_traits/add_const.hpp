#ifndef SYMMATH_TYPE_TRAITS_ADD_CONST_HPP
#define SYMMATH_TYPE_TRAITS_ADD_CONST_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct AddConst {
  using type = const T;
};

template< typename T >
using AddConst_t = typename AddConst<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_ADD_CONST_HPP
