#include <catch2/catch.hpp>

#include <type_traits>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Matrix: operations",
  "[numerics]",
  sym::Real) {

  sym::Matrix<TestType, 2, 2> a({1, 2, 3, 4});
  sym::Matrix<TestType, 2, 2> b({0, 1, 2, 3});

  sym::Scalar<TestType> x({2});
  sym::Vector<TestType, 1> y(x);

  SECTION("should be able to add") {
    sym::Matrix<TestType, 2, 2> result;
    result = a + b;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({1, 3, 5, 7}));
  }

  SECTION("should be able to multiply") {
    sym::Scalar<TestType> s(2);
    sym::Matrix<TestType, 2, 2> result;
    result = a * s;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({2, 4, 6, 8}));
  }

  SECTION("should be able to subtract") {
    sym::Matrix<TestType, 2, 2> result;
    result = a - b;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({1, 1, 1, 1}));
  }
}
