#ifndef SYMMATH_TENSORS_COVECTOR_HPP
#define SYMMATH_TENSORS_COVECTOR_HPP

#include <symmath/tensors/tensor.hpp>
#include <symmath/sets/numerics/vector_space.hpp>
#include <symmath/type_traits/nested_initializer_list.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
using Covector = Tensor<T, 0, 1>;

// -----------------------------------------------------------------------------

template< typename T >
class Tensor<T, 0, 1> {
public:

  static constexpr size_t Order = (1);

                          using This      = Covector<T>;
  template< typename U >  using Other     = Covector<U>;

  template< typename U >  using Scalar    = Tensor<U, 0, 0>;
  template< typename U >  using Covector  = Tensor<U, 0, 1>;
  template< typename U >  using Vector    = Tensor<U, 1, 0>;
  template< typename U >  using Matrix    = Tensor<U, 1, 1>;

  // using ElementOf = typename T::ElementOf;

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

  size_t dim_[1];

  ArrayType value_;

public:

  // Constructor
  explicit inline Tensor();
  explicit inline Tensor(const size_t n);
  explicit inline Tensor(NestedInitializer_t<T, Order> list);

  template< typename U >  explicit inline Tensor(const Covector<U> &other);
  template< typename U >  explicit inline Tensor(Covector<U> &&other);

  // Assignment Operator
  inline This &operator=(NestedInitializer_t<T, Order> list);

  template< typename U >  inline This &operator=(const Covector<U> &other);
  template< typename U >  inline This &operator=(Covector<U> &&other);

  inline ValueType &operator()(const size_t i_);
  inline const ValueType &operator()(const size_t i_) const;

};

// -----------------------------------------------------------------------------
// Constructor

// -----------------------------------------------------------------------------
// Member Function Definitions


} // sym

#endif // SYMMATH_TENSORS_COVECTOR_HPP
