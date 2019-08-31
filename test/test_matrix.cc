#include <catch2/catch.hpp>

#include <type_traits>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Matrix: operations",
  "[numerics]",
  sym::Real) {

  sym::Matrix<TestType, 2, 2> a({1.0, 2.0, 3.0, 4.0});
  sym::Matrix<TestType, 2, 2> b({0.0, 1.0, 2.0, 3.0});
  sym::Matrix<TestType, 2, 2> c({0.0, 0.0, 1.0, 2.0});

  // sym::Scalar<TestType> x({2});
  // sym::Vector<TestType, 1> y(x);

  SECTION("should be able to add") {
    sym::Matrix<TestType, 2, 2> result;
    result = a + b;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({1.0, 3.0, 5.0, 7.0}));
    result = a + b + c;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({1.0, 3.0, 6.0, 9.0}));
  }

  SECTION("should be able to multiply by a scalar") {
    sym::Scalar<TestType> s(2);
    sym::Matrix<TestType, 2, 2> result;
    result = a * s;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({2.0, 4.0, 6.0, 8.0}));
  }

  SECTION("should be able to subtract") {
    sym::Matrix<TestType, 2, 2> result;
    result = a - b;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({1.0, 1.0, 1.0, 1.0}));
    result = a - b - c;
    REQUIRE(result == sym::Matrix<TestType, 2, 2>({1.0, 1.0, 0.0, -1.0}));
  }
}
