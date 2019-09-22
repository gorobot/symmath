#ifndef SYMMATH_OPERATIONS_OPERATION_HPP
#define SYMMATH_OPERATIONS_OPERATION_HPP

namespace sym {

// -----------------------------------------------------------------------------

struct Operation {};

// -----------------------------------------------------------------------------

template< typename T >
inline const typename T::ResultType
eval(const T &operation) {
  typename T::ResultType tmp;
  assign_(tmp, operation);
  return tmp;
}

// -----------------------------------------------------------------------------

// Commute function
// Requires CommutativeProperty

template< typename T1,
          typename T2 >
inline auto
assign_(T1 &lhs, const T2 &rhs) {
  lhs.assign(rhs);
}

} // sym

#endif // SYMMATH_OPERATIONS_OPERATION_HPP
