#ifndef SYMMATH_OPERATIONS_BASIC_DPROD_HPP
#define SYMMATH_OPERATIONS_BASIC_DPROD_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class DProd
  : private Operation {
public:

  using LhsResultType = typename T1::Type;
  using RhsResultType = typename T2::Type;

  // using Type = std::common_type_t<LhsResultType, RhsResultType>;
  using ResultType = R1;

  using LhsType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline DProd(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const DProd<T1, T2> &rhs)
  -> EnableIf_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_add_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline DProd<T1, T2>::DProd(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_DPROD_HPP
