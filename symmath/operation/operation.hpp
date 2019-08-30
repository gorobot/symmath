#ifndef SYMMATH_OPERATION_OPERATION_HPP
#define SYMMATH_OPERATION_OPERATION_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Operation
  : public T {};

// -----------------------------------------------------------------------------

template< typename T >
struct ResultType {
  using type = typename T::ResultType;
};

template< typename T >
using ResultType_t = typename ResultType<T>::type;

template< typename ...T >
struct CommonType {
  using type = typename std::common_type<T...>::type;
};

template< typename ...T >
using CommonType_t = typename CommonType<T...>::type;

} // sym

#endif // SYMMATH_OPERATION_OPERATION_HPP
