#ifndef SYMMATH_OPERATIONS_BASIC_POW_HPP
#define SYMMATH_OPERATIONS_BASIC_POW_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/temporary.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Pow
  : private Operation {
public:

  using R1 = ResultType_t<T1>;
  using R2 = ResultType_t<T2>;

  using ResultType = R1;

  using T1Type = If_t<IsTemporary<T1>, const T1, const T1&>;
  using T2Type = If_t<IsTemporary<T2>, const T2, const T2&>;

private:

  T1Type operand_;
  T2Type p_;

public:

  explicit inline Pow(const T1 &operand, const T2 &p);

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

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_POW_HPP
