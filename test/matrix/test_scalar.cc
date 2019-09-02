#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Scalar: operations",
  "[numerics]",
  sym::Real) {

  sym::Scalar<TestType> a(2.0);
  sym::Scalar<TestType> b(1.0);
  sym::Scalar<TestType> c(5.0);

  SECTION("should be able to add") {
    sym::Scalar<TestType> result;
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
    sym::Scalar<TestType> result;
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
    sym::Scalar<TestType> result;
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
  }

  SECTION("should be able to subtract") {
    sym::Scalar<TestType> result;
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
}
