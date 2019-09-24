#ifndef SYMMATH_OPERATIONS_INV_HPP
#define SYMMATH_OPERATIONS_INV_HPP

#include <type_traits>

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include "../type_traits/result_type.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1 >
class Inv
  : private Operation {
public:

  using R1 = ResultType_t<T1>;

  using ResultType = R1;

  using T1Type = If_t<IsOperation<T1>{}, const T1, const T1&>;

private:

  T1Type operand_;

public:

  explicit inline Inv(const T1 &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Inv<T1> &rhs) {
    assign_inv_(lhs, rhs.operand_);
  }

  template< typename U >
  friend inline void
  assign_inv_(U &lhs, const Inv<T1> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1 >
inline Inv<T1>::Inv(const T1 &operand)
  : operand_(operand) {}

// -----------------------------------------------------------------------------
// Member Function Definitions

} // sym

#endif // SYMMATH_OPERATIONS_INV_HPP
