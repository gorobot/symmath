#ifndef SYMMATH_OPERATIONS_TOTAL_ORDER_HPP
#define SYMMATH_OPERATIONS_TOTAL_ORDER_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
operator<(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TotalOrder>{} &&
              HasProperty<T2, TotalOrder>{} &&
              std::is_same<T1, T2>{},
              bool> {
  return lhs < rhs;
}

template< typename T1,
          typename T2 >
operator<=(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TotalOrder>{} &&
              HasProperty<T2, TotalOrder>{} &&
              std::is_same<T1, T2>{},
              bool> {
  return lhs <= rhs;
}

template< typename T1,
          typename T2 >
operator>(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TotalOrder>{} &&
              HasProperty<T2, TotalOrder>{} &&
              std::is_same<T1, T2>{},
              bool> {
  return lhs > rhs;
}

template< typename T1,
          typename T2 >
operator>=(const T1 &lhs, const T2 &rhs)
-> EnableIf_t<HasProperty<T1, TotalOrder>{} &&
              HasProperty<T2, TotalOrder>{} &&
              std::is_same<T1, T2>{},
              bool> {
  return lhs >= rhs;
}

} // sym

#endif // SYMMATH_OPERATIONS_TOTAL_ORDER_HPP
