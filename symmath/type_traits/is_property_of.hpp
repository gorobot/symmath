#ifndef SYMMATH_TYPE_TRAITS_IS_PROPERTY_OF_HPP
#define SYMMATH_TYPE_TRAITS_IS_PROPERTY_OF_HPP

#include <type_traits>

#include "../properties/property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

// template< typename T >
// struct is_property
//   : std::is_base_of<Property, T> {};
//
// template< typename T >
// using is_property_t = typename is_property<T>::type;

template< template<typename> class P,
          typename T >
struct is_property_of
  : std::is_base_of<P<T>, T> {};

// template< typename T >
// using is_property_of_t = typename is_property_of<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_PROPERTY_OF_HPP
