#include <catch2/catch.hpp>

#include <symmath/numerics/integer.hpp>

using namespace sym;

TEST_CASE("Integer: operations", "[numerics]") {
  Integer a(1);
  Integer b(2);
  Integer c(3);
  Integer d(4);

  SECTION("should be able to add integers") {
    Integer result;
    result = a + b;
    REQUIRE(result == 3);
    result = a + b + c;
    REQUIRE(result == 6);
    result = a + b + c + d;
    REQUIRE(result == 10);
  }

  SECTION("should be able to add basic number types") {
    Integer result;
    result = a + 1;
    REQUIRE(result == 2);
    result = 1 + b;
    REQUIRE(result == 3);

    result = a + 1 + c;
    REQUIRE(result == 5);
    result = 1 + b + c;
    REQUIRE(result == 6);
    result = a + b + 1;
    REQUIRE(result == 4);

    result = 1 + b + c + d;
    REQUIRE(result == 10);
    result = a + 1 + c + d;
    REQUIRE(result == 9);
    result = a + b + 1 + d;
    REQUIRE(result == 8);
    result = a + b + c + 1;
    REQUIRE(result == 7);
  }

  SECTION("should be able to add assign") {
    Integer result(a);
    result += b;
    REQUIRE(result == 3);
  }

  SECTION("should be able to add assign basic number types") {
    Integer result(a);
    result += 1;
    REQUIRE(result == 2);
  }

  SECTION("should be able to multiply integers") {
    Integer result;
    result = a * b;
    REQUIRE(result == 2);
    result = a * b * c;
    REQUIRE(result == 6);
    result = a * b * c * d;
    REQUIRE(result == 24);
  }

  SECTION("should be able to multiply basic number types") {
    Integer result;
    result = 1 * b;
    REQUIRE(result == 2);
    result = a * 2;
    REQUIRE(result == 2);

    result = 1 * b * c;
    REQUIRE(result == 6);
    result = a * 2 * c;
    REQUIRE(result == 6);
    result = a * b * 3;
    REQUIRE(result == 6);

    result = 1 * b * c * d;
    REQUIRE(result == 24);
    result = a * 2 * c * d;
    REQUIRE(result == 24);
    result = a * b * 3 * d;
    REQUIRE(result == 24);
    result = a * b * c * 4;
    REQUIRE(result == 24);
  }

  SECTION("should be able to multiply assign") {
    Integer result(a);
    result *= b;
    REQUIRE(result == 2);
  }

  SECTION("should be able to multiply assign basic number types") {
    Integer result(a);
    result *= 2;
    REQUIRE(result == 2);
  }

  SECTION("should be able to subtract integers") {
    Integer result;
    result = a - b;
    REQUIRE(result == -1);
    result = a - b - c;
    REQUIRE(result == -4);
    result = a - b - c - d;
    REQUIRE(result == -8);
  }

  SECTION("should be able to subtract basic number types") {
    Integer result;
    result = 1 - b;
    REQUIRE(result == -1);
    result = a - 2;
    REQUIRE(result == -1);

    result = 1 - b - c;
    REQUIRE(result == -4);
    result = a - 2 - c;
    REQUIRE(result == -4);
    result = a - b - 3;
    REQUIRE(result == -4);

    result = 1 - b - c - d;
    REQUIRE(result == -8);
    result = a - 2 - c - d;
    REQUIRE(result == -8);
    result = a - b - 3 - d;
    REQUIRE(result == -8);
    result = a - b - c - 4;
    REQUIRE(result == -8);
  }

  SECTION("should be able to subtract assign") {
    Integer result(a);
    result -= b;
    REQUIRE(result == -1);
  }

  SECTION("should be able to subtract assign basic number types") {
    Integer result(a);
    result -= 2;
    REQUIRE(result == -1);
  }

  SECTION("should be able to perform mixed operations") {
    sym::Integer result;
    result = a + (b * a) - b;
    REQUIRE(result == 1);
  }
}
