#ifndef SYMMATH_TYPE_TRAITS_COVARIANT_RESULT_HPP
#define SYMMATH_TYPE_TRAITS_COVARIANT_RESULT_HPP

#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
using CovariantResult_t = Covariant_t<ResultType_t<T1>, ResultType_t<T2>>;

template< typename T1,
          typename T2 >
constexpr bool IsCovariantResult =
  IsCovariant<ResultType_t<T1>, ResultType_t<T2>>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_COVARIANT_RESULT_HPP
