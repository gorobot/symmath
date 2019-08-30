#ifndef SYMMATH_VARIABLE_VARIABLE_HPP
#define SYMMATH_VARIABLE_VARIABLE_HPP

#include "../symbolic.hpp"

namespace sym {

// -----------------------------------------------------------------------------

class Variable
  : public Symbolic<Variable> {
private:

  std::string name_;

public:

  explicit inline Variable();
  inline Variable(const std::string name);

};

// -----------------------------------------------------------------------------
// Constructor
Variable::Variable() {

}

} // sym

#endif // SYMMATH_VARIABLE_VARIABLE_HPP
