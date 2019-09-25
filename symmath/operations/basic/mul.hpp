#ifndef SYMMATH_OPERATIONS_BASIC_MUL_HPP
#define SYMMATH_OPERATIONS_BASIC_MUL_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Mul
  : private Operation {
public:

  using R1 = ResultType_t<T1>;
  using R2 = ResultType_t<T2>;

  // using ResultType = std::common_type_t<R1, R2>;
  using ResultType = R1;

  using LhsOperandType = If_t<IsOperation<T1>{}, const T1, const T1&>;
  using RhsOperandType = If_t<IsOperation<T2>{}, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline Mul(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Mul<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_mul_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Mul<T1, T2>::Mul(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_MUL_HPP
