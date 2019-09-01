#ifndef SYMMATH_PROPERTIES_HAS_ADD_HPP
#define SYMMATH_PROPERTIES_HAS_ADD_HPP

#include <type_traits>

// #include "../operation/add.hpp"
#include "property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Add;

template< typename T >
struct has_add
  : private Property {

  inline has_add<T> &operator=(const Add<T, T> &other);

  inline void assign_add(const T &rhs);

};

// -----------------------------------------------------------------------------

template< typename T >
inline void
assign_add_(has_add<T> &lhs, const has_add<T> &rhs) {
  static_cast<T &>(lhs).assign_add(static_cast<const T &>(rhs));
}

template< typename T >
inline void
assign_add_(has_add<T> &lhs, const typename T::ValueType &rhs) {
  static_cast<T &>(lhs).assign_add(rhs);
}

template< typename T >
inline has_add<T> &
has_add<T>::operator=(const Add<T, T> &other) {
  assign_(*this, other);
  return *this;
}

template< typename T >
inline void
has_add<T>::assign_add(const T &rhs) {
  static_cast<T &>(*this).assign_add(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
class Add {
public:

private:

  T1 lhs_;
  T2 rhs_;

public:

  Add(const has_add<T1> &lhs, const has_add<T2> &rhs);

private:

  template< typename U >
  friend void
  assign_(has_add<U> &lhs, const Add<T1, T2> &rhs) {
    assign_(static_cast<U &>(lhs), rhs.lhs_);
    assign_add_(static_cast<U &>(lhs), rhs.rhs_);
  }
};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
Add<T1, T2>::Add(const has_add<T1> &lhs, const has_add<T2> &rhs)
  : lhs_(static_cast<const T1 &>(lhs)),
    rhs_(static_cast<const T2 &>(rhs)) {}

// -----------------------------------------------------------------------------

template< typename T >
inline auto
operator+(const has_add<T> &lhs, const has_add<T> &rhs)
-> const Add<T, T> {
  return Add<T, T>(static_cast<const T &>(lhs), static_cast<const T &>(rhs));
}

template< typename T >
inline auto
operator+(const has_add<T> &lhs, const typename T::ValueType &rhs)
-> const Add<T, T> {
  const T tmp(rhs);
  return Add<T, T>(static_cast<const T &>(lhs), tmp);
}

template< typename T >
inline auto
operator+(const typename T::ValueType &lhs, const has_add<T> &rhs)
-> const Add<T, T> {
  const T tmp(lhs);
  return Add<T, T>(tmp, static_cast<const T &>(rhs));
}

template< typename T >
inline auto
operator+=(has_add<T> &lhs, const has_add<T> &rhs)
-> has_add<T> & {
  assign_add_(static_cast<T &>(lhs), static_cast<const T &>(rhs));
  return lhs;
}

template< typename T >
inline auto
operator+=(has_add<T> &lhs, const typename T::ValueType &rhs)
-> has_add<T> & {
  assign_add_(static_cast<T &>(lhs), rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ADD_HPP
