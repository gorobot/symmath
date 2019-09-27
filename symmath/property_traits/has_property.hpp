#ifndef SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP
#define SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP

#include <symmath/sets/superset.hpp>
#include <symmath/property_traits/requires.hpp>
#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/detect.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_operation.hpp>
#include <symmath/type_traits/is_set.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          typename P >
struct HasProperty;

// -----------------------------------------------------------------------------

namespace {

template< typename T >
using IsElementOfSet = typename T::ElementOf;

// template< typename T,
//           typename P >
// constexpr bool SetHasProperty = HasProperty<typename T::ElementOf, P>{};

// template< typename T,
//           typename P >
// constexpr bool SupersetHasProperty =
//   HasProperty<Superset<typename T::ElementOf>, P>{};

} // detail

// -----------------------------------------------------------------------------

// template< typename T,
//           typename P >
// struct HasProperty {
//
//   static constexpr bool value =
//     Requires(SetHasProperty<T, P>);
//
//   using type = HasProperty;
//   using value_type = bool;
//
//   constexpr operator value_type() const noexcept {
//     return value;
//   }
//
//   constexpr value_type operator()() const noexcept {
//     return value;
//   }
//
// };

template< typename T,
          typename P >
struct HasProperty_helper {
private:

  template< typename U >
  static auto test(U &)
  -> EnableIf_t<HasProperty<typename U::ElementOf, P>{}, TrueType>;

  template< typename U >
  static auto test(const U &)
  -> EnableIf_t<HasProperty<typename U::ElementOf, P>{}, TrueType>;

  template< typename U >
  static auto test(U &)
  -> EnableIf_t<IsOperation<U>{} &&
                HasProperty<typename U::ResultType, P>{}, TrueType>;

  template< typename U >
  static auto test(const U &)
  -> EnableIf_t<IsOperation<U>{} &&
                HasProperty<typename U::ResultType, P>{}, TrueType>;

  static FalseType test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T,
          typename P >
struct HasProperty
  : HasProperty_helper<T, P>::type {};

template< typename T,
          typename P >
using HasProperty_t = typename HasProperty_helper<T, P>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_HAS_PROPERTY_HPP
