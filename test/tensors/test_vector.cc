#include <catch2/catch.hpp>

#include "../../symmath/numerics/complex.hpp"
#include "../../symmath/numerics/real.hpp"
#include "../../symmath/tensors/vector.hpp"

TEMPLATE_TEST_CASE(
  "Vector: operations",
  "[tensors]",
  sym::Complex,
  sym::Real) {

  sym::Vector<TestType, 3> a(2.0);
  sym::Vector<TestType, 3> b(1.0);
  sym::Vector<TestType, 3> c(5.0);

  SECTION("should be able to add") {
    sym::Vector<TestType, 3> result;
    result = a + b;
    REQUIRE(result == sym::Vector<TestType, 3>(3.0));
    result = a + b + c;
    REQUIRE(result == sym::Vector<TestType, 3>(8.0));
  }

  SECTION("should be able to subtract") {
    sym::Vector<TestType, 3> result;
    result = a - b;
    REQUIRE(result == sym::Vector<TestType, 3>(1.0));
    result = a - b - c;
    REQUIRE(result == sym::Vector<TestType, 3>(-4.0));
  }

  SECTION("should be able to perform mixed operations") {
    sym::Vector<TestType, 3> result;
    result = a + b - c;
    REQUIRE(result == sym::Vector<TestType, 3>(-2.0));
  }
}
