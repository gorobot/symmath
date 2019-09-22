#ifndef SYMMATH_TENSORS_MATRIX_HPP
#define SYMMATH_TENSORS_MATRIX_HPP

#include <type_traits>

#include "tensor.hpp"
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
using Matrix = Tensor<T, 1, 1>;

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 1, 1> {
public:

  using This = Matrix<T>;

  template< typename U >
  using Other = Matrix<U>;

  // using ElementOf =

  using ValueType = T;
  using ArrayType = std::vector<ValueType>;

  // STL Type Requirements
  using value_type      = ValueType;
  using reference       = ValueType&;
  using const_reference = const ValueType&;
  using iterator        = ArrayType::iterator;
  using const_iterator  = ArrayType::const_iterator;
  using difference_type = ArrayType::difference_type;
  using size_type       = ArrayType::size_type;

private:

  size_t dim_[2];

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();
  explicit inline Tensor(const size_t n, const size_t m);
  explicit inline Tensor(std::initializer_list<std::initializer_list<T>> list);

  template< typename U >  explicit inline Tensor(const Other<U> &other);
  template< typename U >  explicit inline Tensor(Other<U> &&other);

  // Assignment Operator
  inline This &operator=(std::initializer_list<std::initializer_list<T>> list);

  template< typename U >  inline This &operator=(const Other<U> &other);
  template< typename U >  inline This &operator=(Other<U> &&other);

  // Assign
  template< typename U >  inline void assign(const Other<U> &rhs);

  // Assign Tensor Product
  template< typename U, size_t N, size_t M >
  inline void assign_tensor_prod(const Tensor<U, N, M> &rhs);

  inline ValueType &operator()(const size_t i_, const size_t j_);
  inline const ValueType &operator()(const size_t i_, const size_t j_) const;

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions


} // sym

#endif // SYMMATH_TENSORS_MATRIX_HPP
