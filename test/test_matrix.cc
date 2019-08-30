#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Matrix: operations",
  "[numerics]",
  sym::Natural,
  sym::Integer,
  sym::Real) {

  // sym::Matrix<TestType> a({1, 2, 3});
  // sym::Matrix<TestType> b({0, 1, 2});

  SECTION("should be able to add") {
    sym::Matrix<TestType> result;
    // result = a + b;
  }

  SECTION("should be able to divide") {
    sym::Matrix<TestType> result;
    // result = a / b;
  }

  SECTION("should be able to multiply") {
    sym::Matrix<TestType> result;
    // result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Matrix<TestType> result;
    // result = a - b;
  }
}
