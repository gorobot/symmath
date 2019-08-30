#include <catch2/catch.hpp>

#include <complex>

#include "../symmath/numerics.hpp"

using namespace std::complex_literals;

TEST_CASE("Complex: operations", "[numerics]") {
  sym::Complex a(2.0, 1.0);
  sym::Complex b(1.0, 3.0);

  SECTION("should be able to add") {
    sym::Complex result;
    result = a + b;
    // REQUIRE(result == 3.0 + 4.0i);
    // result = a + 1.0i;
  }

  SECTION("should be able to divide") {
    sym::Complex result;
    result = a / b;
    // REQUIRE(result == 3.0 + 4.0i);
    // result = a / 1.0i;
  }

  SECTION("should be able to multiply") {
    sym::Complex result;
    result = a * b;
    // REQUIRE(result == 3.0 + 4.0i);
    // result = a * 1.0i;
  }

  SECTION("should be able to subtract") {
    sym::Complex result;
    result = a - b;
    // REQUIRE(result == 3.0 + 4.0i);
    // result = a - 1.0i;
  }
}
