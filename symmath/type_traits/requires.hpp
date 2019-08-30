#ifndef SYMMATH_TYPE_TRAITS_REQUIRES_HPP
#define SYMMATH_TYPE_TRAITS_REQUIRES_HPP

#include <type_traits>

#include "conjunction.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename R,
          typename U,
          template <typename> class ... T >
using requires = std::enable_if_t<conjunction<T<U>...>::value, R>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_REQUIRES_HPP
