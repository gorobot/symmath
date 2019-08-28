#ifndef SYMMATH_EXPRESSION_EQUALS_HPP
#define SYMMATH_EXPRESSION_EQUALS_HPP

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
equals(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}, bool> {
  return (std::is_same<T1, T2>::value &&
          reinterpret_cast<const void *>(&lhs) ==
          reinterpret_cast<const void *>(&rhs));
}

template< typename T1,
          typename T2 >
inline auto
operator==(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}, bool> {
  return equals(lhs.derived(), rhs.derived());
}

template< typename T1,
          typename T2 >
inline auto
operator!=(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}, bool> {
  return !equals(lhs.derived(), rhs.derived());
}

} // sym

#endif // SYMMATH_EXPRESSION_EQUALS_HPP
