#ifndef SYMMATH_SET_UNION_HPP
#define SYMMATH_SET_UNION_HPP

#include <type_traits>

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_temporary.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Union
  : private Operation {
public:

  using LhsOperandType = If_t<IsTemporary<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsTemporary<T2>, const T2, const T2&>;

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

} // sym

#endif // SYMMATH_SET_UNION_HPP
