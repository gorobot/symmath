#ifndef SYMMATH_SYMBOLIC_HPP
#define SYMMATH_SYMBOLIC_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Symbolic {

  inline T &derived() {
    return static_cast<T &>(*this);
  }

  inline const T &derived() const {
    return static_cast<const T &>(*this);
  }

};

} // sym

#endif // SYMMATH_SYMBOLIC_HPP
