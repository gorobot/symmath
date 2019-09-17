#ifndef SYMMATH_OPERATIONS_INV_HPP
#define SYMMATH_OPERATIONS_INV_HPP

#include <type_traits>

#include "unary_operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/result_type.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1 >
class Inv
  : private UnaryOperation {
public:

  using R1 = result_type_t<T1>;

  using ResultType = R1;

  using T1Type = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;

private:

  T1Type operand_;

public:

  explicit inline Inv(const T1 &operand);

  inline auto eval() const -> const ResultType;

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
template< typename T1 >
inline auto Inv<T1>::eval() const
-> const ResultType {
  ResultType tmp;
  assign_(tmp, *this);
  return tmp;
}

} // sym

#endif // SYMMATH_OPERATIONS_INV_HPP
