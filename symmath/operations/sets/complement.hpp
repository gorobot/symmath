#ifndef SYMMATH_OPERATIONS_SETS_COMPLEMENT_HPP
#define SYMMATH_OPERATIONS_SETS_COMPLEMENT_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/temporary.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Complement
  : private Operation {
public:

  using OperandType = If_t<IsTemporary<T>, const T, const T&>;

private:

  OperandType operand_;

public:

  explicit inline Complement(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Complement<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Complement<T>::Complement(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_SETS_COMPLEMENT_HPP
