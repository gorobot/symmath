#ifndef SYMMATH_OPERATIONS_TENSOR_PROD_HPP
#define SYMMATH_OPERATIONS_TENSOR_PROD_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class TensorProd
  : public BinaryOperation {
public:

  using R1 = ResultType_t<T1>;
  using R2 = ResultType_t<T2>;

  // using ResultType = std::common_type_t<R1, R2>;
  using ResultType = R1;

  using LhsType = If_t<IsOperation<T1>, const T1, const T1&>;
  using RhsType = If_t<IsOperation<T2>, const T2, const T2&>;

private:

  LhsType lhs_;
  RhsType rhs_;

public:

  explicit inline TensorProd(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const TensorProd<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_tensor_product_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline TensorProd<T1, T2>::TensorProd(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

// -----------------------------------------------------------------------------
// Member Function Definitions

} // sym

#endif // SYMMATH_OPERATIONS_TENSOR_PROD_HPP
