#ifndef SYMMATH_TENSORS_SCALAR_HPP
#define SYMMATH_TENSORS_SCALAR_HPP

#include <symmath/numerics/scalar.hpp>
#include <symmath/operations/tensors/scalar_mul.hpp>
#include <symmath/tensors/tensor.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          size_t N,
          size_t M >
inline auto
operator*(Scalar<T1> &&lhs, Tensor<T2, N, M> &&rhs)
-> const ScalarMul<Scalar<T1>, Tensor<T2, N, M>> {
  using LhsType = Scalar<T1>;
  using RhsType = Tensor<T2, N, M>;
  using ResultType = Add<LhsType, RhsType>;

  return ResultType(std::forward<LhsType>(lhs), std::forward<RhsType>(rhs));
}

template< typename T1,
          typename T2,
          size_t N,
          size_t M >
inline auto
operator*(Tensor<T1, N, M> &&lhs, Scalar<T2> &&rhs)
-> const ScalarMul<Tensor<T1, N, M>, Scalar<T2>> {
  using LhsType = Tensor<T1, N, M>;
  using RhsType = Scalar<T2>;
  using ResultType = Add<LhsType, RhsType>;

  return ResultType(std::forward<LhsType>(lhs), std::forward<RhsType>(rhs));
}

} // sym

#endif // SYMMATH_TENSORS_SCALAR_HPP
