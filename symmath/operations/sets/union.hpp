#ifndef SYMMATH_SET_UNION_HPP
#define SYMMATH_SET_UNION_HPP

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
class Union
  : public Operation<Symbolic<Union<T1, T2>>> {
public:

  using LhsOperandType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline Union(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Union<T1, T2> &rhs)
  -> EnableIf_t<IsSet<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline Union<T1, T2>::Union(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
union(T1 &lhs, T2 &rhs)
-> EnableIf_t<IsSet<T1>{} && IsSet<T2>{}, const Union<T1, T2>> {
  return Union<T1, T2>(lhs.derived(), rhs.derived());
}

} // sym

#endif // SYMMATH_SET_UNION_HPP
