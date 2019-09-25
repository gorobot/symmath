#ifndef SYMMATH_TYPE_TRAITS_IS_ELEMENT_HPP
#define SYMMATH_TYPE_TRAITS_IS_ELEMENT_HPP

#include <type_traits>

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename S,
          typename T,
          typename = void_t<> >
using IsElement = FalseType;

// template< typename S,
//           typename T >
// using IsElement = Bool<std::is_base_of<ElementOf, T>>{};

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_ELEMENT_HPP
