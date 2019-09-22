#include <catch2/catch.hpp>

#include "../../symmath/expressions/variable.hpp"

TEST_CASE("Variables: operations", "[numerics]") {
  sym::Variable x;
  sym::Variable y;

  SECTION("should be able to assign") {
    x = 3;
    // y = x + 2;
    sym::dummy(x);
  }

}
