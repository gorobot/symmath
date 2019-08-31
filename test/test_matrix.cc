#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Matrix: operations",
  "[numerics]",
  sym::Real) {

  sym::Matrix<TestType, 2, 2> a({1, 2, 3, 4});
  sym::Matrix<TestType, 2, 2> b({0, 1, 2, 3});

  SECTION("should be able to add") {
    sym::Matrix<TestType, 2, 2> result;
    // result = a + b;
  }

  SECTION("should be able to multiply") {
    sym::Matrix<TestType, 2, 2> result;
    // result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Matrix<TestType, 2, 2> result;
    // result = a - b;
  }
}
