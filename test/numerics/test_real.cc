#include <catch2/catch.hpp>

#include <iostream>

#include <symmath/numerics/real.hpp>

using sym::HasProperty;
using sym::Real;

// #include "../../symmath/type_traits/is_field.hpp"
// #include "../../symmath/type_traits/is_scalar.hpp"

TEST_CASE("Real: properties", "[numerics]") {

  REQUIRE(HasProperty<Real, sym::Addition>{});
  REQUIRE(HasProperty<Real, sym::AssociativeProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Real, sym::ClosureProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Real, sym::CommutativeProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Real, sym::DistributiveProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Real, sym::IdentityElement<sym::Addition>>{});
  REQUIRE(HasProperty<Real, sym::InverseElement<sym::Addition>>{});
  REQUIRE(HasProperty<Real, sym::Multiplication>{});
  REQUIRE(HasProperty<Real, sym::AssociativeProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Real, sym::ClosureProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Real, sym::CommutativeProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Real, sym::DistributiveProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Real, sym::IdentityElement<sym::Multiplication>>{});
  REQUIRE(HasProperty<Real, sym::InverseElement<sym::Multiplication>>{});
  REQUIRE(HasProperty<Real, sym::TotalOrder>{});

}

TEST_CASE("Real: operations", "[numerics]") {
  sym::Real a(2.0);
  sym::Real b(1.0);
  sym::Real c(5.0);

  std::cout << a << '\n';

  SECTION("should be able to add") {
    sym::Real result;
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
  //   sym::Real result;
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
  //   sym::Real result;
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
  //   sym::Real result;
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
  //   sym::Real result;
  //   result = a + (b / (a * b)) - a;
  //   REQUIRE(result == 0.5);
  // }
}
