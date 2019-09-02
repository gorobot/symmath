#ifndef SYMMATH_OPERATION_NEG_HPP
#define SYMMATH_OPERATION_NEG_HPP

#include <type_traits>

#include "unary_operation.hpp"
#include "../type_traits/is_operation.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1 >
class Neg
  : private UnaryOperation {
public:

  using R1 = result_type_t<T1>;

  using ResultType = R1;

  using Type = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;

private:

  Type operand_;

public:

  explicit inline Neg(const T1 &operand);

  inline auto eval() const -> const ResultType;

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Neg<T1> &rhs) {
    assign_neg_(lhs, rhs.operand_);
  }

  template< typename U >
  friend inline void
  assign_sub_(U &lhs, const Neg<T1> &rhs) {
    assign_add_(lhs, rhs.operand_);
  }

  template< typename U >
  friend inline void
  assign_neg_(U &lhs, const Neg<T1> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1 >
inline Neg<T1>::Neg(const T1 &operand)
  : operand_(operand) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1 >
inline auto Neg<T1>::eval() const
-> const ResultType {
  ResultType tmp;
  assign_(tmp, *this);
  return tmp;
}

} // sym

#endif // SYMMATH_OPERATION_NEG_HPP
