#ifndef SYMMATH_NUMERICS_NATURAL_HPP
#define SYMMATH_NUMERICS_NATURAL_HPP

#ifndef SYMMATH_NATURAL_UNDERLYING_TYPE
#define SYMMATH_NATURAL_UNDERLYING_TYPE int
#endif

#include <symmath/numerics/number.hpp>
#include <symmath/sets/numerics/naturals.hpp>
#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Natural
  : public Number<Natural> {
public:

  using This            = Natural;
  using Reference       = This&;
  using ConstRef        = const This&;
  using MoveRef         = This&&;

  using ElementOf       = Naturals;

  using ValueType       = SYMMATH_NATURAL_UNDERLYING_TYPE;
  using ResultType      = This;

private:

  ValueType value_;

public:

  // Constructor
  explicit inline Natural();

  inline Natural(const ValueType &value);
  inline Natural(ValueType &&value);

                          inline Natural(ConstRef other) = default;
                          inline Natural(MoveRef other) = default;
  template< typename U >  inline Natural(const Number<U> &other);

  // Assignment Operator
  inline Reference operator=(const ValueType &rhs);
  inline Reference operator=(ValueType &&rhs);

                          inline Reference operator=(ConstRef rhs) = default;
                          inline Reference operator=(MoveRef rhs) = default;
  template< typename U >  inline Reference operator=(const Number<U> &rhs);
  template< typename U >  inline auto      operator=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator+=(const ValueType &rhs);
  inline Reference operator+=(ValueType &&rhs);

                          inline Reference operator+=(ConstRef rhs);
  template< typename U >  inline Reference operator+=(const Number<U> &rhs);
  template< typename U >  inline auto      operator+=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline Reference operator*=(const ValueType &rhs);
  inline Reference operator*=(ValueType &&rhs);

                          inline Reference operator*=(ConstRef rhs);
  template< typename U >  inline Reference operator*=(const Number<U> &rhs);
  template< typename U >  inline auto      operator*=(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>, Reference>;

  inline decltype(auto) value() const;

  // Assign
                          inline void assign(ConstRef rhs);
  template< typename U >  inline void assign(const Number<U> &rhs);
  template< typename U >  inline auto assign(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Addition
                          inline void assign_add(ConstRef rhs);
  template< typename U >  inline auto assign_add(const Number<U> &rhs);
  template< typename U >  inline auto assign_add(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Multiplication
                          inline void assign_mul(ConstRef rhs);
  template< typename U >  inline auto assign_mul(const Number<U> &rhs);
  template< typename U >  inline auto assign_mul(const U &rhs)
  -> EnableIf_t<IsCovariantResult<This, U>>;

  // Assign Power
                          inline void assign_pow(ConstRef rhs);
  template< typename U >  inline auto assign_pow(const Number<U> &rhs);
  template< typename U >  inline auto assign_pow(const U &other)
  -> EnableIf_t<IsCovariantResult<This, U>>;

};

// -----------------------------------------------------------------------------
// Constructor
inline Natural::Natural()
  : value_(0) {}

inline Natural::Natural(const ValueType &value)
  : value_(value) {}

inline Natural::Natural(ValueType &&value)
  : value_(std::move(value)) {}

template< typename U >
inline Natural::Natural(const Number<U> &other)
  : value_(static_cast<const U&>(other).value()) {}

// -----------------------------------------------------------------------------
// Assignment Operator
inline Natural::Reference Natural::operator=(const ValueType &value) {
  value_ = value;
  return *this;
}

inline Natural::Reference Natural::operator=(ValueType &&value) {
  value_ = std::move(value);
  return *this;
}

template< typename U >
inline Natural::Reference Natural::operator=(const Number<U> &other) {
  value_ = static_cast<const U&>(other).value_;
  return *this;
}

template< typename U >
inline auto Natural::operator=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Natural::Reference Natural::operator+=(const ValueType &rhs) {
  value_ += rhs;
  return *this;
}

inline Natural::Reference Natural::operator+=(ValueType &&rhs) {
  value_ += std::move(rhs);
  return *this;
}

inline Natural::Reference Natural::operator+=(ConstRef rhs) {
  value_ += rhs.value_;
  return *this;
}

template< typename U >
inline Natural::Reference Natural::operator+=(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Natural::operator+=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_add_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------

inline Natural::Reference Natural::operator*=(const ValueType &rhs) {
  value_ *= rhs;
  return *this;
}

inline Natural::Reference Natural::operator*=(ValueType &&rhs) {
  value_ *= std::move(rhs);
  return *this;
}

inline Natural::Reference Natural::operator*=(ConstRef rhs) {
  value_ *= rhs.value_;
  return *this;
}

template< typename U >
inline Natural::Reference Natural::operator*=(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
  return *this;
}

template< typename U >
inline auto Natural::operator*=(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>, Reference> {
  assign_mul_(*this, rhs);
  return *this;
}

// -----------------------------------------------------------------------------
// Member Function Definitions
inline decltype(auto) Natural::value() const {
  return value_;
}

// -----------------------------------------------------------------------------
// Assign
inline void Natural::assign(ConstRef rhs) {
  value_ = rhs.value_;
}

template< typename U >
inline void Natural::assign(const Number<U> &rhs) {
  value_ = static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Natural::assign(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Addition
inline void Natural::assign_add(ConstRef rhs) {
  value_ += rhs.value_;
}

template< typename U >
inline auto Natural::assign_add(const Number<U> &rhs) {
  value_ += static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Natural::assign_add(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_add_(*this, eval(rhs));
}

// -----------------------------------------------------------------------------
// Assign Multiplication
inline void Natural::assign_mul(ConstRef rhs) {
  value_ *= rhs.value_;
}

template< typename U >
inline auto Natural::assign_mul(const Number<U> &rhs) {
  value_ *= static_cast<const U&>(rhs).value();
}

template< typename U >
inline auto Natural::assign_mul(const U &rhs)
-> EnableIf_t<IsCovariantResult<This, U>> {
  assign_mul_(*this, eval(rhs));
}

} // sym

#endif // SYMMATH_NUMERICS_NATURAL_HPP
