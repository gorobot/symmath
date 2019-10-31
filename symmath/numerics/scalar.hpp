#ifndef SYMMATH_NUMERICS_SCALAR_HPP
#define SYMMATH_NUMERICS_SCALAR_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct Number;

template< typename T, size_t N, size_t M >
class Tensor;

// -----------------------------------------------------------------------------

namespace {

template< typename T >
using Scalar = Tensor<T, 0, 0>;

} // detail

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 0, 0> {
public:

  static constexpr size_t Order = (1);

  template< typename U >  using Scalar_   = Tensor<U, 0, 0>;
  template< typename U >  using Covector_ = Tensor<U, 0, 1>;
  template< typename U >  using Vector_   = Tensor<U, 1, 0>;
  template< typename U >  using Matrix_   = Tensor<U, 1, 1>;

private:

  // explicit inline Tensor() = default;

public:



};

} // sym

#endif // SYMMATH_NUMERICS_SCALAR_HPP
