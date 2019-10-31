#ifndef SYMMATH_OPERATIONS_TENSORS_NORM_HPP
#define SYMMATH_OPERATIONS_TENSORS_NORM_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/property_traits/negatable.hpp>
#include <symmath/type_traits/add_const_ref.hpp>
#include <symmath/type_traits/add_const.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/is_lvalue_ref.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Norm
  : private Operation {
public:

  using ResultType = ResultType_t<T>;

  using Type = If_t<IsLValueRef_v<T>, AddConstRef_t<T>, AddConst_t<T>>;

private:

  Type operand_;

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
