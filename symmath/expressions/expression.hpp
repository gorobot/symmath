#ifndef SYMMATH_EXPRESSION_EXPRESSION_HPP
#define SYMMATH_EXPRESSION_EXPRESSION_HPP

#include <memory>
#include <string>

#include <symmath/type_traits/enable_if.hpp>

namespace sym {

// -----------------------------------------------------------------------------

class Expression {
public:



private:

                          struct Concept;
  template< typename T >  struct Model;

  std::shared_ptr<const Concept> lhs_;
  std::shared_ptr<const Concept> rhs_;

public:

  explicit inline Expression();

  template< typename T1, typename T2 >
  explicit inline Expression(const T1 &lhs, const T2 &rhs);

};

// -----------------------------------------------------------------------------
// Constructor
inline Expression::Expression()
  : lhs_(),
    rhs_() {}

template< typename T1,
          typename T2 >
inline Expression::Expression(const T1 &lhs, const T2 &rhs)
  : lhs_(std::make_shared<Model<T>>(lhs)),
    rhs_(std::make_shared<Model<T>>(rhs)) {}

// -----------------------------------------------------------------------------
// Concept
struct Expression::Concept {
  virtual ~Concept() = default;
};

// -----------------------------------------------------------------------------
// Model
template< typename T >
struct Expression::Model final
  : public Expression::Concept {

  const T &data_;

  inline Model(T data);

};

// -----------------------------------------------------------------------------
// Model Constructor
template< typename T >
inline Expression::Model<T>::Model(T data)
  : data_(data) {}

} // sym

#endif // SYMMATH_EXPRESSION_EXPRESSION_HPP
