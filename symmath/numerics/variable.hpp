#ifndef SYMMATH_NUMERICS_VARIABLE_HPP
#define SYMMATH_NUMERICS_VARIABLE_HPP

#include <iostream>
#include <memory>

#include <symmath/expressions/variable.hpp>
#include <symmath/numerics/number.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_number.hpp>
#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

namespace {

  template< typename T >
  using NumericVariable = Variable<T, EnableIf_t<IsNumber<T>{}>>;

} // detail

// -----------------------------------------------------------------------------

template< typename T >
class Variable<T, EnableIf_t<IsNumber<T>{}>>
  : public Number<NumericVariable<T>> {
public:

  using This            = NumericVariable<T>;
  using Reference       = NumericVariable<T>&;
  using ConstReference  = const NumericVariable<T>&;

  using ElementOf       = typename T::ElementOf;

  using ValueType       = typename T::ValueType;
  using ResultType      = typename T::ResultType;

private:

                          struct Concept;
  template< typename U >  struct Model;

  std::unique_ptr<const Concept> ptr_;

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

                          inline Reference operator=(const T &rhs);
  template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

  // Assign
                          inline void assign(const T &rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline NumericVariable<T>::Variable()
  : ptr_() {}

template< typename T >
inline NumericVariable<T>::Variable(const ValueType &value)
  : ptr_(std::make_unique<Model<T>>(std::move(T(value)))) {
    std::cout << "copy value ctor" << '\n';
  }

template< typename T >
inline NumericVariable<T>::Variable(ValueType &&value)
  : ptr_(std::make_unique<Model<T>>(std::move(T(value)))) {
    std::cout << "move value ctor" << '\n';
    std::cout << ptr_->value() << '\n';
  }

template< typename T >
inline NumericVariable<T>::Variable(const T &other)
  : ptr_(std::make_unique<ReferenceModel<T>>(other)) {
    std::cout << "copy other T ctor" << '\n';
  }

template< typename T >
template< typename U >
inline NumericVariable<T>::Variable(const Number<U> &other)
  : ptr_(std::make_unique<ReferenceModel<T>>(static_cast<const U&>(other))) {
    std::cout << "copy other number ctor" << '\n';
  }

// -----------------------------------------------------------------------------
// Assignment Operator
template< typename T >
inline NumericVariable<T> &NumericVariable<T>::operator=(const ValueType &rhs) {
  std::cout << "copy assign value" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<Model<T>>(std::move(T(rhs)));
  return *this;
}

template< typename T >
inline NumericVariable<T> &NumericVariable<T>::operator=(ValueType &&rhs) {
  std::cout << "move assign value" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<Model<T>>(std::move(T(rhs)));
  return *this;
}

template< typename T >
inline NumericVariable<T> &NumericVariable<T>::operator=(const T &rhs) {
  std::cout << "copy assign T" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<ReferenceModel<T>>(rhs);
  return *this;
}

template< typename T >
template< typename U >
inline NumericVariable<T> &NumericVariable<T>::operator=(const Number<U> &rhs) {
  std::cout << "copy assign number" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<ReferenceModel<T>>(static_cast<const U&>(rhs));
  return *this;
}

template< typename T >
template< typename U >
inline auto NumericVariable<T>::operator=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  std::cout << "copy assign covariant result" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<Model<U>>(rhs);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline decltype(auto) NumericVariable<T>::value() const {
  std::cout << "get value: " << ptr_->value() << '\n';
  return ptr_->value();
}

// -----------------------------------------------------------------------------
// Assign
template< typename T >
inline void NumericVariable<T>::assign(const T &rhs) {

}

template< typename T >
template< typename U >
inline void NumericVariable<T>::assign(const Number<U> &rhs) {

}

template< typename T >
template< typename U >
inline auto NumericVariable<T>::assign(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {

}

// -----------------------------------------------------------------------------
// Concept
template< typename T >
struct NumericVariable<T>::Concept {
  virtual ~Concept() = default;
  virtual auto value() const -> ValueType = 0;
};

// -----------------------------------------------------------------------------
// Model
template< typename T >
template< typename U >
struct NumericVariable<T>::Model final
  : public NumericVariable<T>::Concept {

  U data_;

  // explicit inline Model();
  explicit inline Model(const U &data);
  explicit inline Model(U &&data);

  inline auto value() const -> ValueType override;

};

// -----------------------------------------------------------------------------
// Model Constructor
// template< typename T >
// template< typename U >
// inline NumericVariable<T>::Model<U>::Model()
//   : data_() {}
//
template< typename T >
template< typename U >
inline NumericVariable<T>::Model<U>::Model(const U &data)
  : data_(data) {
    std::cout << "Model copy ctor" << '\n';
  }

template< typename T >
template< typename U >
inline NumericVariable<T>::Model<U>::Model(U &&data)
  : data_(std::move(data)) {
    std::cout << "Model move ctor" << '\n';
  }

// -----------------------------------------------------------------------------
// Model Member Function Definitions
template< typename T >
template< typename U >
inline auto NumericVariable<T>::Model<U>::value() const -> ValueType {
  std::cout << "Model get value: " << eval(data_).value() << '\n';
  return eval(data_).value();
}

} // sym

#endif // SYMMATH_NUMERICS_VARIABLE_HPP
