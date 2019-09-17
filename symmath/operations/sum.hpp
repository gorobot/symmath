#ifndef SYMMATH_OPERATIONS_SUM_HPP
#define SYMMATH_OPERATIONS_SUM_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/is_symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Sum
  : public Operation<Symbolic<Sum<T>>> {
public:

  using LhsResultType = typename T1::Type;
  using RhsResultType = typename T2::Type;

  using Type = std::common_type_t<LhsResultType, RhsResultType>;

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Sum(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Sum<T1, T2> &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_add_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline Sum<T1, T2>::Sum(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator+(T1 &lhs, T2 &rhs)
-> std::enable_if_t<is_symbolic<T1>{} && is_symbolic<T2>{}, const Sum<T1, T2>> {
  return Sum<T1, T2>(lhs.derived(), rhs.derived());
}

} // sym

#endif // SYMMATH_OPERATIONS_SUM_HPP
