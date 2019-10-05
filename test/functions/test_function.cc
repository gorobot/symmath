#include <catch2/catch.hpp>

#include <iostream>

#include <symmath/numerics.hpp>

using namespace sym;

TEST_CASE("Function: playground", "[functions]") {

  Real a(1.0);
  Real b(2.0);
  Variable<Real> x(1.0);
  Variable<Real> y(2.0);

  // std::cout << x << '\n';

  Function<Real, Real> f(x);

  f = a*x + y;

  // SECTION("should be able to evaluate")

  Real result;
  result = f(a);
  REQUIRE(result == 3.0);
  result = f(2.0);
  REQUIRE(result == 4.0);

  std::cout << result << '\n';
  std::cout << x << '\n';
  std::cout << y << '\n';

}
