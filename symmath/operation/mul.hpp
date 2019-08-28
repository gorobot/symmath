#ifndef SYMMATH_OPERATION_MUL_HPP
#define SYMMATH_OPERATION_MUL_HPP

#include <type_traits>

#include "operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Mul
  : public Operation<Symbolic<Mul<T1, T2>>> {
public:

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Mul(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Mul<T1, T2> &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_mul_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline Mul<T1, T2>::Mul(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator*(T1 &lhs, T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}, const Mul<T1, T2>> {
  return Mul<T1, T2>(lhs.derived(), rhs.derived());
}

} // sym

#endif // SYMMATH_OPERATION_MUL_HPP
