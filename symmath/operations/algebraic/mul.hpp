#ifndef SYMMATH_OPERATIONS_ALGEBRAIC_MUL_HPP
#define SYMMATH_OPERATIONS_ALGEBRAIC_MUL_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/add_const_ref.hpp>
#include <symmath/type_traits/add_const.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/is_lvalue_ref.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Mul
  : private Operation {
public:

  using LhsResultType     = ResultType_t<T1>;
  using RhsResultType     = ResultType_t<T2>;
  using ResultType        = Covariant_t<LhsResultType, RhsResultType>;

  using LhsType = If_t<IsLValueRef_v<T1>, AddConstRef_t<T1>, AddConst_t<T1>>;
  using RhsType = If_t<IsLValueRef_v<T2>, AddConstRef_t<T2>, AddConst_t<T2>>;

private:

  LhsType lhs_;
  RhsType rhs_;

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

#endif // SYMMATH_OPERATIONS_ALGEBRAIC_MUL_HPP