#ifndef SYMMATH_TYPE_TRAITS_IS_SET_HPP
#define SYMMATH_TYPE_TRAITS_IS_SET_HPP

#include <type_traits>

#include <symmath/sets/set.hpp>
#include <symmath/type_traits/boolean.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using IsSet = Bool<std::is_base_of<Set<T>, T>{}>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_SET_HPP
