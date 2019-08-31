#ifndef SYMMATH_MATRIX_MATRIX_HPP
#define SYMMATH_MATRIX_MATRIX_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "storage.hpp"
#include "../type_traits/is_applicable.hpp"
#include "../type_traits/is_scalar.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t R,
          size_t C >
class Matrix
  : public Symbolic<Matrix<T, R, C>>,
    public Storage<T, R, C> {
public:

  using ValueType = typename Storage<T, R, C>::ValueType;

  using ArrayType = typename Storage<T, R, C>::ArrayType;
  using VectorType = typename Storage<T, R, C>::VectorType;

  using ResultType = Matrix<T, R, C>;

private:

public:

  using Storage<T, R, C>::Storage;
  using Storage<T, R, C>::operator=;

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline Matrix<T, R, C> &operator=(const Symbolic<U> &rhs);

  inline Matrix<T, R, C> &operator+=(const ValueType &rhs);
  inline Matrix<T, R, C> &operator*=(const ValueType &rhs);
  inline Matrix<T, R, C> &operator-=(const ValueType &rhs);

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T, R, C>, U>{}>;

  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T, R, C>, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_scalar<U>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T, R, C>, U>{}>;

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T,
          size_t R,
          size_t C >
inline auto
Matrix<T, R, C>::eval() const
-> const ResultType {
  return *this;
}

template< typename T,
          size_t R,
          size_t C >
inline size_t Matrix<T, R, C>::rows() const {
  return R;
}

template< typename T,
          size_t R,
          size_t C >
inline size_t Matrix<T, R, C>::cols() const {
  return C;
}

template< typename T,
          size_t R,
          size_t C >
inline T &
Matrix<T, R, C>::operator()(const size_t row, const size_t col) {
  return (*this)[row*C + col];
}

template< typename T,
          size_t R,
          size_t C >
inline const T &
Matrix<T, R, C>::operator()(const size_t row, const size_t col) const {
  return (*this)[row*C + col];
}

template< typename T,
          size_t R,
          size_t C >
template< typename U >
inline Matrix<T, R, C> &
Matrix<T, R, C>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T,
          size_t R,
          size_t C >
inline Matrix<T, R, C> &
Matrix<T, R, C>::operator+=(const ValueType &rhs) {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] += rhs;
  }
  return *this;
}
template< typename T,
          size_t R,
          size_t C >
inline Matrix<T, R, C> &
Matrix<T, R, C>::operator*=(const ValueType &rhs) {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] *= rhs;
  }
  return *this;
}
template< typename T,
          size_t R,
          size_t C >
inline Matrix<T, R, C> &
Matrix<T, R, C>::operator-=(const ValueType &rhs) {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] -= rhs;
  }
  return *this;
}

template< typename T,
          size_t R,
          size_t C >
template< typename U >
inline auto Matrix<T, R, C>::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Matrix<T, R, C>, U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] = rhs.derived()[i];
  }
}

template< typename T,
          size_t R,
          size_t C >
template< typename U >
inline auto Matrix<T, R, C>::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Matrix<T, R, C>, U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] += rhs.derived()[i];
  }
}
template< typename T,
          size_t R,
          size_t C >
template< typename U >
inline auto Matrix<T, R, C>::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_scalar<U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] *= rhs.derived()[0];
  }
}
template< typename T,
          size_t R,
          size_t C >
template< typename U >
inline auto Matrix<T, R, C>::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Matrix<T, R, C>, U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] -= rhs.derived()[i];
  }
}

} // sym

#endif // SYMMATH_MATRIX_MATRIX_HPP
