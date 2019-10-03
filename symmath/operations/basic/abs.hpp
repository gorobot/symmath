#ifndef SYMMATH_OPERATIONS_BASIC_ABS_HPP
#define SYMMATH_OPERATIONS_BASIC_ABS_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/add_const_ref.hpp>
#include <symmath/type_traits/add_const.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/is_lvalue_ref.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Abs
  : private Operation {
public:

  using ResultType = ResultType_t<T>;

  using Type = If_t<IsLValueRef_v<T>, AddConstRef_t<T>, AddConst_t<T>>;

private:

  Type operand_;

public:

  template< typename U >
  explicit inline Abs(U &&operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Abs<T> &rhs) {
    assign_(lhs, rhs.operand_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
template< typename U >
inline Abs<T>::Abs(U &&operand)
  : operand_(std::forward<U>(operand)) {}

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_ABS_HPP
