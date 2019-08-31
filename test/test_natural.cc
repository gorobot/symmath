#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"

TEST_CASE("Naturals: operations", "[numerics]") {
  sym::Natural a(2);
  sym::Natural b(1);
  sym::Natural c(5);

  SECTION("should be able to add") {
    sym::Natural result;
    result = a + b;
    REQUIRE(result == 3);
    result = a + 1;
    REQUIRE(result == 3);
    result = 2 + b;
    REQUIRE(result == 3);
    result = a + b + c;
    REQUIRE(result == 8);
    result = 2 + b + c;
    REQUIRE(result == 8);
    result += b;
    REQUIRE(result == 9);
    result += 1;
    REQUIRE(result == 10);
  }

  SECTION("should be able to multiply") {
    sym::Natural result;
    result = a * b;
    REQUIRE(result == 2);
    result = a * 1;
    REQUIRE(result == 2);
    result = 2 * b;
    REQUIRE(result == 2);
    result = a * b * c;
    REQUIRE(result == 10);
    result = 2 * b * c;
    REQUIRE(result == 10);
    result *= b;
    REQUIRE(result == 10);
    result *= 1;
    REQUIRE(result == 10);
  }
}
