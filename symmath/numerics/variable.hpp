#ifndef SYMMATH_NUMERICS_VARIABLE_HPP
#define SYMMATH_NUMERICS_VARIABLE_HPP

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

  template< typename U >  explicit inline Variable(U &&other);

  // Assignment Operator
  template< typename U >  inline auto operator=(U &&rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

private:

  template< typename U >
  friend inline void
  assign_(U &lhs, const NumericVariable<T> &rhs) {
    assign_(lhs, rhs.ptr_->value());
  }

  template< typename U >
  friend inline void
  assign_add_(U &lhs, const NumericVariable<T> &rhs) {
    assign_add_(lhs, rhs.ptr_->value());
  }

  template< typename U >
  friend inline void
  assign_div_(U &lhs, const NumericVariable<T> &rhs) {
    assign_div_(lhs, rhs.ptr_->value());
  }

  template< typename U >
  friend inline void
  assign_mul_(U &lhs, const NumericVariable<T> &rhs) {
    assign_mul_(lhs, rhs.ptr_->value());
  }

  template< typename U >
  friend inline void
  assign_sub_(U &lhs, const NumericVariable<T> &rhs) {
    assign_sub_(lhs, rhs.ptr_->value());
  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline NumericVariable<T>::Variable()
  : ptr_() {}

template< typename T >
template< typename U >
inline NumericVariable<T>::Variable(U &&other)
  : ptr_(std::make_unique<Model<U>>(std::forward<U>(other))) {}

// -----------------------------------------------------------------------------
// Assignment Operator
template< typename T >
template< typename U >
inline auto NumericVariable<T>::operator=(U &&rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
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
// Concept
template< typename T >
struct NumericVariable<T>::Concept {
  virtual ~Concept() = default;
  virtual auto copy() const -> std::unique_ptr<Concept> = 0;
  virtual auto value() const -> T = 0;
};

// -----------------------------------------------------------------------------
// Model
template< typename T >
template< typename U >
struct NumericVariable<T>::Model final
  : public NumericVariable<T>::Concept {

  using InnerType = If_t<IsLValueRef<U>{}, AddConstRef_t<U>, AddConst_t<U>>;

  InnerType data_;

  template< typename V >  explicit inline Model(V &&data);

  inline auto copy() const -> std::unique_ptr<Concept> override;
  inline auto value() const -> T override;

};

// -----------------------------------------------------------------------------
// Model Constructor
template< typename T >
template< typename U >
template< typename V >
inline NumericVariable<T>::Model<U>::Model(V &&data)
  : data_(std::forward<V>(data)) {}

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
inline auto NumericVariable<T>::Model<U>::value() const -> T {
  T tmp;
  tmp = data_;
  return tmp;
}

} // sym

#endif // SYMMATH_NUMERICS_VARIABLE_HPP
