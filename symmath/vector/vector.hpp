#ifndef SYMMATH_VECTOR_VECTOR_HPP
#define SYMMATH_VECTOR_VECTOR_HPP

#include <vector>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Vector
  : public Symbolic<Vector<T>> {
public:

  using ResultType = T;

  using IteratorType = typename std::vector<T>::iterator;
  using ConstIteratorType = typename std::vector<T>::const_iterator;

private:

  size_t r_;
  size_t c_;

  std::vector<T> v_;

public:

  explicit inline Vector();
  explicit inline Vector(const size_t count);
  explicit inline Vector(const std::vector<T> v);

  inline Vector(const Vector<T> &m);

  template<typename DT>
  inline Vector(const Matrix<DT> &m);

  inline Vector<T> &operator=(const T &rhs);
  inline Vector<T> &operator=(std::initializer_list<T> rhs);
  inline Vector<T> &operator=(const std::vector<T> rhs);
  inline Vector<T> &operator=(const Vector<T> &rhs);

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
inline Vector<T>::Vector() :
                         r_(0),
                         c_(0) {
  v_ = std::vector<T>(0);
}

template<typename T>
inline Vector<T>::Vector(const size_t count) :
                         r_(count),
                         c_(1) {
  v_ = std::vector<T>(count, declval<T>());
}

template<typename T>
inline Vector<T>::Vector(const std::vector<T> v) :
                         r_(v.size()),
                         c_(1),
                         v_(v) {
  //
}

template<typename T>
inline Vector<T>::Vector(const Vector<T> &m) :
                         r_(m.r_),
                         c_(m.c_),
                         v_(m.v_) {
  //
}

template<typename T>
inline Vector<T> &Vector<T>::operator=(const T &rhs) {
  for(size_t i = 0; i < v_.size(); i++) {
    v_[i] = rhs;
  }

  return *this;
}

template<typename T>
inline Vector<T> &Vector<T>::operator=(std::initializer_list<T> rhs) {
  r_ = rhs.size();
  c_ = 1;
  v_.resize(r_*c_);
  std::copy(rhs.begin(), rhs.end(), v_.begin());

  return *this;
}

template<typename T>
inline Vector<T> &Vector<T>::operator=(const std::vector<T> rhs) {
  r_ = rhs.size();
  c_ = 1;
  v_.resize(r_*c_);
  v_ = rhs;

  return *this;
}

template<typename T>
inline Vector<T> &Vector<T>::operator=(const Vector<T> &rhs) {
  r_ = rhs.r_;
  c_ = rhs.c_;
  v_ = rhs.v_;

  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template<typename T>
inline size_t Vector<T>::size() const {
  return v_.size();
}

template<typename T>
inline size_t Vector<T>::capacity() const {
  return v_.capacity();
}

template<typename T>
inline bool Vector<T>::empty() const {
  return v_.empty();
}

template<typename T>
inline Vector<T>::IteratorType
Vector<T>::begin() {
  return v_.begin();
}

template<typename T>
inline Vector<T>::IteratorType
Vector<T>::end() {
  return v_.begin();
}

template<typename T>
inline Vector<T>::ConstIteratorType
Vector<T>::begin() const {
  return v_.begin();
}

template<typename T>
inline Vector<T>::ConstIteratorType
Vector<T>::end() const {
  return v_.begin();
}

template<typename T>
inline Vector<T>::ConstIteratorType
Vector<T>::cbegin() const {
  return v_.begin();
}

template<typename T>
inline Vector<T>::ConstIteratorType
Vector<T>::cend() const {
  return v_.begin();
}

template<typename T>
inline size_t Vector<T>::rows() const {
  return r_;
}

template<typename T>
inline size_t Vector<T>::cols() const {
  return c_;
}

template<typename T>
inline std::vector<T> Vector<T>::as_vec() const {
  return v_;
}

template<typename T>
inline T &Vector<T>::operator[](const size_t pos) {
  return v_[pos];
}

template<typename T>
inline const T &Vector<T>::operator[](const size_t pos) const {
  return v_[pos];
}

template<typename T>
inline T &Vector<T>::operator()(const size_t row,
                                const size_t col) {
  return v_[row*c_ + col];
}

template<typename T>
inline const T &Vector<T>::operator()(const size_t row,
                                      const size_t col) const {
  return v_[row*c_ + col];
}

} // sym

#endif // SYMMATH_VECTOR_VECTOR_HPP
