#ifndef SYMMATH_DUMMY_HPP
#define SYMMATH_DUMMY_HPP

#include <iostream>

#include "is_.hpp"
#include "ring.hpp"
#include "has_value.hpp"
#include "has_properties.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Foo
  : public has_value<double>,
    public has_properties<Foo, has_assign, has_add, has_mul> {
public:

  using has_value<double>::has_value;
  using has_value<double>::operator=;
  // using Ring<Foo>::operator=;
  // using has_property<Foo,
  //   has_assign,
  //   has_add,
  //   has_mul>
  //   ::operator=;
  using has_assign<Foo>::operator=;
  using has_add<Foo>::operator=;
  using has_mul<Foo>::operator=;

  inline Foo &operator=(const Foo &other);

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_mul(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename U >
inline void
Foo::assign(const U &rhs) {
  this->value_ = rhs.value_;
}

template< typename U >
inline void
Foo::assign_add(const U &rhs) {
  this->value_ += rhs.value_;
}

template<>
inline void
Foo::assign_add<typename Foo::ValueType>(const typename Foo::ValueType &rhs) {
  this->value_ += rhs;
}

template< typename U >
inline void
Foo::assign_mul(const U &rhs) {
  this->value_ *= rhs.value_;
}

template<>
inline void
Foo::assign_mul<typename Foo::ValueType>(const typename Foo::ValueType &rhs) {
  this->value_ *= rhs;
}

// -----------------------------------------------------------------------------

class Bar
  : public has_value<double>,
    public Ring<Bar> {
public:

  using has_value<double>::has_value;
  using has_value<double>::operator=;
  using Ring<Bar>::operator=;

  template< typename U >
  inline void assign(const U &rhs);
  template< typename U >
  inline void assign_add(const U &rhs);
  template< typename U >
  inline void assign_mul(const U &rhs);

};

// -----------------------------------------------------------------------------

template< typename U >
inline void
Bar::assign(const U &rhs) {
  this->value_ = rhs.value_;
}

template< typename U >
inline void
Bar::assign_add(const U &rhs) {
  this->value_ += rhs.value_;
}

template<>
inline void
Bar::assign_add<typename Bar::ValueType>(const typename Bar::ValueType &rhs) {
  this->value_ += rhs;
}

template< typename U >
inline void
Bar::assign_mul(const U &rhs) {
  this->value_ *= rhs.value_;
}

template<>
inline void
Bar::assign_mul<typename Bar::ValueType>(const typename Bar::ValueType &rhs) {
  this->value_ *= rhs;
}

} // sym

#endif // SYMMATH_DUMMY_HPP
