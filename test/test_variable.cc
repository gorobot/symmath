#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../symmath/symmath.hpp"
#include "../symmath/number/number.hpp"
#include "../symmath/variable/variable.hpp"

TEST_CASE("Number: Add", "[symmath]") {
  sym::Number<int> a(1);
  sym::Number<int> b(1);

  {
    sym::Variable result;
    result = a + b;
  }
}
