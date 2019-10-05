#ifndef SYMMATH_OPERATIONS_TENSORS_DIRECT_SUM_HPP
#define SYMMATH_OPERATIONS_TENSORS_DIRECT_SUM_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class DirectSum
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

  explicit inline DirectSum(const T1 &lhs, const T2 &rhs);

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const DirectSum<T1, T2> &rhs) {
    assign_(lhs, rhs.lhs_);
    assign_dsum_(lhs, rhs.rhs_);
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T1,
          typename T2 >
inline DirectSum<T1, T2>::DirectSum(const T1 &lhs, const T2 &rhs)
  : lhs_(lhs),
    rhs_(rhs) {}

} // sym

#endif // SYMMATH_OPERATIONS_TENSORS_DIRECT_SUM_HPP
