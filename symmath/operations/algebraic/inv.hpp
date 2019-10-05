#ifndef SYMMATH_OPERATIONS_ALGEBRAIC_INV_HPP
#define SYMMATH_OPERATIONS_ALGEBRAIC_INV_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/temporary.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Inv
  : private Operation {
public:

  using R = ResultType_t<T>;

  using ResultType = R;

  using OperandType = If_t<IsTemporary<T>, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Inv(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Inv<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Inv<T>::Inv(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_ALGEBRAIC_INV_HPP