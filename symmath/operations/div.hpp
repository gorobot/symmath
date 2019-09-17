#ifndef SYMMATH_OPERATIONS_DIV_HPP
#define SYMMATH_OPERATIONS_DIV_HPP

#include <type_traits>

#include "binary_operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/result_type.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Div
  : private BinaryOperation {
public:

  using R1 = result_type_t<T1>;
  using R2 = result_type_t<T2>;

  // using ResultType = std::common_type_t<R1, R2>;
  using ResultType = R1;

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Div(const T1 &lhs, const T2 &rhs);

  inline auto eval() const -> const ResultType;

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Div<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_div_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Div<T1, T2>::Div(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto Div<T1, T2>::eval() const
-> const ResultType {
  ResultType tmp;
  assign_(tmp, *this);
  return tmp;
}

} // sym

#endif // SYMMATH_OPERATIONS_DIV_HPP
