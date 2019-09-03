#include <catch2/catch.hpp>

#include <complex>

#include "../../symmath/numerics/complex.hpp"

using namespace std::complex_literals;

TEST_CASE("Complex: operations", "[numerics]") {
  sym::Complex a(2.0 + 2.0i);
  sym::Complex b(1.0 + 1.0i);

  SECTION("should be able to add") {
    sym::Complex result;
    result = a + b;
    REQUIRE(result == 3.0 + 3.0i);
    result = a + (1.0 + 1.0i);
    REQUIRE(result == 3.0 + 3.0i);
    result = (2.0 + 2.0i) + b;
    REQUIRE(result == 3.0 + 3.0i);
    // result = a + 1.0i;
  }

  SECTION("should be able to divide") {
    sym::Complex result;
    result = a / b;
    REQUIRE(result == 2.0 + 0.0i);
    result = a / (1.0 + 1.0i);
    REQUIRE(result == 2.0 + 0.0i);
    result = (2.0 + 2.0i) / b;
    REQUIRE(result == 2.0 + 0.0i);
    // result = a / 1.0i;
  }

  SECTION("should be able to multiply") {
    sym::Complex result;
    result = a * b;
    REQUIRE(result == 0.0 + 4.0i);
    result = a * (1.0 + 1.0i);
    REQUIRE(result == 0.0 + 4.0i);
    result = (2.0 + 2.0i) * b;
    REQUIRE(result == 0.0 + 4.0i);
    // result = a * 1.0i;

    result = inv(a);
    REQUIRE(result == 0.25 - 0.25i);
  }

  SECTION("should be able to subtract") {
    sym::Complex result;
    result = a - b;
    REQUIRE(result == 1.0 + 1.0i);
    result = a - (1.0 + 1.0i);
    REQUIRE(result == 1.0 + 1.0i);
    result = (2.0 + 2.0i) - b;
    REQUIRE(result == 1.0 + 1.0i);
    // result = a - 1.0i;

    result = -a + b;
    REQUIRE(result == -1.0 - 1.0i);
    result = a - -b;
    REQUIRE(result == 3.0 + 3.0i);
  }
}
