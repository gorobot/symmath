#ifndef SYMMATH_OPERATIONS_SETS_INTERSECTION_HPP
#define SYMMATH_OPERATIONS_SETS_INTERSECTION_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/temporary.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Intersection
  : private Operation {
public:

  using LhsOperandType = If_t<IsTemporary<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsTemporary<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline Intersection(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Intersection<T1, T2> &rhs)
  -> EnableIf_t<IsSet<U>{}> {
    apply_(lhs.derived(), rhs.lhs_);
    apply_(lhs.derived(), rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline Intersection<T1, T2>::Intersection(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

} // sym

#endif // SYMMATH_OPERATIONS_SETS_INTERSECTION_HPP
