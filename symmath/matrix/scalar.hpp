#ifndef SYMMATH_SCALAR_SCALAR_HPP
#define SYMMATH_SCALAR_SCALAR_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "storage.hpp"
#include "../type_traits/is_applicable.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Scalar
  : public Symbolic<Scalar<T>>,
    public Storage<T, 1> {
public:

  using ValueType = typename Storage<T, 1>::ValueType;

  using ArrayType = typename Storage<T, 1>::ArrayType;
  using VectorType = typename Storage<T, 1>::VectorType;

  using ResultType = Scalar<T>;

private:

public:

  using Storage<T, 1>::Storage;
  using Storage<T, 1>::operator=;

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline Scalar<T> &operator=(const Symbolic<U> &rhs);

  inline Scalar<T> &operator+=(const ValueType &rhs);
  inline Scalar<T> &operator/=(const ValueType &rhs);
  inline Scalar<T> &operator*=(const ValueType &rhs);
  inline Scalar<T> &operator-=(const ValueType &rhs);

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Scalar<T>, U>{}>;

  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Scalar<T>, U>{}>;
  template< typename U >
  inline auto apply_div(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Scalar<T>, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Scalar<T>, U>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Scalar<T>, U>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Scalar<T>::operator Scalar<T>::ValueType() const {
  return (*this)[0];
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline auto
Scalar<T>::eval() const
-> const ResultType {
  return *this;
}

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
  return (*this)[row*1 + col];
}

template< typename T >
inline const T &
Scalar<T>::operator()(const size_t row, const size_t col) const {
  return (*this)[row*1 + col];
}

template< typename T >
template< typename U >
inline Scalar<T> &
Scalar<T>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T >
inline Scalar<T> &
Scalar<T>::operator+=(const ValueType &rhs) {
  (*this)[0] += rhs;
  return *this;
}
template< typename T >
inline Scalar<T> &
Scalar<T>::operator/=(const ValueType &rhs) {
  (*this)[0] /= rhs;
  return *this;
}
template< typename T >
inline Scalar<T> &
Scalar<T>::operator*=(const ValueType &rhs) {
  (*this)[0] *= rhs;
  return *this;
}
template< typename T >
inline Scalar<T> &
Scalar<T>::operator-=(const ValueType &rhs) {
  (*this)[0] -= rhs;
  return *this;
}

template< typename T >
template< typename U >
inline auto Scalar<T>::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  (*this)[0] = rhs.derived()[0];
}

template< typename T >
template< typename U >
inline auto Scalar<T>::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  (*this)[0] += rhs.derived()[0];
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_div(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  (*this)[0] /= rhs.derived()[0];
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  (*this)[0] *= rhs.derived()[0];
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  (*this)[0] -= rhs.derived()[0];
}

} // sym

#endif // SYMMATH_SCALAR_SCALAR_HPP
