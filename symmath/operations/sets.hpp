#ifndef SYMMATH_OPERATIONS_SETS_HPP
#define SYMMATH_OPERATIONS_SETS_HPP

#include <symmath/operations/sets/complement.hpp>
#include <symmath/operations/sets/difference.hpp>
#include <symmath/operations/sets/inf.hpp>
#include <symmath/operations/sets/intersection.hpp>
#include <symmath/operations/sets/sup.hpp>
#include <symmath/operations/sets/union.hpp>
#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
inline auto complement(T &operand)
-> const Complement<T>;

template< typename T1, typename T2 >
inline auto difference(T1 &lhs, const T2 &rhs)
-> const Difference<T1, T2>;

template< typename T >
inline auto inf(T &operand)
-> const Inf<T>;

template< typename T1, typename T2 >
inline auto intersection(T1 &lhs, const T2 &rhs)
-> const Intersection<T1, T2>;

template< typename T >
inline auto sup(T &operand)
-> const Sup<T>;

template< typename T1, typename T2 >
inline auto union(T1 &lhs, const T2 &rhs)
-> const Union<T1, T2>;

} // sym

#endif // SYMMATH_OPERATIONS_SETS_HPP
