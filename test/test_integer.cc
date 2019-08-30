// #define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <complex>

#include "../symmath/symmath.hpp"

TEST_CASE("Integer: operations", "[numerics]") {
  sym::Integer a(2);
  sym::Integer b(1);

  SECTION("should be able to add") {
    sym::Integer result;
    result = a + b;
  }

  SECTION("should be able to multiply") {
    sym::Integer result;
    result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Integer result;
    result = a - b;
  }
}
