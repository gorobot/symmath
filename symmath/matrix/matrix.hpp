#ifndef SYMMATH_MATRIX_MATRIX_HPP
#define SYMMATH_MATRIX_MATRIX_HPP

#include <vector>

#include "../symbolic.hpp"
#include "storage.hpp"
#include "../type_traits/is_applicable.hpp"
#include "../type_traits/is_storage_object.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Matrix
  : public Symbolic<Matrix<T>>,
    public Storage<T> {
public:

  // using ValueType = typename T::ValueType;
  using VectorType = typename Storage<T>::VectorType;

  using ResultType = Matrix<T>;

private:

  size_t r_;
  size_t c_;

public:

  explicit inline Matrix();
  explicit inline Matrix(const size_t R, const size_t C);
  explicit inline Matrix(const size_t R, const size_t C, const VectorType &v);

  template<typename U>
  inline Matrix(const Matrix<U> &m);

  inline Matrix<T> &operator=(const T &rhs);
  inline Matrix<T> &operator=(std::initializer_list<std::initializer_list<T>> rhs);

  template< typename U >
  inline Matrix<T> &operator=(const Matrix<U> &rhs);

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t R, const size_t C);
  inline const T &operator()(const size_t R, const size_t C) const;

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T>, U>{}>;
  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T>, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T>, U>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Matrix<T>, U>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Matrix<T>::Matrix()
  : Storage<T>(),
    r_(0),
    c_(0) {}

template< typename T >
inline Matrix<T>::Matrix(const size_t R, const size_t C)
  : Storage<T>(R*C),
    r_(R),
    c_(C) {}

template< typename T >
inline Matrix<T>::Matrix(const size_t R, const size_t C, const VectorType &v)
  : Storage<T>(v),
    r_(R),
    c_(C) {
  // static_assert(R*C == v.size(), "Vector is of incorrect size.");
}

template< typename T >
template< typename U >
inline Matrix<T>::Matrix(const Matrix<U> &m)
  : Storage<T>(m.value_),
    r_(m.r_),
    c_(m.c_) {}

template< typename T >
inline Matrix<T> &Matrix<T>::operator=(const T &rhs) {
  for(size_t i = 0; i < this->value_.size(); i++) {
    this->value_[i] = rhs;
  }

  return *this;
}

template< typename T >
template< typename U >
inline Matrix<T> &Matrix<T>::operator=(const Matrix<U> &rhs) {
  r_ = rhs.r_;
  c_ = rhs.c_;
  this->value_ = rhs.value_;

  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline auto
Matrix<T>::eval() const
-> const ResultType {
  return *this;
}

template< typename T >
inline size_t Matrix<T>::rows() const {
  return r_;
}

template< typename T >
inline size_t Matrix<T>::cols() const {
  return c_;
}

template< typename T >
inline T &
Matrix<T>::operator()(const size_t R, const size_t C) {
  return this->value_[R*c_ + C];
}

template< typename T >
inline const T &
Matrix<T>::operator()(const size_t R, const size_t C) const {
  return this->value_[R*c_ + C];
}

} // sym

#endif // SYMMATH_MATRIX_MATRIX_HPP
