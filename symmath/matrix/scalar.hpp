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
    public Storage<T, 1> {
public:

  using ValueType = typename Storage<T, 1>::ValueType;

  using ArrayType = typename Storage<T, 1>::ArrayType;
  using VectorType = typename Storage<T, 1>::VectorType;

  using ResultType = T;

private:

public:

  using Storage<T, 1>::Storage;
  using Storage<T, 1>::operator=;

  // explicit inline Scalar();
  // inline Scalar(const ValueType &other);
  // inline Scalar(ValueType &&other);
  // inline Scalar(const ArrayType &other);
  // inline Scalar(const VectorType &other);
  // inline Scalar(std::initializer_list<T> init);
  //
  // template< typename U >
  // inline Scalar(const Scalar<U> &other);
  //
  // inline Scalar<T> &operator=(const ValueType &other);
  // inline Scalar<T> &operator=(ValueType &&other);
  // inline Scalar<T> &operator=(const ArrayType &other);
  // inline Scalar<T> &operator=(const VectorType &other);
  // inline Scalar<T> &operator=(std::initializer_list<T> init);
  //
  // template< typename U >
  // inline Scalar<T> &operator=(const Scalar<U> &other);

  inline operator ValueType() const;

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

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
// template< typename T >
// Scalar<T>::Scalar()
//   : Storage<T, 1>() {}
//
// template< typename T >
// Scalar<T>::Scalar(const ValueType &other)
//   : Storage<T, 1>(other) {}
//
// template< typename T >
// Scalar<T>::Scalar(ValueType &&other)
//   : Storage<T, 1>(std::move(other)) {}
//
// template< typename T >
// inline
// Scalar<T>::Scalar(const ArrayType &other)
//   : Storage<T, 1>(other) {}
//
// template< typename T >
// inline
// Scalar<T>::Scalar(const VectorType &other)
//   : Storage<T, 1>(other) {}
//
// template< typename T >
// inline
// Scalar<T>::Scalar(std::initializer_list<T> init)
//   : Storage<T, 1>(init) {}
//
// template< typename T >
// template< typename U >
// inline
// Scalar<T>::Scalar(const Scalar<U> &other)
//   : Storage<T, 1>(other) {}
//
// template< typename T >
// inline Scalar<T> &
// Scalar<T>::operator=(const ValueType &other) {
//   return *this;
// }
// template< typename T >
// inline Scalar<T> &
// Scalar<T>::operator=(ValueType &&other) {
//   return *this;
// }
// template< typename T >
// inline Scalar<T> &
// Scalar<T>::operator=(const ArrayType &other) {
//   return *this;
// }
// template< typename T >
// inline Scalar<T> &
// Scalar<T>::operator=(const VectorType &other) {
//   return *this;
// }
// template< typename T >
// inline Scalar<T> &
// Scalar<T>::operator=(std::initializer_list<T> init) {
//   return *this;
// }
//
// template< typename U >
// inline Scalar<T> &operator=(const Scalar<U> &other);

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
  return (*this)[0];
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
