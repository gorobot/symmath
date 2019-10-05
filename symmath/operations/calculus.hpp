#ifndef SYMMATH_OPERATIONS_CALCULUS_HPP
#define SYMMATH_OPERATIONS_CALCULUS_HPP

#include <symmath/operations/algebraic.hpp>
#include <symmath/operations/calculus/curl.hpp>
#include <symmath/operations/calculus/derivative.hpp>
#include <symmath/operations/calculus/diff.hpp>
#include <symmath/operations/calculus/divergence.hpp>
#include <symmath/operations/calculus/gradient.hpp>
#include <symmath/operations/calculus/integral.hpp>
#include <symmath/operations/calculus/laplacian.hpp>
#include <symmath/operations/calculus/lim.hpp>
#include <symmath/operations/calculus/pdiff.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
inline auto curl(T &operand)
-> const Curl<T>;

template< typename T1, typename T2 >
inline auto derivative(T1 &lhs, const T2 &rhs)
-> const Derivative<T1, T2>;

template< typename T >
inline auto diff(T &operand)
-> const Diff<T>;

template< typename T >
inline auto divergence(T &operand)
-> const Divergence<T>;

template< typename T >
inline auto gradient(T &operand)
-> const Gradient<T>;

template< typename T >
inline auto integral(T &operand)
-> const Integral<T>;

template< typename T >
inline auto laplacian(T &operand)
-> const Laplacian<T>;

template< typename T >
inline auto lim(T &operand)
-> const Lim<T>;

template< typename T >
inline auto pdiff(T &operand)
-> const PDiff<T>;

} // sym

#endif // SYMMATH_OPERATIONS_CALCULUS_HPP
