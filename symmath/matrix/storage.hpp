#ifndef SYMMATH_MATRIX_STORAGE_HPP
#define SYMMATH_MATRIX_STORAGE_HPP

#include <algorithm>
#include <array>
#include <vector>

#include "../type_traits/product.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t ...D >
class Storage {
public:

  using ValueType = T;

  using ArrayType = std::array<T, product<D...>::value>;
  using VectorType = std::vector<T>;

  using IteratorType = typename ArrayType::iterator;
  using ConstIteratorType = typename ArrayType::const_iterator;

protected:

  ArrayType value_;

public:

  explicit inline Storage();
  inline Storage(const ValueType &other);
  inline Storage(ValueType &&other);
  inline Storage(const ArrayType &other);
  inline Storage(const VectorType &other);
  inline Storage(std::initializer_list<T> init);

  template< typename U >
  inline Storage(const Storage<U, D...> &other);

  inline Storage<T, D...> &operator=(const ValueType &other);
  inline Storage<T, D...> &operator=(ValueType &&other);
  inline Storage<T, D...> &operator=(const ArrayType &other);
  inline Storage<T, D...> &operator=(const VectorType &other);
  inline Storage<T, D...> &operator=(std::initializer_list<T> init);

  template< typename U >
  inline Storage<T, D...> &operator=(const Storage<U, D...> &other);

  inline size_t size() const;
  inline size_t capacity() const;

  inline bool empty() const;

  inline IteratorType begin();
  inline IteratorType end();
  inline ConstIteratorType begin() const;
  inline ConstIteratorType end() const;
  inline ConstIteratorType cbegin() const;
  inline ConstIteratorType cend() const;

  inline auto as_vec() const -> VectorType;

  inline T &operator[](const size_t pos);
  inline const T &operator[](const size_t pos) const;

  inline bool operator==(const Storage<T, D...> &rhs) const;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T,
          size_t ...D >
inline
Storage<T, D...>::Storage()
  : value_() {}

template< typename T,
          size_t ...D >
inline
Storage<T, D...>::Storage(const ValueType &other)
  : value_() {
  value_.fill(other);
}

template< typename T,
          size_t ...D >
inline
Storage<T, D...>::Storage(ValueType &&other)
  : value_() {
  value_.fill(std::move(other));
}

template< typename T,
          size_t ...D >
inline
Storage<T, D...>::Storage(const ArrayType &other)
  : value_() {
  std::copy(other.begin(), other.end(), value_.begin());
}

template< typename T,
          size_t ...D >
inline
Storage<T, D...>::Storage(const VectorType &other)
  : value_() {
  std::copy(other.begin(), other.end(), value_.begin());
}

template< typename T,
          size_t ...D >
inline
Storage<T, D...>::Storage(std::initializer_list<T> init)
  : value_() {
  std::copy(init.begin(), init.end(), value_.begin());
}

template< typename T,
          size_t ...D >
template< typename U >
inline
Storage<T, D...>::Storage(const Storage<U, D...> &other)
  : value_() {
  std::copy(other.begin(), other.end(), value_.begin());
}

template< typename T,
          size_t ...D >
inline Storage<T, D...> &
Storage<T, D...>::operator=(const ValueType &other) {
  value_.fill(other);
  return *this;
}
template< typename T,
          size_t ...D >
inline Storage<T, D...> &
Storage<T, D...>::operator=(ValueType &&other) {
  value_.fill(std::move(other));
  return *this;
}

template< typename T,
          size_t ...D >
inline Storage<T, D...> &
Storage<T, D...>::operator=(const ArrayType &other) {
  std::copy(other.begin(), other.end(), value_.begin());
  return *this;
}

template< typename T,
          size_t ...D >
inline Storage<T, D...> &
Storage<T, D...>::operator=(const VectorType &other) {
  static_assert(other.size() == product<D...>::value, "Bad dimensions.");
  std::copy(other.begin(), other.end(), value_.begin());
  return *this;
}

template< typename T,
          size_t ...D >
inline Storage<T, D...> &
Storage<T, D...>::operator=(std::initializer_list<T> init) {
  static_assert(init.size() == product<D...>::value, "Bad dimensions.");
  std::copy(init.begin(), init.end(), value_.begin());
  return *this;
}

template< typename T,
          size_t ...D >
template< typename U >
inline Storage<T, D...> &
Storage<T, D...>::operator=(const Storage<U, D...> &other) {
  std::copy(other.begin(), other.end(), value_.begin());
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T,
          size_t ...D >
inline size_t
Storage<T, D...>::size() const {
  return value_.size();
}

template< typename T,
          size_t ...D >
inline size_t
Storage<T, D...>::capacity() const {
  return value_.capacity();
}

template< typename T,
          size_t ...D >
inline bool
Storage<T, D...>::empty() const {
  return value_.empty();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::begin()
-> typename Storage<T, D...>::IteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::end()
-> typename Storage<T, D...>::IteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::begin() const
-> typename Storage<T, D...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::end() const
-> typename Storage<T, D...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::cbegin() const
-> typename Storage<T, D...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::cend() const
-> typename Storage<T, D...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...D >
inline auto
Storage<T, D...>::as_vec() const
-> VectorType {
  return value_;
}

template< typename T,
          size_t ...D >
inline T &
Storage<T, D...>::operator[](const size_t pos) {
  return value_[pos];
}

template< typename T,
          size_t ...D >
inline const T &
Storage<T, D...>::operator[](const size_t pos) const {
  return value_[pos];
}

template< typename T,
          size_t ...D >
inline bool
Storage<T, D...>::operator==(const Storage<T, D...> &rhs) const {
  for(size_t i = 0; i < this->size(); i++) {
    if((*this)[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

} // sym

#endif // SYMMATH_MATRIX_STORAGE_HPP
