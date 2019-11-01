#ifndef SYMMATH_TENSORS_MATRIX_HPP
#define SYMMATH_TENSORS_MATRIX_HPP

#include <symmath/tensors/tensor.hpp>
#include <symmath/type_traits/nested_initializer_list.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Matrix {

};

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 1, 1> {
public:

  static constexpr size_t Order = (2);

                          using This      = Tensor<T, 1, 1>;
                          using Reference = This&;
                          using ConstRef  = const This&;
                          using MoveRef   = This&&;
  template< typename U >  using Other     = Tensor<U, 1, 1>;

  template< typename U >  using Scalar_   = Tensor<U, 0, 0>;
  template< typename U >  using Covector_ = Tensor<U, 0, 1>;
  template< typename U >  using Vector_   = Tensor<U, 1, 0>;
  template< typename U >  using Matrix_   = Tensor<U, 1, 1>;

  // using ElementOf =

  using ValueType = T;
  using ArrayType = std::vector<ValueType>;

  // STL Type Requirements
  using value_type      = ValueType;
  using reference       = ValueType&;
  using const_reference = const ValueType&;
  using iterator        = ArrayType::iterator;
  using const_iterator  = ArrayType::const_iterator;
  using difference_type = ArrayType::difference_type;
  using size_type       = ArrayType::size_type;

private:

  std::array<size_t, Order> dim_;

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor() = default;

  explicit inline Tensor(const size_t n, const size_t m);
  explicit inline Tensor(NestedInitializerList_t<T, Order> list);

  template< typename U >  explicit inline Tensor(const Other<U> &other);
  template< typename U >  explicit inline Tensor(Other<U> &&other);

  // Assignment Operator
  inline This &operator=(NestedInitializerList_t<T, Order> list);

  template< typename U >  inline This &operator=(const Other<U> &other);
  template< typename U >  inline This &operator=(Other<U> &&other);

  // Assign
  template< typename U >  inline void assign(const Other<U> &rhs);

  // Assign Scalar Multiplication
                          inline void assign_scalar_mul(const ValueType &rhs);
  template< typename U >  inline void assign_scalar_mul(const Scalar<U> &rhs);

  // Assign Tensor Product
  template< typename U, size_t N, size_t M >
  inline void assign_tensor_prod(const Tensor<U, N, M> &rhs);

  inline ValueType &operator()(const size_t i_, const size_t j_);
  inline const ValueType &operator()(const size_t i_, const size_t j_) const;

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions


} // sym

#endif // SYMMATH_TENSORS_MATRIX_HPP
