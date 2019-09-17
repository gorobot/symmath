#ifndef SYMMATH_PROPERTIES_HAS_ADDITION_HPP
#define SYMMATH_PROPERTIES_HAS_ADDITION_HPP

#include <type_traits>

#include "property.hpp"
#include "../operations/add.hpp"
#include "../type_traits/has_property.hpp"

namespace sym {

// -----------------------------------------------------------------------------

struct addition
  : private Property {};

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline void
assign_add_(T1 &lhs, const T2 &rhs) {
  lhs.assign_add(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, addition>{} &&
                    has_property<T2, addition>{},
                    const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

// template< typename T1,
//           typename T2 >
// inline auto
// operator+(const T1 &lhs, const T2 &rhs)
// -> std::enable_if_t<(has_property<T1, addition>{} ||
//                      has_property<T2, addition>{}) &&
//                     !std::is_same<T1, T2>{},
//                     const Add<T1, T2>> {
//   return Add<T1, T2>(lhs, rhs);
// }

template< typename T1,
          typename T2 >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, addition>{} &&
                    !std::is_same<T1, T2>{},
                    const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator+(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T2, addition>{} &&
                    !std::is_same<T1, T2>{},
                    const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
add(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, addition>{} &&
                    has_property<T2, addition>{},
                    const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
add(const T1 &lhs, const T2 &rhs)
-> std::enable_if_t<(has_property<T1, addition>{} ||
                     has_property<T2, addition>{}) &&
                    !std::is_same<T1, T2>{},
                    const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
operator+=(T1 &lhs, const T2 &rhs)
-> std::enable_if_t<has_property<T1, addition>{}, T1&> {
  assign_add_(lhs, rhs);
  return lhs;
}

} // sym

#endif // SYMMATH_PROPERTIES_HAS_ADDITION_HPP
