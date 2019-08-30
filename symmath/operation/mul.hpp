#ifndef SYMMATH_OPERATION_MUL_HPP
#define SYMMATH_OPERATION_MUL_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/is_symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Mul
  : public Operation<Symbolic<Mul<T1, T2>>> {
public:

  using LhsType = typename T1::ResultType;
  using RhsType = typename T2::ResultType;

  using ResultType = CommonType_t<LhsType, RhsType>;

  using Lhs = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using Rhs = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  Lhs lhs_;
  Rhs rhs_;

public:

  explicit inline Mul(const T1 &lhs, const T2 &rhs);

  inline auto eval() const -> const ResultType;

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
// Constructor
template< typename T1,
          typename T2 >
inline Mul<T1, T2>::Mul(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto Mul<T1, T2>::eval() const
-> const ResultType {
  ResultType tmp;
  apply_(tmp, *this);
  return tmp;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator*(const Symbolic<T1> &lhs, const Symbolic<T2> &rhs)
-> const Mul<T1, T2> {
  return Mul<T1, T2>(lhs.derived(), rhs.derived());
}

} // sym

#endif // SYMMATH_OPERATION_MUL_HPP
