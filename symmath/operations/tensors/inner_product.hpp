#ifndef SYMMATH_OPERATIONS_TENSORS_INNER_PRODUCT_HPP
#define SYMMATH_OPERATIONS_TENSORS_INNER_PRODUCT_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "operation.hpp"
#include "../type_traits/enable_if.hpp"
#include <symmath/type_traits/is_operation.hpp>
#include "../type_traits/is_symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class InnerProduct
  : public Operation<Symbolic<InnerProduct<T1, T2>>> {
public:

  using LhsResultType = typename T1::ResultType;
  using RhsResultType = typename T2::ResultType;

  using ResultType = std::common_type_t<LhsResultType, RhsResultType>;

  using LhsOperandType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline InnerProduct(const T1 &lhs, const T2 &rhs);

  inline auto eval() const -> const ResultType;

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const InnerProduct<T1, T2> &rhs)
  -> EnableIf_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_mul_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline InnerProduct<T1, T2>::InnerProduct(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto InnerProduct<T1, T2>::eval() const
-> const ResultType {
  ResultType tmp;
  apply_(tmp, *this);
  return tmp;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator*(const Symbolic<T1> &lhs, const Symbolic<T2> &rhs)
-> const InnerProduct<T1, T2> {
  return InnerProduct<T1, T2>(lhs.derived(), rhs.derived());
}

// template< typename T1,
//           typename T2 >
// inline Symbolic<T1> &
// operator*=(Symbolic<T1> &lhs, const Symbolic<T2> &rhs) {
//   apply_mul_(lhs.derived(), rhs.derived());
//   return lhs;
// }

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_INNER_PRODUCT_HPP
