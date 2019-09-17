#include <catch2/catch.hpp>

#include "../../symmath/expressions/variable.hpp"

TEST_CASE("Variables: operations", "[numerics]") {
  sym::Variable x;

  SECTION("should be able to assign") {
    x = 3;
  }

}
