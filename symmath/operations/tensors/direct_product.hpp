#ifndef SYMMATH_OPERATIONS_TENSORS_DIRECT_PRODUCT_HPP
#define SYMMATH_OPERATIONS_TENSORS_DIRECT_PRODUCT_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_temporary.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class DirectProduct
  : private Operation {
public:

  using LhsResultType = typename T1::Type;
  using RhsResultType = typename T2::Type;

  // using Type = std::common_type_t<LhsResultType, RhsResultType>;
  using ResultType = R1;

  using LhsOperandType = If_t<IsTemporary<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsTemporary<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline DirectProduct(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const DirectProduct<T1, T2> &rhs) {
    apply_(lhs.derived(), rhs.lhs_);
    apply_add_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline DirectProduct<T1, T2>::DirectProduct(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_DIRECT_PRODUCT_HPP
