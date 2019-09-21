#ifndef SYMMATH_TENSORS_VECTOR_HPP
#define SYMMATH_TENSORS_VECTOR_HPP

#include <type_traits>

#include <symmath/numerics/tensor.hpp>
#include <symmath/sets/numerics/vector_space.hpp>
#include "../properties/has_value_array.hpp"
#include "../properties/has_addition.hpp"
#include "../properties/has_additive_inverse.hpp"
#include "../properties/has_assignment.hpp"
#include "../properties/has_multiplication.hpp"
#include "../properties/has_subtraction.hpp"
#include "../type_traits/result_of.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using Vector = Tensor<T, 1, 0>;

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 1, 0> {
public:

  using This = Vector<T>;

  // using ElementOf = typename T::ElementOf;

  using ValueType = T;
  using ArrayType = std::vector<ValueType>;

private:

  size_t dim_[1];

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();
  explicit inline Tensor(const size_t n);
  explicit inline Tensor(std::initializer_list<T> list);

  template< typename U >  explicit inline Tensor(const Vector<U> &other);
  template< typename U >  explicit inline Tensor(Vector<U> &&other);

  // Assignment Operator
  inline This &operator=(std::initializer_list<T> list);

  template< typename U >  inline This &operator=(const Vector<U> &other);
  template< typename U >  inline This &operator=(Vector<U> &&other);

  inline ValueType &operator()(const size_t i_);
  inline const ValueType &operator()(const size_t i_) const;

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions


} // sym

#endif // SYMMATH_TENSORS_VECTOR_HPP
