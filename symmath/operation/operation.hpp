#ifndef SYMMATH_OPERATION_OPERATION_HPP
#define SYMMATH_OPERATION_OPERATION_HPP

namespace sym {

// -----------------------------------------------------------------------------

struct Operation {};

// -----------------------------------------------------------------------------

template< typename T >
struct ResultType {
  using type = typename T::ResultType;
};

} // sym

#endif // SYMMATH_OPERATION_OPERATION_HPP
