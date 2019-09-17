#ifndef SYMMATH_EXPRESSION_VARIABLE_HPP
#define SYMMATH_EXPRESSION_VARIABLE_HPP

#include <memory>

namespace sym {

// -----------------------------------------------------------------------------

class Variable {
private:

  struct Concept {
    inline virtual ~Concept() = default;

    // inline void assign(const double &rhs);
    // inline void assign_add(const double &rhs);
  };

  template< typename T >
  struct Model final
    : public Concept {

    T data_;

    Model(T data)
      : data_(data) {}

    // inline void assign(const double &rhs);
    // inline void assign_add(const double &rhs);

  };

  std::shared_ptr<const Concept> ptr_;

public:

  explicit inline Variable();

  template< typename T >
  inline Variable(const T &obj);

  template< typename T >
  inline Variable &operator=(const T &obj);
  template< typename T >
  inline Variable &operator=(T &&obj);

};

// -----------------------------------------------------------------------------
// Constructor
Variable::Variable() {}

template< typename T >
Variable::Variable(const T &obj)
  : ptr_(std::make_shared<Model<T>>(std::move(obj))) {}

template< typename T >
inline Variable &Variable::operator=(const T &obj) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(obj);
  return *this;
}

template< typename T >
inline Variable &Variable::operator=(T &&obj) {
  ptr_.reset();
  ptr_ = std::make_shared<Model<T>>(std::move(obj));
  return *this;
}

} // sym

#endif // SYMMATH_EXPRESSION_VARIABLE_HPP
