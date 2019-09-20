#ifndef SYMMATH_TENSORS_SCALAR_HPP
#define SYMMATH_TENSORS_SCALAR_HPP

#include <type_traits>

#include "tensor.hpp"
#include "../properties/has_value_array.hpp"
#include "../properties/has_algebraic_operations.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Scalar
  : public has_value_array<T, 1>,
    public has_algebraic_operations<Scalar<T>>,
    private Tensor {
public:

  using ValueType = typename has_value_array<T, 1>::ValueType;

  using VectorType = typename has_value_array<T, 1>::VectorType;

  using ResultType = Scalar<T>;

  using has_value_array<T, 1>::has_value_array;
  using has_value_array<T, 1>::operator=;
  using has_assignment<Scalar<T>>::operator=;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_div(const U &rhs);
  template< typename U >
  inline void assign_mul(const U &rhs);
  template< typename U >
  inline void assign_sub(const U &rhs);

  template< typename U >
  inline void assign_neg(const U &p);
  template< typename U >
  inline void assign_inv(const U &p);
  template< typename U >
  inline void assign_pow(const U &p);

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline size_t Scalar<T>::rows() const {
  return 1;
}

template< typename T >
inline size_t Scalar<T>::cols() const {
  return 1;
}

template< typename T >
inline T &
Scalar<T>::operator()(const size_t row, const size_t col) {
  // return (*this)[row*Cols + col];
  return (*this)[0];
}

template< typename T >
inline const T &
Scalar<T>::operator()(const size_t row, const size_t col) const {
  // return (*this)[row*Cols + col];
  return (*this)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign(const U &rhs) {
  this->value_[0] = result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_add(const U &rhs) {
  this->value_[0] += result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_div(const U &rhs) {
  this->value_[0] /= result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_mul(const U &rhs) {
  this->value_[0] *= result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_sub(const U &rhs) {
  this->value_[0] -= result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_neg(const U &rhs) {
  this->value_[0] = -result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_inv(const U &rhs) {
  this->value_[0] = 1.0/result_of<U>::value(rhs)[0];
}

template< typename T >
template< typename U >
inline void
Scalar<T>::assign_pow(const U &p) {
  this->value_[0] = std::pow(this->value_[0], result_of<U>::value(p)[0]);
}

} // sym

#endif // SYMMATH_TENSORS_SCALAR_HPP
