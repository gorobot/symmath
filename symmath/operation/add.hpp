#ifndef SYMMATH_OPERATION_ADD_HPP
#define SYMMATH_OPERATION_ADD_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/is_symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Add
  : public Operation<Symbolic<Add<T1, T2>>> {
public:

  using LhsResultType = typename T1::ResultType;
  using RhsResultType = typename T2::ResultType;

  using ResultType = std::common_type_t<LhsResultType, RhsResultType>;

  using LhsType = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using RhsType = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline Add(const T1 &lhs, const T2 &rhs);

  inline auto eval() const -> const ResultType;

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Add<T1, T2> &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_add_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Add<T1, T2>::Add(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto Add<T1, T2>::eval() const
-> const ResultType {
  ResultType tmp;
  apply_(tmp, *this);
  return tmp;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator+(const Symbolic<T1> &lhs, const Symbolic<T2> &rhs)
-> const Add<T1, T2> {
  return Add<T1, T2>(lhs.derived(), rhs.derived());
}

// template< typename T1,
//           typename T2 >
// inline Symbolic<T1> &
// operator+=(Symbolic<T1> &lhs, const Symbolic<T2> &rhs) {
//   apply_add_(lhs.derived(), rhs.derived());
//   return lhs;
// }

} // sym

#endif // SYMMATH_OPERATION_ADD_HPP
