#ifndef SYMMATH_OPERATIONS_BASIC_HPP
#define SYMMATH_OPERATIONS_BASIC_HPP

#include <symmath/operations/probability/conditional_probability.hpp>
#include <symmath/operations/probability/correlation.hpp>
#include <symmath/operations/probability/covariance.hpp>
#include <symmath/operations/probability/expected_value.hpp>
#include <symmath/operations/probability/probability.hpp>
#include <symmath/operations/probability/standard_deviation.hpp>
#include <symmath/operations/probability/variance.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_same_result.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1, typename T2 >
inline auto conditional_prob(T1 &lhs, const T2 &rhs)
-> const ConditionalProbability<T1, T2>;

template< typename T1, typename T2 >
inline auto correlation(T1 &lhs, const T2 &rhs)
-> const Correlation<T1, T2>;

template< typename T1, typename T2 >
inline auto covariance(T1 &lhs, const T2 &rhs)
-> const Covariance<T1, T2>;

template< typename T >
inline auto expected_value(T &operand)
-> const ExpectedValue<T>;

template< typename T >
inline auto prob(T &operand)
-> const Probability<T>;

template< typename T >
inline auto standard_deviation(T &operand)
-> const StandardDeviation<T>;

template< typename T >
inline auto variance(T &operand)
-> const Variance<T>;

} // sym

#endif // SYMMATH_OPERATIONS_BASIC_HPP
