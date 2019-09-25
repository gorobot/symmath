#ifndef SYMMATH_TYPE_TRAITS_COMMON_RESULT_HPP
#define SYMMATH_TYPE_TRAITS_COMMON_RESULT_HPP

#include <symmath/type_traits/is_same.hpp>
#include <symmath/type_traits/result_type.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          typename = void_t<> >
struct IsSameResult
  : FalseType {};

template< typename T1,
          typename T2 >
struct IsSameResult<T1, T2, void_t<ResultType_t<T1>, ResultType_t<T2>>>
  : IsSame<typename T1::ResultType, typename T2::ResultType>::type {};

template< typename T1,
          typename T2 >
using IsSameResult_t = typename IsSameResult<T1, T2>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_COMMON_RESULT_HPP
