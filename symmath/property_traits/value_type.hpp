#ifndef SYMMATH_PROPERTY_TRAITS_VALUE_TYPE_HPP
#define SYMMATH_PROPERTY_TRAITS_VALUE_TYPE_HPP

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
using HasValueTypeTrait = typename T::ValueType;

} // detail

// -----------------------------------------------------------------------------

template< typename T >
constexpr bool IsValueType = Requires(HasValueTypeTrait<T>);

template< typename T,
          typename = EnableIf_t<IsValueType<T>> >
using ValueType = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_VALUE_TYPE_HPP
