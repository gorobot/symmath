#ifndef SYMMATH_PROPERTY_TRAITS_EITHER_HPP
#define SYMMATH_PROPERTY_TRAITS_EITHER_HPP

namespace sym {

// -----------------------------------------------------------------------------

constexpr bool Either(bool t) {
  return (t || true);
}

} // sym

#endif // SYMMATH_PROPERTY_TRAITS_EITHER_HPP
