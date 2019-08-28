#ifndef SYMMATH_OPERATION_SUB_HPP
#define SYMMATH_OPERATION_SUB_HPP

#include <type_traits>

#include "operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Sub
  : public Operation<Symbolic<Sub<T1, T2>>> {
public:

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Sub(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Sub<T1, T2> &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_sub_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline Sub<T1, T2>::Sub(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator-(T1 &lhs, T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}, const Sub<T1, T2>> {
  return Sub<T1, T2>(lhs.derived(), rhs.derived());
}

} // sym

#endif // SYMMATH_OPERATION_SUB_HPP
