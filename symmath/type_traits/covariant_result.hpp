#ifndef SYMMATH_TYPE_TRAITS_COVARIANT_RESULT_HPP
#define SYMMATH_TYPE_TRAITS_COVARIANT_RESULT_HPP

#include <type_traits>

#include <symmath/type_traits/covariant_type.hpp>
#include <symmath/type_traits/detect.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
struct CovariantResult
  : CovariantType<ResultType_t<T1>, ResultType_t<T2>>::type {};

template< typename T1,
          typename T2 >
using CovariantResult_t = CovariantType_t<ResultType_t<T1>, ResultType_t<T2>>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_COVARIANT_RESULT_HPP
