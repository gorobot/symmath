#ifndef SYMMATH_TYPE_TRAITS_IS_STORAGE_OBJECT_HPP
#define SYMMATH_TYPE_TRAITS_IS_STORAGE_OBJECT_HPP

#include <type_traits>

#include "../matrix/storage.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_storage_object_helper {
private:

  template< typename U >
  static std::true_type test(Storage<U> &);

  template< typename U >
  static std::true_type test(const Storage<U> &);

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T >
struct is_storage_object
  : is_storage_object_helper<T>::type {};

template< typename T >
using is_storage_object_t = typename is_storage_object_helper<T>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_IS_STORAGE_OBJECT_HPP
