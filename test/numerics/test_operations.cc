#include <catch2/catch.hpp>

#include <symmath/numerics.hpp>

using namespace sym;

TEMPLATE_TEST_CASE("Operations: absolute value", "[numerics]", Real) {
  TestType a(1.0);
  TestType b(-2.0);

  SECTION("should be able to compute absolute value") {
    TestType result;
    result = abs(a);
    REQUIRE(result == 1.0);
    result = abs(b);
    REQUIRE(result == 2.0);

    result = abs(abs(a));
    REQUIRE(result == 1.0);

    result = abs(abs(abs(a)));
    REQUIRE(result == 1.0);

    result = abs(a + b);
    REQUIRE(result == 1.0);
    result = abs(a / b);
    REQUIRE(result == 0.5);
    result = abs(a * b);
    REQUIRE(result == 2.0);
    result = abs(a - b);
    REQUIRE(result == 3.0);
  }
}
