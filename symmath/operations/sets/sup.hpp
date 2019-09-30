#ifndef SYMMATH_OPERATIONS_SETS_SUP_HPP
#define SYMMATH_OPERATIONS_SETS_SUP_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/is_temporary.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Sup
  : private Operation {
public:

  using OperandType = If_t<IsTemporary<T>, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Sup(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Sup<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Sup<T>::Sup(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_SETS_SUP_HPP
