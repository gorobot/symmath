#ifndef SYMMATH_OPERATION_OPERATION_HPP
#define SYMMATH_OPERATION_OPERATION_HPP

#include <type_traits>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
class Operation
  : public T {};

} // sym

#endif // SYMMATH_OPERATION_OPERATION_HPP
