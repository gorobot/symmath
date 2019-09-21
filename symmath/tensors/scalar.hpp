#ifndef SYMMATH_TENSORS_SCALAR_HPP
#define SYMMATH_TENSORS_SCALAR_HPP

#include <initializer_list>

#include <symmath/tensors/tensor.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using Scalar = Tensor<T, 0, 0>;

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 0, 0> {
public:

  using This = Scalar<T>;

  using ElementOf = typename T::ElementOf;

  using ValueType = T;
  using ArrayType = ValueType;

private:

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();
  explicit inline Tensor(const ValueType &value);
  explicit inline Tensor(ValueType &&value);

  template< typename U >  explicit inline Tensor(const Scalar<U> &other);
  template< typename U >  explicit inline Tensor(Scalar<U> &&other);

  // Assignment Operator
  inline This &operator=(const ValueType &value);
  inline This &operator=(ValueType &&value);

  template< typename U >  inline This &operator=(const Scalar<U> &other);
  template< typename U >  inline This &operator=(Scalar<U> &&other);

  inline auto operator()() -> ValueType &;
  inline auto operator()() const -> const ValueType &;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Scalar<T>::Tensor()
  : value_() {}

template< typename T >
inline Scalar<T>::Tensor(const ValueType &value)
  : value_(value) {}

template< typename T >
inline Scalar<T>::Tensor(ValueType &&value)
  : value_(std::move(value)) {}

// -----------------------------------------------------------------------------
// Assignment Operator
template< typename T >
inline Scalar<T> &Scalar<T>::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

template< typename T >
inline Scalar<T> &Scalar<T>::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline auto Scalar<T>::operator()() -> ValueType & {
  return value_;
}
template< typename T >
inline auto Scalar<T>::operator()() const -> const ValueType & {
  return value_;
}

} // sym

#endif // SYMMATH_TENSORS_SCALAR_HPP
