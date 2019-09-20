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

template< typename T,
          size_t Rows,
          size_t Cols >
class Matrix
  : public has_value_array<T, Rows, Cols>,
    public has_addition<Matrix<T, Rows, Cols>>,
    public has_additive_inverse<Matrix<T, Rows, Cols>>,
    public has_assignment<Matrix<T, Rows, Cols>>,
    public has_multiplication<Matrix<T, Rows, Cols>>,
    public has_subtraction<Matrix<T, Rows, Cols>>,
    private Tensor {
public:

  using ValueType = typename has_value_array<T, Rows, Cols>::ValueType;

  using VectorType = typename has_value_array<T, Rows, Cols>::VectorType;

  using ResultType = Matrix<T, Rows, Cols>;

  using has_value_array<T, Rows, Cols>::has_value_array;
  using has_value_array<T, Rows, Cols>::operator=;
  using has_assignment<Matrix<T, Rows, Cols>>::operator=;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_mul(const U &rhs);
  template< typename U >
  inline void assign_sub(const U &rhs);

  template< typename U >
  inline void assign_neg(const U &rhs);

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T,
          size_t Rows,
          size_t Cols >
inline size_t Matrix<T, Rows, Cols>::rows() const {
  return Rows;
}

template< typename T,
          size_t Rows,
          size_t Cols >
inline size_t Matrix<T, Rows, Cols>::cols() const {
  return Cols;
}

template< typename T,
          size_t Rows,
          size_t Cols >
inline T &
Matrix<T, Rows, Cols>::operator()(const size_t row, const size_t col) {
  return (*this)[row*Cols + col];
}

template< typename T,
          size_t Rows,
          size_t Cols >
inline const T &
Matrix<T, Rows, Cols>::operator()(const size_t row, const size_t col) const {
  return (*this)[row*Cols + col];
}

template< typename T,
          size_t Rows,
          size_t Cols >
template< typename U >
inline void
Matrix<T, Rows, Cols>::assign(const U &rhs) {
  this->value_ = result_of<U>::value(rhs);
}

template< typename T,
          size_t Rows,
          size_t Cols >
template< typename U >
inline void
Matrix<T, Rows, Cols>::assign_add(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Rows*Cols; i++) {
    this->value_[i] += result[i];
  }
}

template< typename T,
          size_t Rows,
          size_t Cols >
template< typename U >
inline void
Matrix<T, Rows, Cols>::assign_mul(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Rows*Cols; i++) {
    this->value_[i] *= result[i];
  }
}

template< typename T,
          size_t Rows,
          size_t Cols >
template< typename U >
inline void
Matrix<T, Rows, Cols>::assign_sub(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Rows*Cols; i++) {
    this->value_[i] -= result[i];
  }
}

template< typename T,
          size_t Rows,
          size_t Cols >
template< typename U >
inline void
Matrix<T, Rows, Cols>::assign_neg(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Rows*Cols; i++) {
    this->value_[i] = -result[i];
  }
}

} // sym

#endif // SYMMATH_TENSORS_MATRIX_HPP
