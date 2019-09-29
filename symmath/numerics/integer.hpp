#ifndef SYMMATH_NUMERICS_INTEGER_HPP
#define SYMMATH_NUMERICS_INTEGER_HPP

#ifndef SYMMATH_INTEGER_UNDERLYING_TYPE
#define SYMMATH_INTEGER_UNDERLYING_TYPE int
#endif

#include <symmath/numerics/number.hpp>
#include <symmath/sets/numerics/integers.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Integer
  : public Number<Integer> {
public:

  using This            = Integer;
  using Reference       = Integer&;
  using ConstReference  = const Integer&;

  using ElementOf       = Integers;

  using ValueType       = SYMMATH_INTEGER_UNDERLYING_TYPE;
  using ResultType      = Integer;

private:

  ValueType value_;

public:

  // Constructor
  explicit inline Integer();

  explicit inline Integer(const ValueType &value);
  explicit inline Integer(ValueType &&value);

                 explicit inline Integer(ConstReference other);
  template< typename U >  inline Integer(const Number<U> &other);

  // Assignment Operator
  inline Reference operator=(const ValueType &rhs);
  inline Reference operator=(ValueType &&rhs);

                          inline Reference operator=(ConstReference rhs);
  template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator+=(const ValueType &rhs);
  inline Reference operator+=(ValueType &&rhs);

                          inline Reference operator+=(ConstReference rhs);
  template< typename U >  inline Reference operator+=(const Number<U> &rhs);
  template< typename U >  inline auto      operator+=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator*=(const ValueType &rhs);
  inline Reference operator*=(ValueType &&rhs);

                          inline Reference operator*=(ConstReference rhs);
  template< typename U >  inline Reference operator*=(const Number<U> &rhs);
  template< typename U >  inline auto      operator*=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator-=(const ValueType &rhs);
  inline Reference operator-=(ValueType &&rhs);

                          inline Reference operator-=(ConstReference rhs);
  template< typename U >  inline Reference operator-=(const Number<U> &rhs);
  template< typename U >  inline auto      operator-=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

  // Assign
                          inline void assign(ConstReference rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Addition
                          inline void assign_add(ConstReference rhs);
  template< typename U >  inline auto assign_add(const Number<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Multiplication
                          inline void assign_mul(ConstReference rhs);
  template< typename U >  inline auto assign_mul(const Number<U> &rhs);
  template< typename U >  inline auto assign_mul(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Subtraction
                          inline void assign_sub(ConstReference rhs);
  template< typename U >  inline auto assign_sub(const Number<U> &rhs);
  template< typename U >  inline auto assign_sub(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Power
                          inline void assign_pow(ConstReference rhs);
  template< typename U >  inline auto assign_pow(const Number<U> &rhs);
  template< typename U >  inline auto assign_pow(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Negative
                          inline void assign_neg(ConstReference rhs);
  template< typename U >  inline auto assign_neg(const Number<U> &rhs);
  template< typename U >  inline auto assign_neg(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Integer::Integer()
  : value_(0.0) {}

inline Integer::Integer(const ValueType &value)
  : value_(value) {}

inline Integer::Integer(ValueType &&value)
  : value_(std::move(value)) {}

inline Integer::Integer(ConstReference other)
  : value_(other.value_) {}

template< typename U >
inline Integer::Integer(const Number<U> &other)
  : value_(static_cast<const U&>(other).value()) {}

// -----------------------------------------------------------------------------
// Assignment Operator
inline Integer::Reference Integer::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

inline Integer::Reference Integer::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

inline Integer::Reference Integer::operator=(ConstReference other) {
  value_ = other.value_;
  return *this;
}

template< typename U >
inline Integer::Reference Integer::operator=(const Number<U> &other) {
  value_ = static_cast<const U&>(other).value_;
  return *this;
}

template< typename U >
inline auto Integer::operator=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Integer::Reference Integer::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}

inline Integer::Reference Integer::operator+=(ValueType &&rhs) {
  value_ += std::move(rhs);
  return *this;
}

inline Integer::Reference Integer::operator+=(ConstReference rhs) {
  value_ += rhs.value_;
  return *this;
}

template< typename U >
inline Integer::Reference Integer::operator+=(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Integer::operator+=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_add_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Integer::Reference Integer::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}

inline Integer::Reference Integer::operator*=(ValueType &&rhs) {
  value_ *= std::move(rhs);
  return *this;
}

inline Integer::Reference Integer::operator*=(ConstReference rhs) {
  value_ *= rhs.value_;
  return *this;
}

template< typename U >
inline Integer::Reference Integer::operator*=(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Integer::operator*=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_mul_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Integer::Reference Integer::operator-=(const ValueType &rhs) {
  value_ -= rhs;
  return *this;
}

inline Integer::Reference Integer::operator-=(ValueType &&rhs) {
  value_ -= std::move(rhs);
  return *this;
}

inline Integer::Reference Integer::operator-=(ConstReference rhs) {
  value_ -= rhs.value_;
  return *this;
}

template< typename U >
inline Integer::Reference Integer::operator-=(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Integer::operator-=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_sub_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline decltype(auto) Integer::value() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Assign
inline void Integer::assign(ConstReference rhs) {
  value_ = rhs.value_;
}

template< typename U >
inline void Integer::assign(const Number<U> &rhs) {
  value_ = static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Integer::assign(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Addition
inline void Integer::assign_add(ConstReference rhs) {
  value_ += rhs.value_;
}

template< typename U >
inline auto Integer::assign_add(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Integer::assign_add(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_add_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Multiplication
inline void Integer::assign_mul(ConstReference rhs) {
  value_ *= rhs.value_;
}

template< typename U >
inline auto Integer::assign_mul(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Integer::assign_mul(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_mul_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Subtraction
inline void Integer::assign_sub(ConstReference rhs) {
  value_ -= rhs.value_;
}

template< typename U >
inline auto Integer::assign_sub(const Number<U> &rhs) {
  value_ -= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Integer::assign_sub(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_sub_(*this, eval(rhs));
}

} // sym

#endif // SYMMATH_NUMERICS_INTEGER_HPP
