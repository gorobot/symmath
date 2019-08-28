#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../symmath/symmath.hpp"

TEST_CASE("SymMath", "[symmath]") {
  REQUIRE(sym::test() == 1);
}
