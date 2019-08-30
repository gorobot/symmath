// #define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <complex>

#include "../symmath/symmath.hpp"

TEST_CASE("Real: operations", "[numerics]") {
  sym::Real a(2.0);
  sym::Real b(1.0);

  SECTION("should be able to add") {
    sym::Real result;
    result = a + b;
  }

  SECTION("should be able to divide") {
    sym::Real result;
    result = a / b;
  }

  SECTION("should be able to multiply") {
    sym::Real result;
    result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Real result;
    result = a - b;
  }
}
