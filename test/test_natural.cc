// #define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <complex>

#include "../symmath/symmath.hpp"

TEST_CASE("Naturals: operations", "[numerics]") {
  sym::Natural a(2);
  sym::Natural b(1);

  SECTION("should be able to add") {
    sym::Natural result;
    result = a + b;
  }

  SECTION("should be able to multiply") {
    sym::Natural result;
    result = a * b;
  }
}
