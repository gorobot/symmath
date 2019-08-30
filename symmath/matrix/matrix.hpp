#ifndef SYMMATH_MATRIX_MATRIX_HPP
#define SYMMATH_MATRIX_MATRIX_HPP

#include <vector>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Matrix
  : public Symbolic<Matrix<T>> {
public:

  using ResultType = T;

  using IteratorType = typename std::vector<T>::iterator;
  using ConstIteratorType = typename std::vector<T>::const_iterator;

private:

  size_t r_;
  size_t c_;

  std::vector<T> v_;

public:

  explicit inline Matrix();
  explicit inline Matrix(const size_t count);
  explicit inline Matrix(const std::vector<T> v);

  inline Matrix(const Matrix<T> &m);

  template<typename DT>
  inline Matrix(const Matrix<DT> &m);

  inline Matrix<T> &operator=(const T &rhs);
  inline Matrix<T> &operator=(std::initializer_list<T> rhs);
  inline Matrix<T> &operator=(std::initializer_list<std::initializer_list<T>> rhs);
  inline Matrix<T> &operator=(const std::vector<T> rhs);
  inline Matrix<T> &operator=(const Matrix<T> &rhs);

  inline size_t size() const;
  inline size_t capacity() const;

  inline bool empty() const;

  inline IteratorType begin();
  inline IteratorType end();
  inline ConstIteratorType begin() const;
  inline ConstIteratorType end() const;
  inline ConstIteratorType cbegin() const;
  inline ConstIteratorType cend() const;

  inline size_t rows() const;
  inline size_t cols() const;

  inline std::vector<T> as_vec() const;

  inline T &operator[](const size_t pos);
  inline const T &operator[](const size_t pos) const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

};

// -----------------------------------------------------------------------------
// Constructor
template<typename T>
inline Matrix<T>::Matrix() :
                         r_(0),
                         c_(0) {
  v_ = std::vector<T>(0);
}

template<typename T>
inline Matrix<T>::Matrix(const size_t count) :
                         r_(count),
                         c_(1) {
  v_ = std::vector<T>(count, std::declval<T>());
}

template<typename T>
inline Matrix<T>::Matrix(const std::vector<T> v) :
                         r_(v.size()),
                         c_(1),
                         v_(v) {
  //
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T> &m) :
                         r_(m.r_),
                         c_(m.c_),
                         v_(m.v_) {
  //
}

template<typename T>
inline Matrix<T> &Matrix<T>::operator=(const T &rhs) {
  for(size_t i = 0; i < v_.size(); i++) {
    v_[i] = rhs;
  }

  return *this;
}

template<typename T>
inline Matrix<T> &Matrix<T>::operator=(std::initializer_list<T> rhs) {
  r_ = rhs.size();
  c_ = 1;
  v_.resize(r_*c_);
  std::copy(rhs.begin(), rhs.end(), v_.begin());

  return *this;
}

template<typename T>
inline Matrix<T> &Matrix<T>::operator=(const std::vector<T> rhs) {
  r_ = rhs.size();
  c_ = 1;
  v_.resize(r_*c_);
  v_ = rhs;

  return *this;
}

template<typename T>
inline Matrix<T> &Matrix<T>::operator=(const Matrix<T> &rhs) {
  r_ = rhs.r_;
  c_ = rhs.c_;
  v_ = rhs.v_;

  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template<typename T>
inline size_t Matrix<T>::size() const {
  return v_.size();
}

template<typename T>
inline size_t Matrix<T>::capacity() const {
  return v_.capacity();
}

template<typename T>
inline bool Matrix<T>::empty() const {
  return v_.empty();
}

template<typename T>
inline auto
Matrix<T>::begin()
-> typename Matrix<T>::IteratorType {
  return v_.begin();
}

template<typename T>
inline auto
Matrix<T>::end()
-> typename Matrix<T>::IteratorType {
  return v_.begin();
}

template<typename T>
inline auto
Matrix<T>::begin() const
-> typename Matrix<T>::ConstIteratorType {
  return v_.begin();
}

template<typename T>
inline auto
Matrix<T>::end() const
-> typename Matrix<T>::ConstIteratorType {
  return v_.begin();
}

template<typename T>
inline auto
Matrix<T>::cbegin() const
-> typename Matrix<T>::ConstIteratorType {
  return v_.begin();
}

template<typename T>
inline auto
Matrix<T>::cend() const
-> typename Matrix<T>::ConstIteratorType {
  return v_.begin();
}

template<typename T>
inline size_t Matrix<T>::rows() const {
  return r_;
}

template<typename T>
inline size_t Matrix<T>::cols() const {
  return c_;
}

template<typename T>
inline std::vector<T> Matrix<T>::as_vec() const {
  return v_;
}

template<typename T>
inline T &Matrix<T>::operator[](const size_t pos) {
  return v_[pos];
}

template<typename T>
inline const T &Matrix<T>::operator[](const size_t pos) const {
  return v_[pos];
}

template<typename T>
inline T &Matrix<T>::operator()(const size_t row,
                                const size_t col) {
  return v_[row*c_ + col];
}

template<typename T>
inline const T &Matrix<T>::operator()(const size_t row,
                                      const size_t col) const {
  return v_[row*c_ + col];
}

} // sym

#endif // SYMMATH_MATRIX_MATRIX_HPP
