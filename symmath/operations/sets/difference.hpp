#ifndef SYMMATH_OPERATIONS_SETS_DIFFERENCE_HPP
#define SYMMATH_OPERATIONS_SETS_DIFFERENCE_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Difference
  : private Operation {
public:

  using LhsOperandType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline Difference(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Difference<T1, T2> &rhs)
  -> EnableIf_t<IsSet<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline Difference<T1, T2>::Difference(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

} // sym

#endif // SYMMATH_OPERATIONS_SETS_DIFFERENCE_HPP
