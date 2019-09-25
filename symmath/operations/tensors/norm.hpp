#ifndef SYMMATH_OPERATIONS_TENSORS_NORM_HPP
#define SYMMATH_OPERATIONS_TENSORS_NORM_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "operation.hpp"
#include "../type_traits/enable_if.hpp"
#include <symmath/type_traits/is_operation.hpp>
#include "../type_traits/is_symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Norm
  : private Operation {
public:

  using R = ResultType_t<T>;

  using ResultType = R;

  using OperandType = If_t<IsOperation<T>{}, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Norm(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Norm<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Norm<T>::Norm(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_NORM_HPP
