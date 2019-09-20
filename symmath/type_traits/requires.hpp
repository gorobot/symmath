#ifndef SYMMATH_TYPE_TRAITS_REQUIRES_HPP
#define SYMMATH_TYPE_TRAITS_REQUIRES_HPP

#include <type_traits>

#include "conjunction.hpp"
#include "../type_traits/enable_if.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename R,
          typename U,
          template <typename> class ... T >
using requires = EnableIf_t<conjunction<T<U>...>::value, R>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_REQUIRES_HPP
