#include <catch2/catch.hpp>

#include <symmath/numerics/real.hpp>

using namespace sym;

TEST_CASE("Real: properties", "[numerics]") {

  REQUIRE(HasProperty<Real, Addition>{});
  REQUIRE(HasProperty<Real, AssociativeProperty<Addition>>{});
  REQUIRE(HasProperty<Real, ClosureProperty<Addition>>{});
  REQUIRE(HasProperty<Real, CommutativeProperty<Addition>>{});
  REQUIRE(HasProperty<Real, DistributiveProperty<Addition>>{});
  REQUIRE(HasProperty<Real, IdentityElement<Addition>>{});
  REQUIRE(HasProperty<Real, InverseElement<Addition>>{});
  REQUIRE(HasProperty<Real, Multiplication>{});
  REQUIRE(HasProperty<Real, AssociativeProperty<Multiplication>>{});
  REQUIRE(HasProperty<Real, ClosureProperty<Multiplication>>{});
  REQUIRE(HasProperty<Real, CommutativeProperty<Multiplication>>{});
  REQUIRE(HasProperty<Real, DistributiveProperty<Multiplication>>{});
  REQUIRE(HasProperty<Real, IdentityElement<Multiplication>>{});
  REQUIRE(HasProperty<Real, InverseElement<Multiplication>>{});
  REQUIRE(HasProperty<Real, TotalOrder>{});

}

TEST_CASE("Real: operations", "[numerics]") {
  Real a(1.0);
  Real b(2.0);
  Real c(3.0);
  Real d(4.0);

  SECTION("should be able to add reals") {
    Real result;
    result = a + b;
    REQUIRE(result == 3.0);
    result = a + b + c;
    REQUIRE(result == 6.0);
    result = a + b + c + d;
    REQUIRE(result == 10.0);
  }

  SECTION("should be able to add basic number types") {
    Real result;
    result = a + 1.0;
    REQUIRE(result == 2.0);
    result = 1.0 + b;
    REQUIRE(result == 3.0);

    result = a + 1.0 + c;
    REQUIRE(result == 5.0);
    result = 1.0 + b + c;
    REQUIRE(result == 6.0);
    result = a + b + 1.0;
    REQUIRE(result == 4.0);

    result = 1.0 + b + c + d;
    REQUIRE(result == 10.0);
    result = a + 1.0 + c + d;
    REQUIRE(result == 9.0);
    result = a + b + 1.0 + d;
    REQUIRE(result == 8.0);
    result = a + b + c + 1.0;
    REQUIRE(result == 7.0);
  }

  SECTION("should be able to add assign") {
    Real result(a);
    result += b;
    REQUIRE(result == 3.0);
  }

  SECTION("should be able to add assign basic number types") {
    Real result(a);
    result += 1.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide reals") {
    Real result;
    result = b / a;
    REQUIRE(result == 2.0);
    result = d / b / a;
    REQUIRE(result == 2.0);
    result = d / b / a / a;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide basic number types") {
    Real result;
    result = b / 1.0;
    REQUIRE(result == 2.0);
    result = 2.0 / a;
    REQUIRE(result == 2.0);

    result = 4.0 / b / a;
    REQUIRE(result == 2.0);
    result = d / 2.0 / a;
    REQUIRE(result == 2.0);
    result = d / b / 1.0;
    REQUIRE(result == 2.0);

    result = 4.0 / b / a / a;
    REQUIRE(result == 2.0);
    result = d / 2.0 / a / a;
    REQUIRE(result == 2.0);
    result = d / b / 1.0 / a;
    REQUIRE(result == 2.0);
    result = d / b / a / 1.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide assign") {
    Real result(b);
    result /= a;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide assign basic number types") {
    Real result(b);
    result /= 1.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to multiply reals") {
    Real result;
    result = a * b;
    REQUIRE(result == 2.0);
    result = a * b * c;
    REQUIRE(result == 6.0);
    result = a * b * c * d;
    REQUIRE(result == 24.0);
  }

  SECTION("should be able to multiply basic number types") {
    Real result;
    result = 1.0 * b;
    REQUIRE(result == 2.0);
    result = a * 2.0;
    REQUIRE(result == 2.0);

    result = 1.0 * b * c;
    REQUIRE(result == 6.0);
    result = a * 2.0 * c;
    REQUIRE(result == 6.0);
    result = a * b * 3.0;
    REQUIRE(result == 6.0);

    result = 1.0 * b * c * d;
    REQUIRE(result == 24.0);
    result = a * 2.0 * c * d;
    REQUIRE(result == 24.0);
    result = a * b * 3.0 * d;
    REQUIRE(result == 24.0);
    result = a * b * c * 4.0;
    REQUIRE(result == 24.0);
  }

  SECTION("should be able to multiply assign") {
    Real result(a);
    result *= b;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to multiply assign basic number types") {
    Real result(a);
    result *= 2.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to subtract reals") {
    Real result;
    result = a - b;
    REQUIRE(result == -1.0);
    result = a - b - c;
    REQUIRE(result == -4.0);
    result = a - b - c - d;
    REQUIRE(result == -8.0);
  }

  SECTION("should be able to subtract basic number types") {
    Real result;
    result = 1.0 - b;
    REQUIRE(result == -1.0);
    result = a - 2.0;
    REQUIRE(result == -1.0);

    result = 1.0 - b - c;
    REQUIRE(result == -4.0);
    result = a - 2.0 - c;
    REQUIRE(result == -4.0);
    result = a - b - 3.0;
    REQUIRE(result == -4.0);

    result = 1.0 - b - c - d;
    REQUIRE(result == -8.0);
    result = a - 2.0 - c - d;
    REQUIRE(result == -8.0);
    result = a - b - 3.0 - d;
    REQUIRE(result == -8.0);
    result = a - b - c - 4.0;
    REQUIRE(result == -8.0);
  }

  SECTION("should be able to subtract assign") {
    Real result(a);
    result -= b;
    REQUIRE(result == -1.0);
  }

  SECTION("should be able to subtract assign basic number types") {
    Real result(a);
    result -= 2.0;
    REQUIRE(result == -1.0);
  }

  SECTION("should be able to perform mixed operations") {
    Real result;
    result = a + (b / (a * d)) - a;
    REQUIRE(result == 0.5);
  }
}
