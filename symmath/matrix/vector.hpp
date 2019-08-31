#ifndef SYMMATH_VECTOR_VECTOR_HPP
#define SYMMATH_VECTOR_VECTOR_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "storage.hpp"
#include "../type_traits/is_applicable.hpp"
#include "../type_traits/is_scalar.hpp"
#include "../type_traits/is_storage_object.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t L >
class Vector
  : public Symbolic<Vector<T, L>>,
    public Storage<T, L> {
public:

  using ValueType = typename Storage<T, L>::ValueType;

  using ArrayType = typename Storage<T, L>::ArrayType;
  using VectorType = typename Storage<T, L>::VectorType;

  using ResultType = Vector<T, L>;

private:

public:

  using Storage<T, L>::Storage;
  using Storage<T, L>::operator=;

  // explicit inline Vector();
  // inline Vector(const ArrayType &other);
  // inline Vector(const VectorType &other);
  // inline Vector(std::initializer_list<T> init);
  //
  // template< typename U >
  // inline Vector(const Vector<U, L> &other);
  //
  // inline Vector<T, L> &operator=(const ArrayType &other);
  // inline Vector<T, L> &operator=(const VectorType &other);
  // inline Vector<T, L> &operator=(std::initializer_list<T> init);
  //
  // template< typename U >
  // inline Vector<T, L> &operator=(const Vector<U, L> &other);

  inline auto eval() const -> const ResultType;

  inline size_t rows() const;
  inline size_t cols() const;

  inline T &operator()(const size_t row, const size_t col);
  inline const T &operator()(const size_t row, const size_t col) const;

  template< typename U >
  inline Vector<T, L> &operator=(const Symbolic<U> &rhs);

  template< typename U >
  inline auto apply(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Vector<T, L>, U>{}>;

  template< typename U >
  inline auto apply_add(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Vector<T, L>, U>{}>;
  template< typename U >
  inline auto apply_mul(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_scalar_t<U>{}>;
  template< typename U >
  inline auto apply_sub(const Symbolic<U> &rhs)
  -> std::enable_if_t<is_applicable<Vector<T, L>, U>{}>;

};

// -----------------------------------------------------------------------------
// Constructor
// template< typename T,
//           size_t L >
// inline
// Vector<T, L>::Vector()
//   : Storage<T, L>() {}
//
// template< typename T,
//           size_t L >
// inline
// Vector<T, L>::Vector(const ArrayType &other)
//   : Storage<T, L>(other) {}
//
// template< typename T,
//           size_t L >
// inline
// Vector<T, L>::Vector(const VectorType &other)
//   : Storage<T, L>(other) {}
//
// template< typename T,
//           size_t L >
// inline
// Vector<T, L>::Vector(std::initializer_list<T> init)
//   : Storage<T, L>(init) {}
//
// template< typename T,
//           size_t L >
// template< typename U >
// inline
// Vector<T, L>::Vector(const Vector<U, L> &other)
//   : Storage<T, L>(other) {}
//
// template< typename T,
//           size_t L >
// inline Vector<T, L> &
// Vector<T, L>::operator=(const ArrayType &other) {
//   std::copy(other.begin(), other.end(), this->begin());
//   return *this;
// }
//
// template< typename T,
//           size_t L >
// inline Vector<T, L> &
// Vector<T, L>::operator=(const VectorType &other) {
//   static_assert(other.size() == L, "Bad dimensions.");
//   std::copy(other.begin(), other.end(), this->begin());
//   return *this;
// }
//
// template< typename T,
//           size_t L >
// inline Vector<T, L> &
// Vector<T, L>::operator=(std::initializer_list<T> init) {
//   static_assert(init.size() == L, "Bad dimensions.");
//   std::copy(init.begin(), init.end(), this->begin());
//   return *this;
// }
//
// template< typename T,
//           size_t L >
// template< typename U >
// inline Vector<T, L> &
// Vector<T, L>::operator=(const Vector<U, L> &other) {
//   std::copy(other.begin(), other.end(), this->begin());
//   return *this;
// }

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T,
          size_t L >
inline auto
Vector<T, L>::eval() const
-> const ResultType {
  return *this;
}

template< typename T,
          size_t L >
inline size_t Vector<T, L>::rows() const {
  return L;
}

template< typename T,
          size_t L >
inline size_t Vector<T, L>::cols() const {
  return 1;
}

template< typename T,
          size_t L >
inline T &
Vector<T, L>::operator()(const size_t row, const size_t col) {
  return (*this)[row*1 + col];
}

template< typename T,
          size_t L >
inline const T &
Vector<T, L>::operator()(const size_t row, const size_t col) const {
  return (*this)[row*1 + col];
}

template< typename T,
          size_t L >
template< typename U >
inline Vector<T, L> &
Vector<T, L>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T,
          size_t L >
template< typename U >
inline auto Vector<T, L>::apply(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Vector<T, L>, U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] = rhs.derived()[i];
  }
}

template< typename T,
          size_t L >
template< typename U >
inline auto Vector<T, L>::apply_add(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Vector<T, L>, U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] += rhs.derived()[i];
  }
}
template< typename T,
          size_t L >
template< typename U >
inline auto Vector<T, L>::apply_mul(const Symbolic<U> &rhs)
-> std::enable_if_t<is_scalar_t<U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] *= rhs.derived()[0];
  }
}
template< typename T,
          size_t L >
template< typename U >
inline auto Vector<T, L>::apply_sub(const Symbolic<U> &rhs)
-> std::enable_if_t<is_applicable<Vector<T, L>, U>{}> {
  for(size_t i = 0; i < this->size(); i++) {
    (*this)[i] -= rhs.derived()[i];
  }
}

} // sym

#endif // SYMMATH_VECTOR_VECTOR_HPP
