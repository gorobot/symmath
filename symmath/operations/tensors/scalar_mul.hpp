#ifndef SYMMATH_OPERATIONS_TENSORS_SCALAR_MUL_HPP
#define SYMMATH_OPERATIONS_TENSORS_SCALAR_MUL_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include "../type_traits/enable_if.hpp"
#include <symmath/type_traits/is_operation.hpp>
#include "../type_traits/is_scalar.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class ScalarMul
  : private Operation {
public:

  using LhsResultType = typename T1::ResultType;
  using RhsResultType = typename T2::ResultType;

  // using ResultType = std::common_type_t<LhsResultType, RhsResultType>;
  // using ResultType = If_t<is_scalar<LhsResultType>{}, RhsResultType, LhsResultType>;
  using ResultType = LhsResultType;

  using LhsOperandType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline ScalarMul(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const ScalarMul<T1, T2> &rhs)
  -> EnableIf_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_mul_(lhs.derived(), rhs.rhs_);
  }

  // template< typename U >
  // friend inline auto
  // apply_(U &lhs, const ScalarMul<T1, T2> &rhs)
  // -> EnableIf_t<is_symbolic<U>{}> {
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

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_SCALAR_MUL_HPP
