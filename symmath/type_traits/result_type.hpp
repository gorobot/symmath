#ifndef SYMMATH_TYPE_TRAITS_RESULT_TYPE_HPP
#define SYMMATH_TYPE_TRAITS_RESULT_TYPE_HPP

#include <type_traits>

#include <symmath/type_traits/detect.hpp>
#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
using HasResultTypeTrait = typename T::ResultType;

template< typename T,
          typename = void_t<> >
struct ResultType_helper {
  using type = T;
};

template< typename T >
struct ResultType_helper<T, void_t<typename T::ResultType>> {
  using type = typename T::ResultType;
};

} // detail

// -----------------------------------------------------------------------------

template< typename T >
using ResultType_t = typename ResultType_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_RESULT_TYPE_HPP
