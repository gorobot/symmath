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
  Real a(2.0);
  Real b(1.0);
  Real c(5.0);

  SECTION("should be able to add") {
    Real result;
    result = a + b;
    REQUIRE(result == 3.0);
    // result = a + 1.0;
    // REQUIRE(result == 3.0);
    // result = 2.0 + b;
    // REQUIRE(result == 3.0);
    result = a + b + c;
    REQUIRE(result == 8.0);
    // // result = 2.0 + b + c;
    // // REQUIRE(result == 8.0);
    // result += b;
    // REQUIRE(result == 9.0);
    // result += 1.0;
    // REQUIRE(result == 10.0);
  }

  // SECTION("should be able to divide") {
  //   Real result;
  //   result = a / b;
  //   REQUIRE(result == 2.0);
  //   result = a / 1.0;
  //   REQUIRE(result == 2.0);
  //   result = 2.0 / b;
  //   REQUIRE(result == 2.0);
  //   result = a / b / c;
  //   REQUIRE(result == 0.4);
  //   result = 2.0 / b / c;
  //   REQUIRE(result == 0.4);
  //   result /= b;
  //   REQUIRE(result == 0.4);
  //   result /= 1.0;
  //   REQUIRE(result == 0.4);
  // }
  //
  // SECTION("should be able to multiply") {
  //   Real result;
  //   result = a * b;
  //   REQUIRE(result == 2.0);
  //   result = a * 1.0;
  //   REQUIRE(result == 2.0);
  //   result = 2.0 * b;
  //   REQUIRE(result == 2.0);
  //   result = a * b * c;
  //   REQUIRE(result == 10.0);
  //   result = 2.0 * b * c;
  //   REQUIRE(result == 10.0);
  //   result *= b;
  //   REQUIRE(result == 10.0);
  //   result *= 1.0;
  //   REQUIRE(result == 10.0);
  //
  //   result = a^b;
  //   REQUIRE(result == 2.0);
  //   result = a^2;
  //   REQUIRE(result == 4.0);
  //   result ^= 2;
  //   REQUIRE(result == 16.0);
  //
  //   result = inv(a);
  //   REQUIRE(result == 0.5);
  // }
  //
  // SECTION("should be able to subtract") {
  //   Real result;
  //   result = a - b;
  //   REQUIRE(result == 1.0);
  //   result = a - 1.0;
  //   REQUIRE(result == 1.0);
  //   result = 2.0 - b;
  //   REQUIRE(result == 1.0);
  //   result = a - b - c;
  //   REQUIRE(result == -4.0);
  //   result = 2.0 - b - c;
  //   REQUIRE(result == -4.0);
  //   result -= b;
  //   REQUIRE(result == -5.0);
  //   result -= 1.0;
  //   REQUIRE(result == -6.0);
  //
  //   result = -a + b;
  //   REQUIRE(result == -1.0);
  //   result = a - -b;
  //   REQUIRE(result == 3.0);
  // }
  //
  // SECTION("should be able to perform mixed operations") {
  //   Real result;
  //   result = a + (b / (a * b)) - a;
  //   REQUIRE(result == 0.5);
  // }
}
