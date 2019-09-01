#include <catch2/catch.hpp>

#include "../symmath/properties/dummy.hpp"

TEST_CASE("Integer: operations", "[dummy]") {
  sym::Foo a(2);
  sym::Foo b(1);

  sym::Bar c(2);
  sym::Bar d(1);

  SECTION("should be able to add Foo") {
    sym::Foo result;
    result = a + b;
    REQUIRE(result == 3);
    result += b;
    REQUIRE(result == 4);
    result += 1;
    REQUIRE(result == 5);
    result = a + 1;
    REQUIRE(result == 3);
    result = 2 + b;
    REQUIRE(result == 3);
  }

  SECTION("should be able to add Bar") {
    sym::Bar result;
    result = c + d;
    REQUIRE(result == 3);
    result += d;
    REQUIRE(result == 4);
    result += 1;
    REQUIRE(result == 5);
    result = c + 1;
    REQUIRE(result == 3);
    result = 2 + d;
    REQUIRE(result == 3);
  }

  SECTION("should be able to multiply Foo") {
    sym::Foo result;
    result = a * b;
    REQUIRE(result == 2);
    result *= b;
    REQUIRE(result == 2);
    result *= 1;
    REQUIRE(result == 2);
    result = a * 1;
    REQUIRE(result == 2);
    result = 2 * b;
    REQUIRE(result == 2);
  }

  SECTION("should be able to multiply Bar") {
    sym::Bar result;
    result = c * d;
    REQUIRE(result == 2);
    result *= d;
    REQUIRE(result == 2);
    result *= 1;
    REQUIRE(result == 2);
    result = c * 1;
    REQUIRE(result == 2);
    result = 2 * d;
    REQUIRE(result == 2);
  }

  // SECTION("should not be able to add") {
  //   sym::Bar result;
  //   result = a + d;
  //   std::cout << result << '\n';
  // }
}
