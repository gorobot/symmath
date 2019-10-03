#ifndef SYMMATH_OPERATIONS_BASIC_FACTORIAL_HPP
#define SYMMATH_OPERATIONS_BASIC_FACTORIAL_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/temporary.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Factorial
  : private Operation {
public:

  using R = ResultType_t<T>;

  using ResultType = R;

  using OperandType = If_t<IsTemporary<T>, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Factorial(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Factorial<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Factorial<T>::Factorial(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_FACTORIAL_HPP
