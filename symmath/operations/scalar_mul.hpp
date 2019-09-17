#ifndef SYMMATH_OPERATIONS_SCALAR_MUL_HPP
#define SYMMATH_OPERATIONS_SCALAR_MUL_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "binary_operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/is_scalar.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class ScalarMul
  : private BinaryOperation {
public:

  using LhsResultType = typename T1::ResultType;
  using RhsResultType = typename T2::ResultType;

  // using ResultType = std::common_type_t<LhsResultType, RhsResultType>;
  // using ResultType = std::conditional_t<is_scalar<LhsResultType>{}, RhsResultType, LhsResultType>;
  using ResultType = LhsResultType;

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline ScalarMul(const T1 &lhs, const T2 &rhs);

  inline auto eval() const -> const ResultType;

  inline auto operator[](const size_t pos) -> ResultType;
  inline auto operator[](const size_t pos) const -> const ResultType;

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const ScalarMul<T1, T2> &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_mul_(lhs.derived(), rhs.rhs_);
  }

  // template< typename U >
  // friend inline auto
  // apply_(U &lhs, const ScalarMul<T1, T2> &rhs)
  // -> std::enable_if_t<is_symbolic<U>{}> {
  //   apply_(lhs.derived(), rhs.lhs_);
  //   apply_mul_(lhs.derived(), rhs.rhs_);
  // }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline ScalarMul<T1, T2>::ScalarMul(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto ScalarMul<T1, T2>::eval() const
-> const ResultType {
  ResultType tmp;
  apply_(tmp, *this);
  return tmp;
}

template< typename T1,
          typename T2 >
inline auto ScalarMul<T1, T2>::operator[](const size_t pos)
-> ResultType {
  return lhs_[pos] * rhs_[pos];
}

template< typename T1,
          typename T2 >
inline auto ScalarMul<T1, T2>::operator[](const size_t pos) const
-> const ResultType {
  return lhs_[pos] * rhs_[pos];
}

} // sym

#endif // SYMMATH_OPERATIONS_SCALAR_MUL_HPP
