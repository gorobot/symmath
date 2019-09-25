#ifndef SYMMATH_NUMERICS_VARIABLE_HPP
#define SYMMATH_NUMERICS_VARIABLE_HPP

#include <memory>

#include <symmath/expressions/variable.hpp>
#include <symmath/tensors/tensor.hpp>
#include <symmath/operations/operation.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_tensor.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

  template< typename T >
  using TensorVariable = Variable<T, EnableIf_t<IsTensor<T>{}>>;

} // detail

// -----------------------------------------------------------------------------

template< typename T >
class Variable<T, EnableIf_t<IsTensor<T>{}>> {
public:

  using This = TensorVariable<T>;

  using ElementOf = typename T::ElementOf;

  using ValueType = typename T::ValueType;
  using ResultType = typename T::ResultType;

private:

                          struct Concept;
  template< typename U >  struct Model;

  std::shared_ptr<const Concept> ptr_;

public:

  // Constructor
  explicit inline Variable();

  explicit inline Variable(const ValueType &value);
  explicit inline Variable(ValueType &&value);

                 explicit inline Variable(const T &other);
  template< typename U >  inline Variable(const Number<U> &other);

  // Assignment Operator
  inline This &operator=(const ValueType &rhs);
  inline This &operator=(ValueType &&rhs);

                          inline This &operator=(const T &rhs);
  template< typename U >  inline This &operator=(const Number<U> &rhs);
  // template< typename U >  inline This &operator=(const Variable<U> &rhs);
  template< typename U >  inline auto  operator=(const U &rhs)
  -> EnableIf_t<IsSameResult<This, U>{}, This&>;
  template< typename U >  inline auto  operator=(U &&rhs)
  -> EnableIf_t<IsSameResult<This, U>{}, This&>;

  inline decltype(auto) value() const;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline TensorVariable<T>::Variable()
  : ptr_() {}

template< typename T >
inline TensorVariable<T>::Variable(const ValueType &value)
  : ptr_(std::make_shared<Model<T>>(std::move(T(value)))) {}

template< typename T >
inline TensorVariable<T>::Variable(ValueType &&value)
  : ptr_(std::make_shared<Model<T>>(std::move(T(value)))) {}

template< typename T >
inline TensorVariable<T>::Variable(const T &other)
  : ptr_(std::make_shared<Model<T>>(other)) {}

// -----------------------------------------------------------------------------
// Assignment Operator
template< typename T >
inline TensorVariable<T> &TensorVariable<T>::operator=(const ValueType &rhs) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(std::move(rhs));
  return *this;
}
template< typename T >
inline TensorVariable<T> &TensorVariable<T>::operator=(ValueType &&rhs) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(std::move(rhs));
  return *this;
}

template< typename T >
inline TensorVariable<T> &TensorVariable<T>::operator=(const T &rhs) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(rhs);
  return *this;
}

template< typename T >
template< typename U >
inline TensorVariable<T> &TensorVariable<T>::operator=(const Number<U> &rhs) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<U>>(static_cast<const U&>(rhs));
  return *this;
}

template< typename T >
template< typename U >
inline auto TensorVariable<T>::operator=(const U &rhs)
-> EnableIf_t<IsSameResult<This, U>{}, This&> {
  // if(this == &rhs)
  //   return *this;

  ptr_.reset();
  ptr_ = std::make_shared<Model<U>>(rhs);
  return *this;
}

template< typename T >
template< typename U >
inline auto TensorVariable<T>::operator=(U &&rhs)
-> EnableIf_t<IsSameResult<This, U>{}, This&> {
  // if(this == &rhs)
  //   return *this;

  ptr_.reset();
  ptr_ = std::make_shared<Model<U>>(std::move(rhs));
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline decltype(auto) TensorVariable<T>::value() const {
  return ptr_->value();
}

// -----------------------------------------------------------------------------
// Concept
template< typename T >
struct TensorVariable<T>::Concept {
  virtual ~Concept() = default;
  virtual auto value() const -> ValueType = 0;
};

// -----------------------------------------------------------------------------
// Model
template< typename T >
template< typename U >
struct TensorVariable<T>::Model final
  : public TensorVariable<T>::Concept {

  const U &data_;

  explicit inline Model();
  explicit inline Model(const U &data);
  explicit inline Model(U &&data);

  inline auto value() const -> ValueType override;

};

// -----------------------------------------------------------------------------
// Model Constructor
template< typename T >
template< typename U >
inline TensorVariable<T>::Model<U>::Model()
  : data_() {}

template< typename T >
template< typename U >
inline TensorVariable<T>::Model<U>::Model(const U &data)
  : data_(data) {}

template< typename T >
template< typename U >
inline TensorVariable<T>::Model<U>::Model(U &&data)
  : data_(std::move(data)) {}

// -----------------------------------------------------------------------------
// Model Member Function Definitions
template< typename T >
template< typename U >
inline auto TensorVariable<T>::Model<U>::value() const -> ValueType {
  return eval(data_).value();
}

} // sym

#endif // SYMMATH_NUMERICS_VARIABLE_HPP
