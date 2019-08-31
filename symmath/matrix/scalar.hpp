#ifndef SYMMATH_SCALAR_SCALAR_HPP
#define SYMMATH_SCALAR_SCALAR_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "storage.hpp"
#include "../type_traits/is_applicable.hpp"
#include "../type_traits/is_storage_object.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Scalar
  : public Symbolic<Scalar<T>>,
    public Storage<T> {
public:

  using ValueType = T;
  using VectorType = typename Storage<T>::VectorType;

  using ResultType = Scalar<T>;

private:

  static constexpr size_t r_ = 1;
  static constexpr size_t c_ = 1;

public:

  explicit inline Scalar();
  inline Scalar(const ValueType v);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t R, const size_t C);
  inline const T &operator()(const size_t R, const size_t C) const;

  template< typename U >
  inline Scalar<T> &operator=(const Symbolic<U> &rhs);

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
Scalar<T>::Scalar()
  : Storage<T>() {}

template< typename T >
Scalar<T>::Scalar(const ValueType v)
  : Storage<T>{v} {}

template< typename T >
inline Scalar<T>::operator Scalar<T>::ValueType() const {
  return this->value_[0];
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
  return r_;
}

template< typename T >
inline size_t Scalar<T>::cols() const {
  return c_;
}

template< typename T >
inline T &
Scalar<T>::operator()(const size_t R, const size_t C) {
  return this->value_[R*c_ + C];
}

template< typename T >
inline const T &
Scalar<T>::operator()(const size_t R, const size_t C) const {
  return this->value_[R*c_ + C];
}

template< typename T >
template< typename U >
inline Scalar<T> &
Scalar<T>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T >
template< typename U >
inline auto Scalar<T>::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  this->value_[0] = rhs.derived().eval();
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  this->value_[0] += rhs.derived().eval();
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_div(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  this->value_[0] /= rhs.derived().eval();
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  this->value_[0] *= rhs.derived().eval();
}
template< typename T >
template< typename U >
inline auto Scalar<T>::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Scalar<T>, U>{}> {
  this->value_[0] -= rhs.derived().eval();
}

} // sym

#endif // SYMMATH_SCALAR_SCALAR_HPP
