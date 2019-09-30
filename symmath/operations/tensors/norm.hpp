#ifndef SYMMATH_OPERATIONS_TENSORS_NORM_HPP
#define SYMMATH_OPERATIONS_TENSORS_NORM_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_temporary.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Norm
  : private Operation {
public:

  using R = ResultType_t<T>;

  using ResultType = R;

  using OperandType = If_t<IsTemporary<T>, const T, const T&>;

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
