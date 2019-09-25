#ifndef SYMMATH_FUNCTIONS_FUNCTION_HPP
#define SYMMATH_FUNCTIONS_FUNCTION_HPP

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename F >
struct FunctionReturnType {};

template<typename R, typename ...Args>
struct FunctionReturnType<R(*)(Args...)> {
  using type = R;
};

template<typename R, typename ...Args>
struct FunctionReturnType<R(Args...)> {
  using type = R;
};

template< typename F >
struct FunctionArgsType {};

template<typename R, typename ...Args>
struct FunctionArgsType<R(*)(Args...)> {
  using type = R;
};

template<typename R, typename Args>
struct FunctionArgsType<R(Args)> {
  // using type = std::tuple<Args...>;
  using type = Args;
};

} // detail

// -----------------------------------------------------------------------------

template< typename F >
class Function {
public:

  using ArgsType = typename FunctionArgsType<F>::type::ElementOf;
  using ReturnType = typename FunctionReturnType<F>::type::ElementOf;

  using FunctionType = ReturnType(ArgsType);

private:

  std::function<FunctionType> f_;

public:

  template< typename U >
  inline Function(U something) {
    std::cout << "constructor" << '\n';
  }

  template< typename U >
  inline Function<F> &operator=(U something) {
    std::cout << "operator=" << '\n';
  }

  template< typename U >
  inline std::function<F> &operator()(U expr) {
    return f_;
  }
  // const std::function<F> &
  // operator()(sym::Reals x) const {
  //   return f_(x);
  // }
};

} // sym

#endif // SYMMATH_FUNCTIONS_FUNCTION_HPP
