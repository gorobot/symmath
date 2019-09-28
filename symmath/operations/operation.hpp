#ifndef SYMMATH_OPERATIONS_OPERATION_HPP
#define SYMMATH_OPERATIONS_OPERATION_HPP

namespace sym {

// -----------------------------------------------------------------------------

struct Operation {};

// -----------------------------------------------------------------------------

template< typename T,
          typename R = typename T::ResultType >
inline const R eval(const T &operation) {
  R tmp;
  assign_(tmp, operation);
  return tmp;
}

// -----------------------------------------------------------------------------

// Commute function
// Requires CommutativeProperty

} // sym

#endif // SYMMATH_OPERATIONS_OPERATION_HPP
