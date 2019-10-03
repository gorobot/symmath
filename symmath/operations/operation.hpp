#ifndef SYMMATH_OPERATIONS_OPERATION_HPP
#define SYMMATH_OPERATIONS_OPERATION_HPP

#include <iostream>

#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

struct Operation {};

// -----------------------------------------------------------------------------

template< typename T,
          typename R = ResultType_t<T> >
inline R eval(const T &operation) {
  std::cout << "eval" << '\n';
  R tmp;
  assign_(tmp, operation);
  return tmp;
}

// -----------------------------------------------------------------------------

// Commute function
// Requires CommutativeProperty

} // sym

#endif // SYMMATH_OPERATIONS_OPERATION_HPP
