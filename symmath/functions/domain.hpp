#ifndef SYMMATH_FUNCTIONS_DOMAIN_HPP
#define SYMMATH_FUNCTIONS_DOMAIN_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< typename ...T >
struct Domain {

  static constexpr auto size = (sizeof(T) + ...);

};

} // sym

#endif // SYMMATH_FUNCTIONS_DOMAIN_HPP
