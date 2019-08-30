#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Scalar: operations",
  "[numerics]",
  sym::Natural,
  sym::Integer,
  sym::Real) {

  // sym::Scalar<TestType> a({1, 2, 3});
  // sym::Scalar<TestType> b({0, 1, 2});

  SECTION("should be able to add") {
    sym::Scalar<TestType> result;
    // result = a + b;
  }

  SECTION("should be able to divide") {
    sym::Scalar<TestType> result;
    // result = a / b;
  }

  SECTION("should be able to multiply") {
    sym::Scalar<TestType> result;
    // result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Scalar<TestType> result;
    // result = a - b;
  }
}
