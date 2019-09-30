#ifndef SYMMATH_OPERATIONS_TENSORS_PROD_HPP
#define SYMMATH_OPERATIONS_TENSORS_PROD_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_temporary.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Magnitude
  : private Operation {
public:

  using R = ResultType_t<T>;

  using ResultType = R;

  using OperandType = If_t<IsTemporary<T>, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Magnitude(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Magnitude<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Magnitude<T>::Magnitude(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_PROD_HPP
