#ifndef SYMMATH_EXPRESSION_EXPRESSION_HPP
#define SYMMATH_EXPRESSION_EXPRESSION_HPP

#include <memory>
#include <string>
#include <utility>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Expression {
public:

  using ResultType = Expression;

private:

  struct Concept;

  template< typename T >
  struct Model;

  class BaseVisitor {
  public:

    virtual ~BaseVisitor() = default;

    template< typename U >
    void visit(U &lhs) {
      // apply_(lhs, data_);
    }

  };

  template< typename T >
  class Visitor
    : public BaseVisitor {
  public:

    T data_;

    Visitor(T data)
      : data_(data) {}

  };

  class Concept {
  public:

    virtual ~Concept() = default;

    template< typename T >
    void apply(T &m) const {
      auto v = get_visitor();
      // decltype(v)::show;
    }

  private:

    virtual BaseVisitor &get_visitor() const = 0;

  };

  template< typename T >
  class Model final
    : public Concept {
  private:

    T data_;

  public:

    Model(T data)
      : data_(data) {}

    Visitor<T> &get_visitor() const override {
      return Visitor<T>(data_);
    }

  };

  std::shared_ptr<const Concept> ptr_;

public:

  template< typename T >
  inline Expression &operator=(const Symbolic<T> &rhs);

  inline auto eval() const -> const ResultType;

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Expression<U> &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    // auto v = rhs.ptr_->get_visitor();

  }

};

// -----------------------------------------------------------------------------
// Constructor
template< typename T >
inline Expression &Expression::operator=(const Symbolic<T> &rhs) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(std::move(rhs.derived()));
  return *this;
}

} // sym

#endif // SYMMATH_EXPRESSION_EXPRESSION_HPP
