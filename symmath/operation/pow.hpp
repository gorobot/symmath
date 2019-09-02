#ifndef SYMMATH_OPERATION_POW_HPP
#define SYMMATH_OPERATION_POW_HPP

#include <type_traits>

#include "unary_operation.hpp"
#include "../type_traits/is_operation.hpp"
#include "../type_traits/result_type.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Pow
  : private UnaryOperation {
public:

  using R1 = result_type_t<T1>;
  using R2 = result_type_t<T2>;

  using ResultType = R1;

  using T1Type = std::conditional_t<is_operation<T1>{}, const T1, const T1&>;
  using T2Type = std::conditional_t<is_operation<T2>{}, const T2, const T2&>;

private:

  T1Type operand_;
  T2Type p_;

public:

  explicit inline Pow(const T1 &operand, const T2 &p);

  inline auto eval() const -> const ResultType;

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Pow<T1, T2> &rhs) {
    assign_(lhs, rhs.operand_);
    assign_pow_(lhs, rhs.p_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Pow<T1, T2>::Pow(const T1 &operand, const T2 &p)
  : operand_(operand),
    p_(p) {}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T1,
          typename T2 >
inline auto Pow<T1, T2>::eval() const
-> const ResultType {
  ResultType tmp;
  assign_(tmp, *this);
  return tmp;
}

} // sym

#endif // SYMMATH_OPERATION_POW_HPP
