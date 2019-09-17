#ifndef SYMMATH_TYPE_TRAITS_IS_ELEMENT_OF_HPP
#define SYMMATH_TYPE_TRAITS_IS_ELEMENT_OF_HPP

#include <type_traits>

#include "../sets/element_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename S,
          typename T >
struct is_element_of
  : std::is_base_of<ElementOf<S>, T> {};

template< typename S,
          typename T >
using is_element_of_t = typename is_element_of<S, T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_ELEMENT_OF_HPP
