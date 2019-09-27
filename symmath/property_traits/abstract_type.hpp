#ifndef SYMMATH_PROPERTY_TRAITS_ABSTRACT_TYPE_HPP
#define SYMMATH_PROPERTY_TRAITS_ABSTRACT_TYPE_HPP

namespace sym {

// -----------------------------------------------------------------------------

namespace {

template< typename T >
using HasAbstractTypeTrait = typename T::AbstractType;

} // detail

// -----------------------------------------------------------------------------

template< typename T >
constexpr bool IsAbstractType = Requires(HasAbstractTypeTrait<T>);

template< typename T,
          typename = EnableIf_t<IsAbstractType<T>> >
using AbstractType = T;

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_ABSTRACT_TYPE_HPP
