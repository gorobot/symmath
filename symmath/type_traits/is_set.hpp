#ifndef SYMMATH_TYPE_TRAITS_IS_SET_HPP
#define SYMMATH_TYPE_TRAITS_IS_SET_HPP

#include <type_traits>

#include "../sets/set.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_set
  : std::is_base_of<Set, T> {};

template< typename T >
using is_set_t = typename is_set<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_SET_HPP
