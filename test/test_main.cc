#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../symmath/symmath.hpp"

TEST_CASE("SymMath", "[symmath]") {
  REQUIRE(SymMath::test() == 1);
}
