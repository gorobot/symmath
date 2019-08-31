#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Vector: operations",
  "[numerics]",
  sym::Real) {

  sym::Vector<TestType, 3> a({1.0, 2.0, 3.0});
  sym::Vector<TestType, 3> b({0.0, 1.0, 2.0});
  sym::Vector<TestType, 3> c({0.0, 0.0, 1.0});

  SECTION("should be able to add") {
    sym::Vector<TestType, 3> result;
    result = a + b;
    REQUIRE(result == sym::Vector<TestType, 3>({1.0, 3.0, 5.0}));
    result = a + b + c;
    REQUIRE(result == sym::Vector<TestType, 3>({1.0, 3.0, 6.0}));
  }

  SECTION("should be able to add scalars") {
    sym::Vector<TestType, 3> result;
    // result = a + 1.0;
    // REQUIRE(result == sym::Vector<TestType, 3>({2.0, 3.0, 4.0}));
    // result = 1.0 + b;
    // REQUIRE(result == sym::Vector<TestType, 3>({1.0, 2.0, 3.0}));
    // result = 2.0 + b + c;
    // REQUIRE(result == sym::Vector<TestType, 3>({2.0, 3.0, 5.0}));
  }

  SECTION("should be able to multiply by a scalar") {
    sym::Scalar<TestType> s(2.0);
    sym::Vector<TestType, 3> result;
    result = a * s;
    REQUIRE(result == sym::Vector<TestType, 3>({2.0, 4, 6}));
  }

  SECTION("should be able to subtract") {
    sym::Vector<TestType, 3> result;
    result = a - b;
    REQUIRE(result == sym::Vector<TestType, 3>({1.0, 1.0, 1.0}));
    result = a - b - c;
    REQUIRE(result == sym::Vector<TestType, 3>({1.0, 1.0, 0.0}));
  }
}
