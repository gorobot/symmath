#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

TEMPLATE_TEST_CASE(
  "Vector: operations",
  "[numerics]",
  sym::Natural,
  sym::Integer,
  sym::Real) {

  sym::Vector<TestType> a({1, 2, 3});
  sym::Vector<TestType> b({0, 1, 2});

  SECTION("should be able to add") {
    sym::Vector<TestType> result;
    // result = a + b;
  }

  SECTION("should be able to divide") {
    sym::Vector<TestType> result;
    // result = a / b;
  }

  SECTION("should be able to multiply") {
    sym::Vector<TestType> result;
    // result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Vector<TestType> result;
    // result = a - b;
  }
}
