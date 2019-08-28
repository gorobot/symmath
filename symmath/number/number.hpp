#ifndef SYMMATH_NUMBER_HPP
#define SYMMATH_NUMBER_HPP

#include <type_traits>

#include "../symbolic.hpp"
#include "../expression/apply.hpp"
#include "../expression/assignable.hpp"
#include "../operation/arithmetic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

template< typename T >
struct is_integral
  : std::false_type {};

template<>
struct is_integral<short>
  : std::true_type {};

template<>
struct is_integral<unsigned short>
  : std::true_type {};

template<>
struct is_integral<int>
  : std::true_type {};

template<>
struct is_integral<unsigned int>
  : std::true_type {};

template<>
struct is_integral<long>
  : std::true_type {};

template<>
struct is_integral<unsigned long>
  : std::true_type {};

template<>
struct is_integral<long long>
  : std::true_type {};

template<>
struct is_integral<unsigned long long>
  : std::true_type {};

template< typename T >
struct is_floating_point
  : std::false_type {};

template<>
struct is_floating_point<float>
  : std::true_type {};

template<>
struct is_floating_point<double>
  : std::true_type {};

template<>
struct is_floating_point<long double>
  : std::true_type {};

template< typename T >
struct is_numeric
  : std::integral_constant<bool,
      is_integral<T>{} ||
      is_floating_point<T>{}> {};

// -----------------------------------------------------------------------------

template< typename T >
class Number
  : public Symbolic<Number<T>>,
    public Assignable<Number<T>, Number> {
private:

  T v_;

public:

  explicit inline Number();
  inline Number(const T v);

  template< typename U >
  inline Number<T> &operator=(const Symbolic<U> &rhs);

  template< typename U >
  inline void apply(const Number<U> &rhs);
  template< typename U >
  inline void apply_add(const Number<U> &rhs);
  template< typename U >
  inline void apply_div(const Number<U> &rhs);
  template< typename U >
  inline void apply_mul(const Number<U> &rhs);
  template< typename U >
  inline void apply_sub(const Number<U> &rhs);

};

// -----------------------------------------------------------------------------

template< typename T >
struct is_number_helper {
private:

  template< typename ...U >
  static std::true_type test(Number<U...> &);

  template< typename ...U >
  static std::true_type test(const Number<U...> &);

  static std::false_type test(...);

public:

  using type = decltype(test(std::declval<T&>()));

};

template< typename T >
struct is_number
  : is_number_helper<T>::type {};

template< typename T >
using is_number_t = typename is_number_helper<T>::type;

// -----------------------------------------------------------------------------
template< typename T >
Number<T>::Number()
  : v_(0) {}

template< typename T >
Number<T>::Number(const T v)
  : v_(v) {}

template< typename T >
template< typename U >
inline Number<T> &
Number<T>::operator=(const Symbolic<U> &rhs) {
  apply_(*this, rhs.derived());
  return *this;
}

template< typename T >
template< typename U >
inline void
Number<T>::apply(const Number<U> &rhs) {
  v_ = rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_add(const Number<U> &rhs) {
  v_ += rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_div(const Number<U> &rhs) {
  v_ /= rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_mul(const Number<U> &rhs) {
  v_ *= rhs.v_;
}
template< typename T >
template< typename U >
inline void
Number<T>::apply_sub(const Number<U> &rhs) {
  v_ -= rhs.v_;
}

} // sym

#endif // SYMMATH_NUMBER_HPP
