#ifndef SYMMATH_OPERATIONS_SETS_INF_HPP
#define SYMMATH_OPERATIONS_SETS_INF_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Inf
  : private Operation {
public:

  using OperandType = If_t<IsOperation<T>{}, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Inf(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Inf<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Inf<T>::Inf(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_SETS_INF_HPP
