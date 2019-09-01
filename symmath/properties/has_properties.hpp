#ifndef SYMMATH_PROPERTIES_HAS_PROPERTIES_HPP
#define SYMMATH_PROPERTIES_HAS_PROPERTIES_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename T,
          template<typename> class ...U >
struct has_properties
  : public U<T>... {};

} // sym

#endif // SYMMATH_PROPERTIES_HAS_PROPERTIES_HPP
