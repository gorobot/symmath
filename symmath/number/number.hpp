#ifndef SYMMATH_NUMBER_NUMBER_HPP
#define SYMMATH_NUMBER_NUMBER_HPP

#include <ostream>
#include <type_traits>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Number
  : public Symbolic<T> {
public:

protected:

public:

  template< typename U >
  inline Number<T> &operator=(const Symbolic<U> &rhs);

  template< typename U >
  inline void apply(const Number<U> &rhs);
  template< typename U >
  inline void apply_add(const Number<U> &rhs);
  template< typename U >
  inline void apply_mul(const Number<U> &rhs);

private:

  // template< typename U >
  // friend std::ostream& operator<<(std::ostream& os, const Number<U>& m);

};

// -----------------------------------------------------------------------------
// Member Function Definitions
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
  // (*this).derived().value_ = rhs.derived().value_;
  (*this).derived().apply(rhs);
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_add(const Number<U> &rhs) {
  // (*this).derived().value_ += rhs.derived().value_;
  (*this).derived().apply_add(rhs);
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_mul(const Number<U> &rhs) {
  // (*this).derived().value_ *= rhs.derived().value_;
  (*this).derived().apply_mul(rhs);
}

// template< typename T >
// std::ostream& operator<<(std::ostream& os, const Number<T>& m) {
//   return os << m.derived().value_;
// }

} // sym

#endif // SYMMATH_NUMBER_NUMBER_HPP
