#include <catch2/catch.hpp>

#include <symmath/numerics.hpp>

using namespace sym;

TEST_CASE("Function: one variable", "[functions]") {
  Real a(1.0);
  Real b(2.0);
  Variable<Real> x;

  Function<Real, Real> f(x);
  f = a*x;

  SECTION("should accept rvalues") {
    Real result;
    result = f(2.0);
    REQUIRE(result == 2.0);
  }

  SECTION("should accept lvalues") {
    Real result;
    result = f(b);
    REQUIRE(result == 2.0);
  }

  SECTION("should change if underlying value changes") {
    Real result;

    a = 2.0;

    result = f(2.0);
    REQUIRE(result == 4.0);
    result = f(b);
    REQUIRE(result == 4.0);
  }

}

TEST_CASE("Function: two variables", "[functions]") {
  Real a(1.0);
  Real b(2.0);
  Real c(3.0);
  Real d(4.0);
  Variable<Real> x;
  Variable<Real> y;

  Function<Real, Real, Real> f(x, y);
  f = a*x + b*y;

  SECTION("should accept rvalues") {
    Real result;
    result = f(3.0, 4.0);
    REQUIRE(result == 11.0);
  }

  SECTION("should accept lvalues") {
    Real result;
    result = f(c, d);
    REQUIRE(result == 11.0);
  }

  SECTION("should change if underlying value changes") {
    Real result;

    a = 2.0;

    result = f(3.0, 4.0);
    REQUIRE(result == 14.0);
    result = f(c, d);
    REQUIRE(result == 14.0);
  }

}
