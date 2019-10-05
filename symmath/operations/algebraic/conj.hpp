#ifndef SYMMATH_OPERATIONS_ALGEBRAIC_CONJ_HPP
#define SYMMATH_OPERATIONS_ALGEBRAIC_CONJ_HPP

#include <complex>

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/add_const_ref.hpp>
#include <symmath/type_traits/add_const.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/is_lvalue_ref.hpp>
#include <symmath/type_traits/is_same.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Complex;

// -----------------------------------------------------------------------------

template< typename T >
class Conj
  : private Operation {
public:

  using ResultType = ResultType_t<T>;

  using Type = If_t<IsLValueRef_v<T>, AddConstRef_t<T>, AddConst_t<T>>;

private:

  Type operand_;

public:

  explicit inline Conj(const T &operand);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Conj<T> &rhs) {
    if constexpr(IsSame_v<T, Complex>) {
      assign_(lhs, std::conj(rhs.operand_));
    } else {
      assign_(lhs, rhs.operand_);
    }
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Conj<T>::Conj(const T &operand)
  : operand_(operand) {}

} // sym

#endif // SYMMATH_OPERATIONS_ALGEBRAIC_CONJ_HPP
