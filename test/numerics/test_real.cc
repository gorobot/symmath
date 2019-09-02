#include <catch2/catch.hpp>

#include "../../symmath/numerics/real.hpp"

TEST_CASE("Real: operations", "[numerics]") {
  sym::Real a(2.0);
  sym::Real b(1.0);
  sym::Real c(5.0);

  SECTION("should be able to add") {
    sym::Real result;
    result = a + b;
    REQUIRE(result == 3.0);
    result = a + 1.0;
    REQUIRE(result == 3.0);
    result = 2.0 + b;
    REQUIRE(result == 3.0);
    result = a + b + c;
    REQUIRE(result == 8.0);
    result = 2.0 + b + c;
    REQUIRE(result == 8.0);
    result += b;
    REQUIRE(result == 9.0);
    result += 1.0;
    REQUIRE(result == 10.0);
  }

  SECTION("should be able to divide") {
    sym::Real result;
    result = a / b;
    REQUIRE(result == 2.0);
    result = a / 1.0;
    REQUIRE(result == 2.0);
    result = 2.0 / b;
    REQUIRE(result == 2.0);
    result = a / b / c;
    REQUIRE(result == 0.4);
    result = 2.0 / b / c;
    REQUIRE(result == 0.4);
    result /= b;
    REQUIRE(result == 0.4);
    result /= 1.0;
    REQUIRE(result == 0.4);
  }

  SECTION("should be able to multiply") {
    sym::Real result;
    result = a * b;
    REQUIRE(result == 2.0);
    result = a * 1.0;
    REQUIRE(result == 2.0);
    result = 2.0 * b;
    REQUIRE(result == 2.0);
    result = a * b * c;
    REQUIRE(result == 10.0);
    result = 2.0 * b * c;
    REQUIRE(result == 10.0);
    result *= b;
    REQUIRE(result == 10.0);
    result *= 1.0;
    REQUIRE(result == 10.0);

    result = a^b;
    REQUIRE(result == 2.0);
    result = a^2;
    REQUIRE(result == 4.0);
    result ^= 2;
    REQUIRE(result == 16.0);
  }

  SECTION("should be able to subtract") {
    sym::Real result;
    result = a - b;
    REQUIRE(result == 1.0);
    result = a - 1.0;
    REQUIRE(result == 1.0);
    result = 2.0 - b;
    REQUIRE(result == 1.0);
    result = a - b - c;
    REQUIRE(result == -4.0);
    result = 2.0 - b - c;
    REQUIRE(result == -4.0);
    result -= b;
    REQUIRE(result == -5.0);
    result -= 1.0;
    REQUIRE(result == -6.0);
  }

  SECTION("should be able to perform mixed operations") {
    sym::Real result;
    result = a + (b / (a * b)) - a;
    REQUIRE(result == 0.5);
  }
}
