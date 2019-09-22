#ifndef SYMMATH_EXPRESSION_VARIABLE_HPP
#define SYMMATH_EXPRESSION_VARIABLE_HPP

#include <memory>

#include <symmath/type_traits/void_t.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename = void_t<> >
class Variable;

} // sym

#endif // SYMMATH_EXPRESSION_VARIABLE_HPP
