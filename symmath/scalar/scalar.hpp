#ifndef SYMMATH_SCALAR_SCALAR_HPP
#define SYMMATH_SCALAR_SCALAR_HPP

#include <type_traits>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Scalar
  : public Symbolic<Scalar<T>> {
public:

  using ResultType = T;

private:

  static constexpr size_t r_ = 1;
  static constexpr size_t c_ = 1;

  T v_;

public:

  explicit inline Scalar();
  inline Scalar(const T v);

  template< typename U >
  inline Scalar<T> &operator=(const Symbolic<U> &rhs);

  inline size_t size() const;
  inline size_t capacity() const;

  inline bool empty() const;

  inline size_t rows() const;
  inline size_t cols() const;

  inline std::vector<T> as_vec() const;

  inline T &operator[](const size_t pos);
  inline const T &operator[](const size_t pos) const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline void apply(const Scalar<U> &rhs);
  template< typename U >
  inline void apply_add(const Scalar<U> &rhs);
  template< typename U >
  inline void apply_div(const Scalar<U> &rhs);
  template< typename U >
  inline void apply_mul(const Scalar<U> &rhs);
  template< typename U >
  inline void apply_sub(const Scalar<U> &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
Scalar<T>::Scalar()
  : v_(0) {}

template< typename T >
Scalar<T>::Scalar(const T v)
  : v_(v) {}

template< typename T >
template< typename U >
inline Scalar<T> &
Scalar<T>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
template< typename U >
inline void
Scalar<T>::apply(const Scalar<U> &rhs) {
  v_ = rhs.v_;
}
template< typename T >
template< typename U >
inline void
Scalar<T>::apply_add(const Scalar<U> &rhs) {
  v_ += rhs.v_;
}
template< typename T >
template< typename U >
inline void
Scalar<T>::apply_div(const Scalar<U> &rhs) {
  v_ /= rhs.v_;
}
template< typename T >
template< typename U >
inline void
Scalar<T>::apply_mul(const Scalar<U> &rhs) {
  v_ *= rhs.v_;
}
template< typename T >
template< typename U >
inline void
Scalar<T>::apply_sub(const Scalar<U> &rhs) {
  v_ -= rhs.v_;
}

} // sym

#endif // SYMMATH_SCALAR_SCALAR_HPP
