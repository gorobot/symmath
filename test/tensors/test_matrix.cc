#include <catch2/catch.hpp>

#include <symmath/numerics/complex.hpp>
#include <symmath/numerics/real.hpp>
#include <symmath/tensors/matrix.hpp>

TEMPLATE_TEST_CASE(
  "Matrix: operations",
  "[tensors]",
  sym::Complex,
  sym::Real) {

  sym::Matrix<TestType, 2, 2> a(2.0);
  sym::Matrix<TestType, 2, 2> b(1.0);
  sym::Matrix<TestType, 2, 2> c(5.0);

  SECTION("should be able to add") {
    sym::Matrix<TestType, 2, 2> result;
    result = a + b;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>(3.0));
    result = a + b + c;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>(8.0));
  }

  SECTION("should be able to subtract") {
    sym::Matrix<TestType, 2, 2> result;
    result = a - b;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>(1.0));
    result = a - b - c;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>(-4.0));
  }

  SECTION("should be able to perform mixed operations") {
    sym::Matrix<TestType, 2, 2> result;
    result = a + b - c;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>(-2.0));
  }
}
