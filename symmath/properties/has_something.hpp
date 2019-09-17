#ifndef SYMMATH_PROPERTIES_HAS_SOMETHING_HPP
#define SYMMATH_PROPERTIES_HAS_SOMETHING_HPP

#include <iostream>
#include <type_traits>

#include "property.hpp"
#include "../operations/add.hpp"

#include "../sets/element_of.hpp"
#include "../type_traits/is_set_property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class has_something
  : private Property {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_set_property<T1, has_something>{} &&
                    is_set_property<T2, has_something>{}, const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<(is_set_property<T1, has_something>{} ||
                     is_set_property<T2, has_something>{}) &&
                    !std::is_same<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_SOMETHING_HPP
