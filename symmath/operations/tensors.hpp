#ifndef SYMMATH_OPERATIONS_TENSORS_HPP
#define SYMMATH_OPERATIONS_TENSORS_HPP

#include <iostream>

#include <symmath/operations/algebraic.hpp>
#include <symmath/operations/tensors/cross.hpp>
#include <symmath/operations/tensors/ctranspose.hpp>
#include <symmath/operations/tensors/direct_product.hpp>
#include <symmath/operations/tensors/direct_sum.hpp>
#include <symmath/operations/tensors/dot.hpp>
#include <symmath/operations/tensors/inner_product.hpp>
// #include <symmath/operations/tensors/magnitude.hpp>
#include <symmath/operations/tensors/matrix_inv.hpp>
#include <symmath/operations/tensors/matrix_mul.hpp>
#include <symmath/operations/tensors/matrix_pinv.hpp>
#include <symmath/operations/tensors/norm.hpp>
#include <symmath/operations/tensors/outer_product.hpp>
#include <symmath/operations/tensors/scalar_mul.hpp>
#include <symmath/operations/tensors/tensor_product.hpp>
#include <symmath/operations/tensors/transpose.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_basic_number.hpp>

namespace sym {

// -----------------------------------------------------------------------------
// Forward Declaration
template< typename T, size_t N, size_t M > class Tensor;

// -----------------------------------------------------------------------------

template< typename T1, typename T2 >
inline auto assign_scalar_mul_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<IsCovariantResult<T1, T2>>;

// -----------------------------------------------------------------------------
// Addition
template< typename T1,
          typename T2,
          size_t N,
          size_t M >
inline auto
operator+(Tensor<T1, N, M> &&lhs, Tensor<T2, N, M> &&rhs)
-> const Add<Tensor<T1, N, M>, Tensor<T2, N, M>> {
  using LhsType = Tensor<T1, N, M>;
  using RhsType = Tensor<T2, N, M>;
  using ResultType = Add<LhsType, RhsType>;
  // using ResultType = Tensor<CovariantResult_t<T1, T2>, N, M>;
  std::cout << "this one" << '\n';

  return ResultType(std::forward<LhsType>(lhs), std::forward<RhsType>(rhs));
}

// -----------------------------------------------------------------------------
// Subtraction
template< typename T1,
          typename T2,
          size_t N,
          size_t M >
inline auto
operator-(Tensor<T1, N, M> &&lhs, Tensor<T2, N, M> &&rhs)
-> const Sub<Tensor<T1, N, M>, Tensor<T2, N, M>> {
  using LhsType = Tensor<T1, N, M>;
  using RhsType = Tensor<T2, N, M>;
  using ResultType = Sub<LhsType, RhsType>;
  // using ResultType = Tensor<CovariantResult_t<T1, T2>, N, M>;
  std::cout << "this one" << '\n';

  return ResultType(std::forward<LhsType>(lhs), std::forward<RhsType>(rhs));
}

// -----------------------------------------------------------------------------

template< typename T1, typename T2 >
inline auto cross(T1 &lhs, const T2 &rhs)
-> const Cross<T1, T2>;

template< typename T >
inline auto ctranspose(T &operand)
-> const CTranspose<T>;

template< typename T1, typename T2 >
inline auto direct_product(T1 &lhs, const T2 &rhs)
-> const DirectProduct<T1, T2>;

template< typename T1, typename T2 >
inline auto direct_sum(T1 &lhs, const T2 &rhs)
-> const DirectSum<T1, T2>;

template< typename T1, typename T2 >
inline auto dot(T1 &lhs, const T2 &rhs)
-> const Dot<T1, T2>;

template< typename T1, typename T2 >
inline auto inner_product(T1 &lhs, const T2 &rhs)
-> const InnerProduct<T1, T2>;

// template< typename T >
// inline auto magnitude(T &operand)
// -> const Magnitude<T>;

template< typename T >
inline auto matrix_inv(T &operand)
-> const MatrixInv<T>;

template< typename T1, typename T2 >
inline auto matrix_mul(T1 &lhs, const T2 &rhs)
-> const MatrixMul<T1, T2>;

template< typename T >
inline auto matrix_pinv(T &operand)
-> const MatrixPInv<T>;

template< typename T >
inline auto norm(T &operand)
-> const Norm<T>;

template< typename T1, typename T2 >
inline auto outer_product(T1 &lhs, const T2 &rhs)
-> const OuterProduct<T1, T2>;

template< typename T1, typename T2 >
inline auto scalar_mul(T1 &lhs, const T2 &rhs)
-> const ScalarMul<T1, T2>;

template< typename T1, typename T2 >
inline auto tensor_product(T1 &lhs, const T2 &rhs)
-> const TensorProduct<T1, T2>;

template< typename T >
inline auto transpose(T &operand)
-> const CTranspose<T>;

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_HPP
