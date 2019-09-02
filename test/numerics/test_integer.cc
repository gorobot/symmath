#include <catch2/catch.hpp>

#include "../../symmath/numerics/integer.hpp"

TEST_CASE("Integer: operations", "[numerics]") {
  sym::Integer a(2);
  sym::Integer b(1);
  sym::Integer c(5);

  SECTION("should be able to add") {
    sym::Integer result;
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
    sym::Integer result;
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

  SECTION("should be able to subtract") {
    sym::Integer result;
    result = a - b;
    REQUIRE(result == 1);
    result = a - 1;
    REQUIRE(result == 1);
    result = 2 - b;
    REQUIRE(result == 1);
    result = a - b - c;
    REQUIRE(result == -4);
    result = 2 - b - c;
    REQUIRE(result == -4);
    result -= b;
    REQUIRE(result == -5);
    result -= 1;
    REQUIRE(result == -6);
  }

  SECTION("should be able to perform mixed operations") {
    sym::Integer result;
    result = a + (b * a) - b;
    REQUIRE(result == 3);
  }
}
