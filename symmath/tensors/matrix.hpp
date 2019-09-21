#ifndef SYMMATH_TENSORS_MATRIX_HPP
#define SYMMATH_TENSORS_MATRIX_HPP

#include <type_traits>

#include "tensor.hpp"
#include "../properties/has_value_array.hpp"
#include "../properties/has_addition.hpp"
#include "../properties/has_additive_inverse.hpp"
#include "../properties/has_assignment.hpp"
#include "../properties/has_multiplication.hpp"
#include "../properties/has_subtraction.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using Matrix = Tensor<T, 2, 0>;

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 2, 0> {
public:

  using This = Matrix<T>;

  // using ElementOf =

  using ValueType = T;
  using ArrayType = std::vector<ValueType>;

private:

  size_t dim_[2];

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();
  explicit inline Tensor(const size_t n, const size_t m);
  explicit inline Tensor(std::initializer_list<std::initializer_list<T>> list);

  template< typename U >  explicit inline Tensor(const Matrix<U> &other);
  template< typename U >  explicit inline Tensor(Matrix<U> &&other);

  // Assignment Operator
  inline This &operator=(std::initializer_list<std::initializer_list<T>> list);

  template< typename U >  inline This &operator=(const Matrix<U> &other);
  template< typename U >  inline This &operator=(Matrix<U> &&other);

  inline ValueType &operator()(const size_t i_, const size_t j_);
  inline const ValueType &operator()(const size_t i_, const size_t j_) const;

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions


} // sym

#endif // SYMMATH_TENSORS_MATRIX_HPP
