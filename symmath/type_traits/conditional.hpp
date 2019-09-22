#ifndef SYMMATH_TYPE_TRAITS_CONDITIONAL_HPP
#define SYMMATH_TYPE_TRAITS_CONDITIONAL_HPP

namespace sym {

// -----------------------------------------------------------------------------

template< bool C,
          typename T1,
          typename T2 >
struct If {
public:

  using type = T1;

};

template< typename T1,
          typename T2 >
struct If<false, T1, T2> {
public:

  using type = T2;

};

template< bool C,
          typename T1,
          typename T2 >
using If_t = typename If<C, T1, T2>::type;

} // sym

#endif // SYMMATH_TYPE_TRAITS_CONDITIONAL_HPP
