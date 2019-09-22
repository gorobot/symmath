#include <catch2/catch.hpp>

#include <symmath/numerics/real.hpp>
#include <symmath/numerics/variable.hpp>

TEST_CASE("Variables: operations", "[numerics]") {
  sym::Real a(1.0);
  sym::Variable<sym::Real> x(2.0);
  sym::Variable<sym::Real> y(1.0);

  // REQUIRE(a == y);

  // z = x + y;

  SECTION("should be able to assign") {
    sym::Variable<sym::Real> z(a);
    REQUIRE(z == a);
    REQUIRE(z == 1.0);
  }

  SECTION("should be able to assign") {
    sym::Variable<sym::Real> z(a);
    REQUIRE(z == a);
    REQUIRE(a == 1.0);
    REQUIRE(z == 1.0);
    a = 5.0;
    REQUIRE(a == 5.0);
    REQUIRE(z == 5.0);
  }

  SECTION("should be able to assign") {
    sym::Variable<sym::Real> z;
    z = a;
    REQUIRE(z == a);
  }

  SECTION("should be able to assign") {
    sym::Variable<sym::Real> z;
    z = x;
    REQUIRE(z == x);
    // REQUIRE(z == 2.0);
  }

  SECTION("should be able to assign") {
    sym::Variable<sym::Real> z;
    z = x + a;
    // REQUIRE(z == 3.0);
    // a = 3.0;
    // REQUIRE(z == 5.0);
  }

}
