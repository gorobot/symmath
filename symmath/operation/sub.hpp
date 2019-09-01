#ifndef SYMMATH_OPERATION_SUB_HPP
#define SYMMATH_OPERATION_SUB_HPP

#include <type_traits>

#include "binary_operation.hpp"
#include "../type_traits/is_operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Sub
  : private BinaryOperation {
public:

  using R1 = result_type_t<T1>;
  using R2 = result_type_t<T2>;

  using ResultType = std::common_type_t<R1, R2>;

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Sub(const T1 &lhs, const T2 &rhs);

  inline auto eval() const -> const ResultType &;

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Sub<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_sub_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Sub<T1, T2>::Sub(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto Sub<T1, T2>::eval() const
-> const ResultType & {
  ResultType tmp;
  assign_(tmp, *this);
  return tmp;
}

} // sym

#endif // SYMMATH_OPERATION_SUB_HPP
