#include <catch2/catch.hpp>

#include <symmath/numerics/natural.hpp>

using namespace sym;

TEST_CASE("Natural: addition", "[numerics]") {
  sym::Natural a(1);
  sym::Natural b(2);
  sym::Natural c(3);
  sym::Natural d(4);

  SECTION("should be able to add naturals") {
    Natural result;
    result = a + b;
    REQUIRE(result == 3);
    result = a + b + c;
    REQUIRE(result == 6);
    result = a + b + c + d;
    REQUIRE(result == 10);
  }

  SECTION("should be able to add basic number types") {
    Natural result;
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
    Natural result(a);
    result += b;
    REQUIRE(result == 3);
  }

  SECTION("should be able to add assign basic number types") {
    Natural result(a);
    result += 1;
    REQUIRE(result == 2);
  }
}

TEST_CASE("Natural: multiplication", "[numerics]") {
  sym::Natural a(1);
  sym::Natural b(2);
  sym::Natural c(3);
  sym::Natural d(4);

  SECTION("should be able to multiply naturals") {
    Natural result;
    result = a * b;
    REQUIRE(result == 2);
    result = a * b * c;
    REQUIRE(result == 6);
    result = a * b * c * d;
    REQUIRE(result == 24);
  }

  SECTION("should be able to multiply basic number types") {
    Natural result;
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
    Natural result(a);
    result *= b;
    REQUIRE(result == 2);
  }

  SECTION("should be able to multiply assign basic number types") {
    Natural result(a);
    result *= 2;
    REQUIRE(result == 2);
  }
}

TEST_CASE("Natural: mixed operations", "[numerics]") {
  sym::Natural a(1);
  sym::Natural b(2);
  sym::Natural c(3);
  sym::Natural d(4);

  SECTION("should be able to perform mixed arithmetic operations") {
    Natural result;
    result = a + (b * a);
    REQUIRE(result == 3);
  }
}
