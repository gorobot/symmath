#ifndef SYMMATH_VARIABLE_VARIABLE_HPP
#define SYMMATH_VARIABLE_VARIABLE_HPP

#include <memory>
#include <string>
#include <utility>

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Variable
  : public Symbolic<Variable> {
private:

  struct Concept;
  template< typename T > struct Model;

  struct ApplyVisitor {

    void visit(const Concept &rhs) {}

    template< typename U >
    void visit(const Model<U> &rhs) {

    }

  };

  struct Concept {
    virtual ~Concept() = default;

    virtual void apply_to(ApplyVisitor &v) const = 0;
  };

  template< typename T >
  class Model final
    : public Concept {
  private:

    T data_;

  public:

    Model(T data)
      : data_(data) {}

    void apply_to(ApplyVisitor &v) const override {
      v.visit(*this);
    }

  };

  std::shared_ptr<const Concept> ptr_;

  std::string name_;

public:

  explicit inline Variable();
  inline Variable(const std::string name);

  template< typename T >
  inline Variable &operator=(const Symbolic<T> &rhs);

private:

  template< typename U >
  friend inline auto
  apply_(U &lhs, const Variable &rhs)
  -> std::enable_if_t<is_symbolic<U>{}> {
    ApplyVisitor v;
    rhs.ptr_->apply_to(v);
  }

};

// -----------------------------------------------------------------------------
// Constructor
Variable::Variable() {

}

// -----------------------------------------------------------------------------
// Member Function Definitions
template< typename T >
inline Variable &Variable::operator=(const Symbolic<T> &rhs) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(std::move(rhs.derived()));
  return *this;
}

} // sym

#endif // SYMMATH_VARIABLE_VARIABLE_HPP
