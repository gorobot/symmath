#ifndef SYMMATH_OPERATIONS_ARITY_HPP
#define SYMMATH_OPERATIONS_ARITY_HPP

namespace  {

// -----------------------------------------------------------------------------

template< size_t T >
struct Arity {
  static constexpr size_t arity = T;
};

} //

#endif // SYMMATH_OPERATIONS_ARITY_HPP
