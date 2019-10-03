#ifndef SYMMATH_OPERATIONS_CALCULUS_LIM_HPP
#define SYMMATH_OPERATIONS_CALCULUS_LIM_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/temporary.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Lim
  : private Operation {
public:

  using R1 = ResultType_t<T1>;
  using R2 = ResultType_t<T2>;

  // using ResultType = std::common_type_t<R1, R2>;
  using ResultType = R1;

  using LhsOperandType = If_t<IsTemporary<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsTemporary<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline Lim(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Lim<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_add_(lhs, rhs.rhs_);
  }

  template< typename U >
  friend inline void
  assign_add_(U &lhs, const Lim<T1, T2> &rhs) {
    assign_add_(lhs, rhs.lhs_);
    assign_add_(lhs, rhs.rhs_);
  }

  template< typename U >
  friend inline void
  assign_sub_(U &lhs, const Lim<T1, T2> &rhs) {
    assign_sub_(lhs, rhs.lhs_);
    assign_sub_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Lim<T1, T2>::Lim(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions

} // sym

#endif // SYMMATH_OPERATIONS_CALCULUS_LIM_HPP
