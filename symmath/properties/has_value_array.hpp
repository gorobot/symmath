#ifndef SYMMATH_PROPERTIES_HAS_VALUE_ARRAY_HPP
#define SYMMATH_PROPERTIES_HAS_VALUE_ARRAY_HPP

#include <algorithm>
#include <array>
#include <ostream>
#include <type_traits>

#include "property.hpp"
#include "../type_traits/product.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          size_t ...Dim >
class has_value_array
  : private Property {
public:

  using ValueType = typename T::ValueType;

  using VectorType = std::array<T, product<Dim...>::value>;

  using IteratorType = typename VectorType::iterator;
  using ConstIteratorType = typename VectorType::const_iterator;

  using ResultType = has_value_array<T, Dim...>;

protected:

  VectorType value_;

public:

  explicit inline has_value_array();
  explicit inline has_value_array(const VectorType &other);
  explicit inline has_value_array(std::initializer_list<T> init);
  explicit inline has_value_array(const ValueType &value);
  // inline has_value_array(ValueType &&value);

  inline has_value_array<T, Dim...> &operator=(const VectorType &other);
  inline has_value_array<T, Dim...> &operator=(std::initializer_list<T> init);
  inline has_value_array<T, Dim...> &operator=(const ValueType &value);
  // inline has_value_array<T, Dim...> &operator=(ValueType &&value);

  inline auto value() const -> const VectorType;

  inline size_t size() const;
  inline size_t capacity() const;

  inline bool empty() const;

  inline IteratorType begin();
  inline IteratorType end();
  inline ConstIteratorType begin() const;
  inline ConstIteratorType end() const;
  inline ConstIteratorType cbegin() const;
  inline ConstIteratorType cend() const;

  inline T &operator[](const size_t pos);
  inline const T &operator[](const size_t pos) const;

private:

  template< typename U,
            size_t ...Lengths >
  friend std::ostream &
  operator<<(std::ostream &os, const has_value_array<U, Lengths...> &m);

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T,
          size_t ...Dim >
inline
has_value_array<T, Dim...>::has_value_array()
  : value_() {}

template< typename T,
          size_t ...Dim >
inline
has_value_array<T, Dim...>::has_value_array(const VectorType &other)
  : value_() {
  std::copy(other.begin(), other.end(), value_.begin());
}

template< typename T,
          size_t ...Dim >
inline
has_value_array<T, Dim...>::has_value_array(std::initializer_list<T> init)
  : value_() {
  std::copy(init.begin(), init.end(), value_.begin());
}

template< typename T,
          size_t ...Dim >
inline
has_value_array<T, Dim...>::has_value_array(const ValueType &other)
  : value_() {
  for(size_t i = 0; i < product<Dim...>::value; i++) {
    value_[i] = other;
  }
}

// template< typename T,
//         size_t ...Dim >
// inline
// has_value_array<T, Dim...>::has_value_array(ValueType &&other)
//   : value_() {
//   value_.fill(std::move(other));
// }

template< typename T,
          size_t ...Dim >
inline has_value_array<T, Dim...> &
has_value_array<T, Dim...>::operator=(const VectorType &other) {
  std::copy(other.begin(), other.end(), value_.begin());
  return *this;
}

template< typename T,
          size_t ...Dim >
inline has_value_array<T, Dim...> &
has_value_array<T, Dim...>::operator=(std::initializer_list<T> init) {
  // static_assert(init.size() == product<Dim...>::value, "Bad dimensions.");
  std::copy(init.begin(), init.end(), value_.begin());
  return *this;
}

template< typename T,
          size_t ...Dim >
inline has_value_array<T, Dim...> &
has_value_array<T, Dim...>::operator=(const ValueType &other) {
  for(size_t i = 0; i < product<Dim...>::value; i++) {
    value_[i] = other;
  }
  return *this;
}

// template< typename T,
//           size_t ...Dim >
// inline has_value_array<T, Dim...> &
// has_value_array<T, Dim...>::operator=(ValueType &&other) {
//   value_.fill(std::move(other));
//   return *this;
// }

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::value() const
-> const VectorType {
  return value_;
}

template< typename T,
          size_t ...Dim >
inline size_t
has_value_array<T, Dim...>::size() const {
  return value_.size();
}

template< typename T,
          size_t ...Dim >
inline bool
has_value_array<T, Dim...>::empty() const {
  return value_.empty();
}

template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::begin()
-> typename has_value_array<T, Dim...>::IteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::end()
-> typename has_value_array<T, Dim...>::IteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::begin() const
-> typename has_value_array<T, Dim...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::end() const
-> typename has_value_array<T, Dim...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::cbegin() const
-> typename has_value_array<T, Dim...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...Dim >
inline auto
has_value_array<T, Dim...>::cend() const
-> typename has_value_array<T, Dim...>::ConstIteratorType {
  return value_.begin();
}

template< typename T,
          size_t ...Dim >
inline T &
has_value_array<T, Dim...>::operator[](const size_t pos) {
  return value_[pos];
}

template< typename T,
          size_t ...Dim >
inline const T &
has_value_array<T, Dim...>::operator[](const size_t pos) const {
  return value_[pos];
}

// -----------------------------------------------------------------------------

template< typename T,
          size_t ...Dim >
std::ostream &
operator<<(std::ostream &os, const has_value_array<T, Dim...> &m) {
  os << "{";
  for(size_t i = 0; i < product<Dim...>::value; i++) {
    os << m.value_[i];
    if(i < m.value_.size() - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2,
          size_t ...Dim >
inline bool
operator==( const has_value_array<T1, Dim...> &lhs,
            const has_value_array<T2, Dim...> &rhs ) {
  for(size_t i = 0; i < product<Dim...>::value; i++) {
    if(!(lhs[i] == rhs[i])) {
      return false;
    }
  }
  return true;
}

template< typename T1,
          typename T2,
          size_t ...Dim >
inline bool
operator!=( const has_value_array<T1, Dim...> &lhs,
            const has_value_array<T2, Dim...> &rhs ) {
  for(size_t i = 0; i < product<Dim...>::value; i++) {
    if(lhs[i] == rhs[i]) {
      return false;
    }
  }
  return true;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_VALUE_ARRAY_HPP
