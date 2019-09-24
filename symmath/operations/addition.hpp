#ifndef SYMMATH_OPERATIONS_ADDITION_HPP
#define SYMMATH_OPERATIONS_ADDITION_HPP

#include <type_traits>

#include <symmath/operations/basic/add.hpp>
#include <symmath/property_traits/addable.hpp>
#include <symmath/type_traits/enable_if.hpp>
#include <symmath/type_traits/is_same_result.hpp>

namespace sym {

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
assign_add_(Addable<T1> &lhs, const Addable<T2> &rhs)
-> EnableIf_t<IsSameResult<T1, T2>{}> {
  lhs.assign_add(rhs);
}

// -----------------------------------------------------------------------------

template< typename T1,
          typename T2 >
inline auto
operator+(const Addable<T1> &lhs, const Addable<T2> &rhs)
-> EnableIf_t<IsSameResult<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

template< typename T1,
          typename T2 >
inline auto
add(const Addable<T1> &lhs, const Addable<T2> &rhs)
-> EnableIf_t<IsSameResult<T1, T2>{}, const Add<T1, T2>> {
  return Add<T1, T2>(lhs, rhs);
}

// template< typename T1,
//           typename T2 >
// inline auto
// operator+=(T1 &lhs, const T2 &rhs)
// -> EnableIf_t<HasProperty<T1, Addition>{} &&
//               HasProperty<T2, Addition>{} &&
//               IsSameResult<T1, T2>{},
//               T1&> {
//   assign_add_(lhs, rhs);
//   return lhs;
// }

} // sym

#endif // SYMMATH_OPERATIONS_ADDITION_HPP
