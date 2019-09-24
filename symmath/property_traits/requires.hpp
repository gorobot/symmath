#ifndef SYMMATH_PROPERTY_TRAITS_REQUIRES_HPP
#define SYMMATH_PROPERTY_TRAITS_REQUIRES_HPP

namespace sym {

// -----------------------------------------------------------------------------

constexpr bool Requires(bool t) {
  return (t && true);
}

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_REQUIRES_HPP
