#ifndef SYMMATH_TYPE_TRAITS_PRODUCT_HPP
#define SYMMATH_TYPE_TRAITS_PRODUCT_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< size_t ...T >
struct product {
  static constexpr size_t value = 1;
};

template< size_t V, size_t ...T >
struct product<V, T...> {
  static constexpr size_t value = V * product<T...>::value;
};

} // sym

#endif // SYMMATH_TYPE_TRAITS_PRODUCT_HPP
