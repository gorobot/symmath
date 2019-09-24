#ifndef SYMMATH_OPERATIONS_NORM_HPP
#define SYMMATH_OPERATIONS_NORM_HPP

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
class Norm
  : public Operation<Symbolic<Norm<T1, T2>>> {
public:

  using LhsResultType = typename T1::ResultType;
  using RhsResultType = typename T2::ResultType;

  using ResultType = std::common_type_t<LhsResultType, RhsResultType>;

  using LhsType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Norm(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Norm<T1, T2> &rhs)
  -> EnableIf_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_mul_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Norm<T1, T2>::Norm(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions

} // sym

#endif // SYMMATH_OPERATIONS_NORM_HPP
