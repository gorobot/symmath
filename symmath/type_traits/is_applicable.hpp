#ifndef SYMMATH_TYPE_TRAITS_IS_APPLICABLE_HPP
#define SYMMATH_TYPE_TRAITS_IS_APPLICABLE_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
using is_applicable = std::is_convertible< typename T2::ResultType,
                                           typename T1::ResultType >;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_APPLICABLE_HPP
