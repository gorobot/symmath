#ifndef SYMMATH_OPERATIONS_CALCULUS_LAPLACIAN_HPP
#define SYMMATH_OPERATIONS_CALCULUS_LAPLACIAN_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Laplacian
  : private Operation {
public:

  using R = ResultType_t<T>;

  using ResultType = R;

  using OperandType = If_t<IsOperation<T>{}, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Laplacian(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Laplacian<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Laplacian<T>::Laplacian(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_CALCULUS_LAPLACIAN_HPP
