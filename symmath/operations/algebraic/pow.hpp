#ifndef SYMMATH_OPERATIONS_ALGEBRAIC_POW_HPP
#define SYMMATH_OPERATIONS_ALGEBRAIC_POW_HPP

#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/add_const_ref.hpp>
#include <symmath/type_traits/add_const.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/is_lvalue_ref.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Pow
  : private Operation {
public:

  using BaseResultType    = ResultType_t<T1>;
  using ExpResultType     = ResultType_t<T2>;
  using ResultType        = Covariant_t<BaseResultType, ExpResultType>;

  using BaseType = If_t<IsLValueRef_v<T1>, AddConstRef_t<T1>, AddConst_t<T1>>;
  using ExpType  = If_t<IsLValueRef_v<T2>, AddConstRef_t<T2>, AddConst_t<T2>>;

private:

  BaseType base_;
  ExpType exponent_;

public:

  explicit inline Pow(const T1 &base, const T2 &exponent);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const Pow<T1, T2> &rhs) {
    assign_(lhs, rhs.base_);
    assign_pow_(lhs, rhs.exponent_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline Pow<T1, T2>::Pow(const T1 &base, const T2 &exponent)
  : base_(base),
    exponent_(exponent) {}

} // sym

#endif // SYMMATH_OPERATIONS_ALGEBRAIC_POW_HPP
