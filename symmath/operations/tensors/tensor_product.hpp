#ifndef SYMMATH_OPERATIONS_TENSORS_TENSOR_PRODUCT_HPP
#define SYMMATH_OPERATIONS_TENSORS_TENSOR_PRODUCT_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class TensorProduct
  : public BinaryOperation {
public:

  using R1 = ResultType_t<T1>;
  using R2 = ResultType_t<T2>;

  // using ResultType = std::common_type_t<R1, R2>;
  using ResultType = R1;

  using LhsOperandType = If_t<IsTemporary<T1>, const T1, const T1&>;
  using RhsOperandType = If_t<IsTemporary<T2>, const T2, const T2&>;

private:

  LhsOperandType lhs_;
  RhsOperandType rhs_;

public:

  explicit inline TensorProduct(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const TensorProduct<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_tensor_product_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline TensorProduct<T1, T2>::TensorProduct(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_TENSOR_PRODUCT_HPP
