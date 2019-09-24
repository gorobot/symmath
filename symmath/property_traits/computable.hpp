#ifndef SYMMATH_PROPERTY_TRAITS_COMPUTABLE_HPP
#define SYMMATH_PROPERTY_TRAITS_COMPUTABLE_HPP

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename ...T >
constexpr bool HasTotalOrder = All<HasProperty<T, TotalOrder>...>{};

} // detail

// -----------------------------------------------------------------------------

template< typename ...T >
constexpr bool IsComputable = Requires(HasTotalOrder<T...>);

template< typename T,
          typename = EnableIf_t<IsComputable<T>> >
using Computable = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_COMPUTABLE_HPP
