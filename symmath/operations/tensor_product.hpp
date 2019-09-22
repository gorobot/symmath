#ifndef SYMMATH_OPERATIONS_TENSOR_PRODUCT_HPP
#define SYMMATH_OPERATIONS_TENSOR_PRODUCT_HPP

#include <type_traits>

#include <symmath/operations/tensor_prod.hpp>
#include <symmath/properties/tensor_product.hpp>
#include <symmath/type_traits/has_property.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_tensor_prod_(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TensorProduct>{} &&
              HasProperty<T2, TensorProduct>{} &&
              std::is_same<T1, T2>{}> {
  lhs.assign_tensor_prod(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
auto
operator*(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TensorProduct>{} &&
              HasProperty<T2, TensorProduct>{} &&
              std::is_same<T1, T2>{},
              const TensorProd<T1, T2>> {
  return TensorProd<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
auto
mul(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TensorProduct>{} &&
              HasProperty<T2, TensorProduct>{} &&
              std::is_same<T1, T2>{},
              const TensorProd<T1, T2>> {
  return TensorProd<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator*=(T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TensorProduct>{} &&
              HasProperty<T2, TensorProduct>{} &&
              std::is_same<T1, T2>{},
              T1&> {
  assign_tensor_prod_(lhs, rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_OPERATIONS_TENSOR_PRODUCT_HPP
