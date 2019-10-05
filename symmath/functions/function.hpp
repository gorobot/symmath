#ifndef SYMMATH_FUNCTIONS_FUNCTION_HPP
#define SYMMATH_FUNCTIONS_FUNCTION_HPP

#include <iostream>
#include <memory>
#include <tuple>

#include <symmath/expressions/variable.hpp>
#include <symmath/functions/codomain.hpp>
#include <symmath/functions/domain.hpp>
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

template< typename C,
          typename ...D >
class Function {
public:

  static constexpr auto N = (sizeof(D) + ...);

  using This            = Function<C, D...>;
  using Reference       = This&;
  using ConstRef        = const This&;
  using MoveRef         = This&&;

  using ElementOf       = C;

  using ResultType      = C;

private:

                          struct Concept;
  template< typename U >  struct Model;

  std::unique_ptr<const Concept> ptr_;

  std::tuple<Variable<D>&...> params_;

public:

  explicit inline Function() = default;

  explicit inline Function(Variable<D>&... params);

                                   // inline Function(ConstRef other);
                                   // inline Function(MoveRef other) = default;
  // template< typename U >  explicit inline Function(U&& other);

  // Assignment Operator
                          // inline Reference operator=(ConstRef rhs);
                          // inline Reference operator=(MoveRef rhs) = default;
  template< typename U >  inline auto      operator=(U &&rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline const C operator()(const D&... params);

};

// -----------------------------------------------------------------------------
// Constructor
template< typename C,
          typename ...D >
inline Function<C, D...>::Function(Variable<D>&... params)
  : ptr_(),
    params_(params...) {
      std::cout << "Function: ctor" << '\n';
    }

// template< typename C,
//           typename ...D >
// inline Function<C, D...>::Function(ConstRef other)
//   : ptr_(other.ptr_->copy()) {
//     std::cout << "Function: copy ctor" << '\n';
//   }

// template< typename C,
//           typename ...D >
// template< typename U >
// inline Function<C, D...>::Function(U &&other)
//   : ptr_(std::make_unique<Model<U>>(std::forward<U>(other))) {
//     std::cout << "Function: forwarding ctor" << '\n';
//   }

// -----------------------------------------------------------------------------
// Assignment Operator
// template< typename C,
//           typename ...D >
// inline typename Function<C, D...>::Reference
// Function<C, D...>::operator=(ConstRef other) {
//   std::cout << "Function: = copy" << '\n';
//   Function<C> tmp(other);
//   *this = std::move(other);
//   return *this;
// }

template< typename C,
          typename ...D >
template< typename U >
inline auto Function<C, D...>::operator=(U &&rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  std::cout << "Function: = covariant" << '\n';
  // Deduce variables.
  ptr_.reset();
  ptr_ = std::make_unique<Model<U>>(std::forward<U>(rhs));
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename C,
          typename ...D >
inline const C Function<C, D...>::operator()(const D&... params) {
  std::cout << "Function: operator()" << '\n';

  // (std::cout << ... << params);
  // std::cout << '\n';
  std::tuple p(params...);
  params_ = p;

  return (*ptr_)(params...);
}

// -----------------------------------------------------------------------------
// Concept
template< typename C,
          typename ...D >
struct Function<C, D...>::Concept {
  virtual ~Concept() = default;
  virtual auto copy() const -> std::unique_ptr<Concept> = 0;
  virtual C operator()(const D&... params) const = 0;
};

// -----------------------------------------------------------------------------
// Model
template< typename C,
          typename ...D >
template< typename U >
struct Function<C, D...>::Model final
  : public Function<C, D...>::Concept {

  using InnerType = If_t<IsLValueRef<U>{}, AddConstRef_t<U>, AddConst_t<U>>;

  InnerType data_;

  explicit inline Model(const U &data);

  inline auto copy() const -> std::unique_ptr<Concept> override;
  inline C operator()(const D&... params) const override;
};

// -----------------------------------------------------------------------------
// Model Constructor
template< typename C,
          typename ...D >
template< typename U >
inline Function<C, D...>::Model<U>::Model(const U &data)
  : data_(data) {
    std::cout << "Function: Model copy ctor" << '\n';
  };

// -----------------------------------------------------------------------------
// Model Member Function Definitions
template< typename C,
          typename ...D >
template< typename U >
inline auto Function<C, D...>::Model<U>::copy() const
-> std::unique_ptr<Concept> {
  return std::make_unique<Model<U>>(*this);
}

template< typename C,
          typename ...D >
template< typename U >
inline C Function<C, D...>::Model<U>::operator()(const D&... params) const {
  std::cout << "Function: Model operator()" << '\n';

  C tmp;
  tmp = data_;
  return tmp;
}

} // sym

#endif // SYMMATH_FUNCTIONS_FUNCTION_HPP
