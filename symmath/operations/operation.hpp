#ifndef SYMMATH_OPERATIONS_OPERATION_HPP
#define SYMMATH_OPERATIONS_OPERATION_HPP

#include <symmath/type_traits/result_type.hpp>

namespace sym {

// -----------------------------------------------------------------------------

struct Operation {};

// -----------------------------------------------------------------------------

template< typename T,
          typename R = ResultType_t<T> >
inline const R eval(const T &operation) {
  R tmp;
  assign_(tmp, operation);
  return tmp;
}

} // sym

#endif // SYMMATH_OPERATIONS_OPERATION_HPP
