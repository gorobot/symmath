#ifndef SYMMATH_OPERATIONS_BASIC_DIV_HPP
#define SYMMATH_OPERATIONS_BASIC_DIV_HPP

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
class Div
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

  template< typename U1, typename U2 >
  explicit inline Div(U1 &&lhs, U2 &&rhs);

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
template< typename U1,
          typename U2 >
inline Div<T1, T2>::Div(U1 &&lhs, U2 &&rhs)
  : lhs_(std::forward<U1>(lhs)),
    rhs_(std::forward<U2>(rhs)) {}

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_DIV_HPP
