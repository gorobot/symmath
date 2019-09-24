#ifndef SYMMATH_TYPE_TRAITS_BOOLEAN_HPP
#define SYMMATH_TYPE_TRAITS_BOOLEAN_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< bool V >
struct Bool {

  static constexpr bool value = V;

  using type = Bool;
  using value_type = bool;

  constexpr operator value_type() const noexcept {
    return value;
  }

  constexpr value_type operator()() const noexcept {
    return value;
  }

};

using TrueType = Bool<true>;

using FalseType = Bool<false>;

} // sym

#endif // SYMMATH_TYPE_TRAITS_BOOLEAN_HPP
