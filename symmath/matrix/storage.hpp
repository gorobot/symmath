#ifndef SYMMATH_MATRIX_STORAGE_HPP
#define SYMMATH_MATRIX_STORAGE_HPP

#include <vector>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Storage {
public:

  using VectorType = std::vector<T>;

  using IteratorType = typename VectorType::iterator;
  using ConstIteratorType = typename VectorType::const_iterator;

protected:

  VectorType value_;

public:

  explicit inline Storage();
  explicit inline Storage(const size_t count);
  inline Storage(const VectorType &other);
  inline Storage(std::initializer_list<T> init);

  inline Storage(const Storage &other);

  inline Storage<T> &operator=(const Storage<T> &other);
  // inline Storage<T> &operator=(Storage<T> &&rhs);

  inline Storage<T> &operator=(const VectorType &other);
  // inline Storage<T> &operator=(VectorType &&rhs);
  inline Storage<T> &operator=(std::initializer_list<T> init);

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

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Storage<T>::Storage()
  : value_(VectorType(0)) {}

template< typename T >
inline Storage<T>::Storage(const size_t count)
  : value_(VectorType(count, std::declval<T>())) {}

template< typename T >
inline Storage<T>::Storage(const VectorType &other)
  : value_(other) {}

template< typename T >
inline Storage<T>::Storage(std::initializer_list<T> init)
  : value_(init) {}

template< typename T >
inline Storage<T>::Storage(const Storage &other)
  : value_(other.value_) {}

template< typename T >
inline Storage<T> &Storage<T>::operator=(const Storage<T> &other) {
  value_ = other.value_;
}
// template< typename T >
// inline Storage<T> &Storage<T>::operator=(Storage<T> &&rhs) {
//   value_ = std::move(rhs.value_);
// }

template< typename T >
inline Storage<T> &Storage<T>::operator=(const VectorType &other) {
  value_ = other;
}
// template< typename T >
// inline Storage<T> &Storage<T>::operator=(VectorType &&rhs) {
//   value_ = rhs;
// }
template< typename T >
inline Storage<T> &Storage<T>::operator=(std::initializer_list<T> init) {
  value_ = init;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template<typename T>
inline size_t Storage<T>::size() const {
  return value_.size();
}

template<typename T>
inline size_t Storage<T>::capacity() const {
  return value_.capacity();
}

template<typename T>
inline bool Storage<T>::empty() const {
  return value_.empty();
}

template<typename T>
inline auto
Storage<T>::begin()
-> typename Storage<T>::IteratorType {
  return value_.begin();
}

template<typename T>
inline auto
Storage<T>::end()
-> typename Storage<T>::IteratorType {
  return value_.begin();
}

template<typename T>
inline auto
Storage<T>::begin() const
-> typename Storage<T>::ConstIteratorType {
  return value_.begin();
}

template<typename T>
inline auto
Storage<T>::end() const
-> typename Storage<T>::ConstIteratorType {
  return value_.begin();
}

template<typename T>
inline auto
Storage<T>::cbegin() const
-> typename Storage<T>::ConstIteratorType {
  return value_.begin();
}

template<typename T>
inline auto
Storage<T>::cend() const
-> typename Storage<T>::ConstIteratorType {
  return value_.begin();
}

template<typename T>
inline auto Storage<T>::as_vec() const
-> VectorType {
  return value_;
}

template<typename T>
inline T &Storage<T>::operator[](const size_t pos) {
  return value_[pos];
}

template<typename T>
inline const T &Storage<T>::operator[](const size_t pos) const {
  return value_[pos];
}

} // sym

#endif // SYMMATH_MATRIX_STORAGE_HPP
