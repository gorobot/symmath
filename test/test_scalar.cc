#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Scalar: operations",
  "[numerics]",
  sym::Natural,
  sym::Integer,
  sym::Real) {

  // sym::Scalar<TestType> a(2);
  // sym::Scalar<TestType> b(1);

  SECTION("should be able to add") {
    sym::Scalar<TestType> result;
    // result = a + b;
    // REQUIRE(result == 3);
  }

  SECTION("should be able to divide") {
    sym::Scalar<TestType> result;
    // result = a / b;
    // REQUIRE(result == 2);
  }

  SECTION("should be able to multiply") {
    sym::Scalar<TestType> result;
    // result = a * b;
    // REQUIRE(result == 2);
  }

  SECTION("should be able to subtract") {
    sym::Scalar<TestType> result;
    // result = a - b;
    // REQUIRE(result == 1);
  }
}
