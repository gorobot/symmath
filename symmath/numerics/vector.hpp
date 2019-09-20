#ifndef SYMMATH_TENSORS_VECTOR_HPP
#define SYMMATH_TENSORS_VECTOR_HPP

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
          size_t Length >
class Vector
  : private Tensor,
    public ElementOf<VectorSpace>,
    public has_assignment<Vector>,
    public has_value_array<T, Length> {
public:

  using ValueType = typename has_value_array<T, Length>::ValueType;
  using VectorType = typename has_value_array<T, Length>::VectorType;
  using ResultType = Vector<T, Length>;

  using has_value_array<T, Length>::has_value_array;
  using has_value_array<T, Length>::operator=;
  using has_assignment<Vector<T, Length>>::operator=;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_scalar_mul(const U &rhs);
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
          size_t Length >
inline size_t Vector<T, Length>::rows() const {
  return Length;
}

template< typename T,
          size_t Length >
inline size_t Vector<T, Length>::cols() const {
  return 1;
}

template< typename T,
          size_t Length >
inline T &
Vector<T, Length>::operator()(const size_t row, const size_t col) {
  return (*this)[row*1 + col];
}

template< typename T,
          size_t Length >
inline const T &
Vector<T, Length>::operator()(const size_t row, const size_t col) const {
  return (*this)[row*1 + col];
}

template< typename T,
          size_t Length>
template< typename U >
inline void
Vector<T, Length>::assign(const U &rhs) {
  this->value_ = result_of<U>::value(rhs);
}

template< typename T,
          size_t Length>
template< typename U >
inline void
Vector<T, Length>::assign_add(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Length; i++) {
    this->value_[i] += result[i];
  }
}

template< typename T,
          size_t Length>
template< typename U >
inline void
Vector<T, Length>::assign_scalar_mul(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Length; i++) {
    this->value_[i] *= result[i];
  }
}

template< typename T,
          size_t Length>
template< typename U >
inline void
Vector<T, Length>::assign_sub(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Length; i++) {
    this->value_[i] -= result[i];
  }
}

template< typename T,
          size_t Length>
template< typename U >
inline void
Vector<T, Length>::assign_neg(const U &rhs) {
  auto result = result_of<U>::value(rhs);
  for(size_t i = 0; i < Length; i++) {
    this->value_[i] = -result[i];
  }
}

} // sym

#endif // SYMMATH_TENSORS_VECTOR_HPP
