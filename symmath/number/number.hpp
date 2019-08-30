#ifndef SYMMATH_NUMBER_NUMBER_HPP
#define SYMMATH_NUMBER_NUMBER_HPP

#include <type_traits>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Number
  : public Symbolic<Number<T>> {
public:

  using ResultType = T;

private:

  T v_;

public:

  explicit inline Number();
  inline Number(const T v);

  template< typename U >
  inline Number<T> &operator=(const Symbolic<U> &rhs);

  template< typename U >
  inline void apply(const Number<U> &rhs);
  template< typename U >
  inline void apply_add(const Number<U> &rhs);
  template< typename U >
  inline void apply_div(const Number<U> &rhs);
  template< typename U >
  inline void apply_mul(const Number<U> &rhs);
  template< typename U >
  inline void apply_sub(const Number<U> &rhs);

};

// -----------------------------------------------------------------------------
template< typename T >
Number<T>::Number()
  : v_(0) {}

template< typename T >
Number<T>::Number(const T v)
  : v_(v) {}

template< typename T >
template< typename U >
inline Number<T> &
Number<T>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T >
template< typename U >
inline void
Number<T>::apply(const Number<U> &rhs) {
  v_ = rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_add(const Number<U> &rhs) {
  v_ += rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_div(const Number<U> &rhs) {
  v_ /= rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_mul(const Number<U> &rhs) {
  v_ *= rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_sub(const Number<U> &rhs) {
  v_ -= rhs.v_;
}

} // sym

#endif // SYMMATH_NUMBER_NUMBER_HPP
