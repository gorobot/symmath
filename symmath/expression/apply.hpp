#ifndef SYMMATH_EXPRESSION_APPLY_HPP
#define SYMMATH_EXPRESSION_APPLY_HPP

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
auto
apply_(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}> {
  lhs.derived().apply(rhs.derived());
}

template< typename T1,
          typename T2 >
auto
apply_add_(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}> {
  lhs.derived().apply_add(rhs.derived());
}

template< typename T1,
          typename T2 >
auto
apply_div_(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}> {
  lhs.derived().apply_div(rhs.derived());
}

template< typename T1,
          typename T2 >
auto
apply_mul_(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}> {
  lhs.derived().apply_mul(rhs.derived());
}

template< typename T1,
          typename T2 >
auto
apply_sub_(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}> {
  lhs.derived().apply_sub(rhs.derived());
}

} // sym

#endif // SYMMATH_EXPRESSION_APPLY_HPP
