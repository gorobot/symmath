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

  static constexpr size_t Order = (1);

                          using This      = Scalar<T>;
  template< typename U >  using Other     = Scalar<U>;

  template< typename U >  using Scalar    = Tensor<U, 0, 0>;
  template< typename U >  using Covector  = Tensor<U, 0, 1>;
  template< typename U >  using Vector    = Tensor<U, 1, 0>;
  template< typename U >  using Matrix    = Tensor<U, 1, 1>;

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

  template< typename U >  explicit inline Tensor(const Other<U> &other);
  template< typename U >  explicit inline Tensor(Other<U> &&other);

  // Assignment Operator
  inline This &operator=(const ValueType &value);
  inline This &operator=(ValueType &&value);

  template< typename U >  inline This &operator=(const Other<U> &other);
  template< typename U >  inline This &operator=(Other<U> &&other);

  // Assign
                          inline void assign(const ValueType &rhs);
  template< typename U >  inline void assign(const Scalar<U> &rhs);

  // Assign Scalar Multiplication
                          inline void assign_scalar_mul(const ValueType &rhs);
  template< typename U >  inline void assign_scalar_mul(const Scalar<U> &rhs);

  // Assign Tensor Product
  template< typename U, size_t N, size_t M >
  inline void assign_tensor_prod(const Tensor<U, N, M> &rhs);

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
