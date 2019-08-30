#ifndef SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
#define SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP

#include <type_traits>

#include "../operation/operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_operation_helper {
private:

  template< typename U >
  static std::true_type test(Operation<U> &);

  template< typename U >
  static std::true_type test(const Operation<U> &);

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T >
struct is_operation
  : is_operation_helper<T>::type {};

template< typename T >
using is_operation_t = typename is_operation_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_OPERATION_HPP
