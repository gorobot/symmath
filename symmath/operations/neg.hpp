#ifndef SYMMATH_OPERATIONS_NEG_HPP
#define SYMMATH_OPERATIONS_NEG_HPP

#include <type_traits>

#include "unary_operation.hpp"
#include "../type_traits/conditional.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/result_type.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1 >
class Neg
  : private UnaryOperation {
public:

  using R1 = ResultType_t<T1>;

  using ResultType = R1;

  using T1Type = If_t<IsOperation<T1>{}, const T1, const T1&>;

private:

  T1Type operand_;

public:

  explicit inline Neg(const T1 &operand);

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

} // sym

#endif // SYMMATH_OPERATIONS_NEG_HPP
