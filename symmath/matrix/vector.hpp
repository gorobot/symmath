#ifndef SYMMATH_VECTOR_VECTOR_HPP
#define SYMMATH_VECTOR_VECTOR_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "storage.hpp"
#include "../type_traits/is_applicable.hpp"
#include "../type_traits/is_storage_object.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Vector
  : public Symbolic<Vector<T>>,
    public Storage<T> {
public:

  // using ValueType = typename T::ValueType;
  using VectorType = typename Storage<T>::VectorType;

  using ResultType = Vector<T>;

private:

  size_t r_;
  size_t c_;

public:

  explicit inline Vector();
  explicit inline Vector(const size_t count);
  inline Vector(const std::vector<T> &v);
  inline Vector(std::initializer_list<T> init);

  template< typename U >
  inline Vector(const Vector<U> &m);

  // template<typename DT>
  // inline Vector(const Vector<DT> &m);

  inline Vector<T> &operator=(const T &rhs);
  inline Vector<T> &operator=(std::initializer_list<T> init);
  inline Vector<T> &operator=(const std::vector<T> rhs);
  inline Vector<T> &operator=(const Vector<T> &rhs);

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline Vector<T> &operator=(const Symbolic<U> &rhs);

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_storage_object<U>{}>;

  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Vector<T>, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Vector<T>, U>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Vector<T>, U>{}>;

  template< typename U >
  inline bool operator==(const Symbolic<U> &rhs) const;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Vector<T>::Vector()
  : Storage<T>(),
    r_(0),
    c_(0) {}

template< typename T >
inline Vector<T>::Vector(const size_t count)
  : Storage<T>(count),
    r_(count),
    c_(1) {}

template< typename T >
inline Vector<T>::Vector(const std::vector<T> &other)
  : Storage<T>(other),
    r_(other.size()),
    c_(1) {}

template< typename T >
inline Vector<T>::Vector(std::initializer_list<T> init)
  : Storage<T>(init),
    r_(init.size()),
    c_(1) {}

template< typename T >
template< typename U >
inline Vector<T>::Vector(const Vector<U> &m)
  : Storage<T>(m.value_),
    r_(m.r_),
    c_(m.c_) {}

template< typename T >
inline Vector<T> &Vector<T>::operator=(const T &rhs) {
  for(size_t i = 0; i < this->value_.size(); i++) {
    this->value_[i] = rhs;
  }

  return *this;
}

template< typename T >
inline Vector<T> &Vector<T>::operator=(std::initializer_list<T> rhs) {
  r_ = rhs.size();
  c_ = 1;
  this->value_.resize(r_*c_);
  std::copy(rhs.begin(), rhs.end(), this->value_.begin());

  return *this;
}

template< typename T >
inline Vector<T> &Vector<T>::operator=(const std::vector<T> rhs) {
  r_ = rhs.size();
  c_ = 1;
  this->value_.resize(r_*c_);
  this->value_ = rhs;

  return *this;
}

template< typename T >
inline Vector<T> &Vector<T>::operator=(const Vector<T> &rhs) {
  r_ = rhs.r_;
  c_ = rhs.c_;
  this->value_ = rhs.value_;

  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline auto
Vector<T>::eval() const
-> const ResultType {
  return *this;
}

template< typename T >
inline size_t Vector<T>::rows() const {
  return r_;
}

template< typename T >
inline size_t Vector<T>::cols() const {
  return c_;
}

template< typename T >
inline T &
Vector<T>::operator()(const size_t R, const size_t C) {
  return this->value_[R*c_ + C];
}

template< typename T >
inline const T &
Vector<T>::operator()(const size_t R, const size_t C) const {
  return this->value_[R*c_ + C];
}

template< typename T>
template< typename U >
inline Vector<T> &
Vector<T>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T >
template< typename U >
inline auto Vector<T>::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_storage_object<U>{}> {
  this->r_ = rhs.derived().r_;
  this->c_ = rhs.derived().c_;
  this->value_ = rhs.derived().value_;
}

template< typename T >
template< typename U >
inline auto Vector<T>::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Vector<T>, U>{}> {
  // static_assert(r_ == rhs.derived().r_, "Inconsistent dimensions.");
  // static_assert(c_ == rhs.derived().c_, "Inconsistent dimensions.");
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] += rhs.derived()[i];
  }
  // this->value_[0] += rhs.derived().eval();
}
template< typename T >
template< typename U >
inline auto Vector<T>::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Vector<T>, U>{}> {
  // static_assert(r_ == rhs.derived().r_, "Inconsistent dimensions.");
  // static_assert(c_ == rhs.derived().c_, "Inconsistent dimensions.");
  for(size_t i = 0; i < this->size(); i++) {
    // (*this)[i] *= rhs.derived()[i];
  }
  // this->value_[0] *= rhs.derived().eval();
}
template< typename T >
template< typename U >
inline auto Vector<T>::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Vector<T>, U>{}> {
  // static_assert(r_ == rhs.derived().r_, "Inconsistent dimensions.");
  // static_assert(c_ == rhs.derived().c_, "Inconsistent dimensions.");
  for(size_t i = 0; i < this->size(); i++) {
    // (*this)[i] -= rhs.derived()[i];
  }
  // this->value_[0] -= rhs.derived().eval();
}

template< typename T >
template< typename U >
inline bool Vector<T>::operator==(const Symbolic<U> &rhs) const {
  if(this->r_ != rhs.derived().r_) {
    return false;
  }
  if(this->c_ != rhs.derived().c_) {
    return false;
  }
  for(size_t i = 0; i < this->size(); i++) {
    if((*this)[i] != rhs.derived()[i]) {
      return false;
    }
  }
  return true;
}

} // sym

#endif // SYMMATH_VECTOR_VECTOR_HPP
