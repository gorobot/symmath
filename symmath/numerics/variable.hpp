#ifndef SYMMATH_NUMERICS_VARIABLE_HPP
#define SYMMATH_NUMERICS_VARIABLE_HPP

#include <iostream>
#include <memory>

#include <symmath/expressions/variable.hpp>
#include <symmath/numerics/number.hpp>
#include <symmath/type_traits/add_const_ref.hpp>
#include <symmath/type_traits/add_const.hpp>
#include <symmath/type_traits/conditional.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_lvalue_ref.hpp>
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

  //                explicit inline Variable(const T &other);
  // template< typename U >  inline Variable(const Number<U> &other);
  template< typename U >  explicit inline Variable(U &&other);

  // Assignment Operator
  inline This &operator=(const ValueType &rhs);
  inline This &operator=(ValueType &&rhs);

  //                         inline Reference operator=(const T &rhs);
  // template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(U &&rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

  // Assign
                          inline void assign(const T &rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Addition
                          inline void assign_add(const T &rhs);
  template< typename U >  inline void assign_add(const Number<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const NumericVariable<T> &rhs) {
    // std::cout << rhs.ptr_->value() << '\n';
    // assign_(lhs, rhs.ptr_->value());
    lhs = rhs.ptr_->value();
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline NumericVariable<T>::Variable()
  : ptr_() {}

template< typename T >
inline NumericVariable<T>::Variable(const ValueType &value)
  : ptr_(std::make_unique<Model<T>>(std::forward<ValueType>(value))) {
    std::cout << "Variable: copy value ctor" << '\n';
  }

template< typename T >
inline NumericVariable<T>::Variable(ValueType &&value)
  : ptr_(std::make_unique<Model<T>>(std::forward<ValueType>(value))) {
    std::cout << "Variable: move value ctor" << '\n';
  }

// template< typename T >
// inline NumericVariable<T>::Variable(const T &other)
//   : ptr_(std::make_unique<Model<T>>(other)) {
//     std::cout << "Variable: copy other T ctor" << '\n';
//   }
//
// template< typename T >
// template< typename U >
// inline NumericVariable<T>::Variable(const Number<U> &other)
//   : ptr_(std::make_unique<Model<T>>(static_cast<const U&>(other))) {
//     std::cout << "Variable: copy other number ctor" << '\n';
//   }

template< typename T >
template< typename U >
inline NumericVariable<T>::Variable(U &&other)
  : ptr_(std::make_unique<Model<U>>(std::forward<U>(other))) {
    std::cout << "Variable: forwarding ctor" << '\n';
  }

// -----------------------------------------------------------------------------
// Assignment Operator
template< typename T >
inline NumericVariable<T> &NumericVariable<T>::operator=(const ValueType &rhs) {
  std::cout << "Variable: copy assign value" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<Model<T>>(std::forward<T>(T(rhs)));
  return *this;
}

template< typename T >
inline NumericVariable<T> &NumericVariable<T>::operator=(ValueType &&rhs) {
  std::cout << "Variable: move assign value" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<Model<T>>(std::forward<T>(T(rhs)));
  return *this;
}

// template< typename T >
// inline NumericVariable<T> &NumericVariable<T>::operator=(const T &rhs) {
//   std::cout << "Variable: copy assign T" << '\n';
//   ptr_.reset();
//   ptr_ = std::make_unique<Model<T>>(rhs);
//   return *this;
// }
//
// template< typename T >
// template< typename U >
// inline NumericVariable<T> &NumericVariable<T>::operator=(const Number<U> &rhs) {
//   std::cout << "Variable: copy assign number" << '\n';
//   ptr_.reset();
//   ptr_ = std::make_unique<Model<T>>(static_cast<const U&>(rhs));
//   return *this;
// }
//
template< typename T >
template< typename U >
inline auto NumericVariable<T>::operator=(U &&rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  std::cout << "Variable: forward assign covariant result" << '\n';
  ptr_.reset();
  ptr_ = std::make_unique<Model<U>>(std::forward<U>(rhs));
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline decltype(auto) NumericVariable<T>::value() const {
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
// Assign Addition
template< typename T >
inline void NumericVariable<T>::assign_add(const T &rhs) {

}

template< typename T >
template< typename U >
inline void NumericVariable<T>::assign_add(const Number<U> &rhs) {

}

template< typename T >
template< typename U >
inline auto NumericVariable<T>::assign_add(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {

}

// -----------------------------------------------------------------------------
// Concept
template< typename T >
struct NumericVariable<T>::Concept {
  virtual ~Concept() = default;
  virtual auto copy() const -> std::unique_ptr<Concept> = 0;
  virtual auto value() const -> ValueType = 0;
};

// -----------------------------------------------------------------------------
// Model
template< typename T >
template< typename U >
struct NumericVariable<T>::Model final
  : public NumericVariable<T>::Concept {

  using InnerType = If_t<IsLValueRef<U>{}, AddConstRef_t<U>, AddConst_t<U>>;

  InnerType data_;

                          // explicit inline Model(const U &data);
                          // explicit inline Model(U &&data);
  template< typename V >  explicit inline Model(V &&data);

  inline auto copy() const -> std::unique_ptr<Concept> override;
  inline auto value() const -> ValueType override;

};

// -----------------------------------------------------------------------------
// Model Constructor
// template< typename T >
// template< typename U >
// inline NumericVariable<T>::Model<U>::Model(const U &data)
//   : data_(data) {
//     std::cout << "Variable: Model copy ctor" << '\n';
//   }
//
// template< typename T >
// template< typename U >
// inline NumericVariable<T>::Model<U>::Model(U &&data)
//   : data_(std::move(data)) {
//     std::cout << "Variable: Model move ctor" << '\n';
//   }

template< typename T >
template< typename U >
template< typename V >
inline NumericVariable<T>::Model<U>::Model(V &&data)
  : data_(std::forward<V>(data)) {
    std::cout << "Variable: Model forwarding ctor" << '\n';
  }

// -----------------------------------------------------------------------------
// Model Member Function Definitions
template< typename T >
template< typename U >
inline auto NumericVariable<T>::Model<U>::copy() const
-> std::unique_ptr<Concept> {
  return std::make_unique<Model<U>>(*this);
}

template< typename T >
template< typename U >
inline auto NumericVariable<T>::Model<U>::value() const -> ValueType {
  return eval(data_).value();
  // return 0;
}

} // sym

#endif // SYMMATH_NUMERICS_VARIABLE_HPP
