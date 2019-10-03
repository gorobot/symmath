#include <catch2/catch.hpp>

#include <iostream>
#include <symmath/numerics/real.hpp>
#include <symmath/numerics/variable.hpp>

using namespace sym;

// TEST_CASE("Variables: value", "[numerics]") {
//
//   SECTION("should accept rvalues") {
//     Variable<Real> x(1.0);
//     REQUIRE(x == 1.0);
//   }
//
//   SECTION("should accept lvalues") {
//     Real a(1.0);
//     Variable<Real> x(a);
//     REQUIRE(a == 1.0);
//     REQUIRE(x == 1.0);
//   }
//
//   SECTION("should change if underlying value changes") {
//     Real a(1.0);
//     Variable<Real> x(a);
//     REQUIRE(a == 1.0);
//     REQUIRE(x == 1.0);
//     a = 2.0;
//     REQUIRE(a == 2.0);
//     REQUIRE(x == 2.0);
//     a = 200.0;
//     REQUIRE(a == 200.0);
//     REQUIRE(x == 200.0);
//   }
// }

TEST_CASE("Variables: addition", "[numerics]") {
  Variable<Real> x(1.0);
  Variable<Real> y(2.0);
  Variable<Real> z(3.0);

  SECTION("should be able to add variables") {
    Variable<Real> result;
    result = x + y;
    // REQUIRE(result == 3.0);
    // result = x + y + z;
    // REQUIRE(result == 6.0);
  }
}

// TEST_CASE("Variables: division", "[numerics]") {
//   Variable<Real> x(1.0);
//   Variable<Real> y(2.0);
//   Variable<Real> z(3.0);
//
//   SECTION("should be able to div variables") {
//     Variable<Real> result;
//     result = y / x;
//     REQUIRE(result == 2.0);
//     result = z / x / y;
//     REQUIRE(result == 1.5);
//   }
// }
//
// TEST_CASE("Variables: multiplication", "[numerics]") {
//   Variable<Real> x(1.0);
//   Variable<Real> y(2.0);
//   Variable<Real> z(3.0);
//
//   SECTION("should be able to mul variables") {
//     Variable<Real> result;
//     result = x * y;
//     REQUIRE(result == 2.0);
//     result = x * y * z;
//     REQUIRE(result == 6.0);
//   }
// }
//
// TEST_CASE("Variables: subtraction", "[numerics]") {
//   Variable<Real> x(1.0);
//   Variable<Real> y(2.0);
//   Variable<Real> z(3.0);
//
//   SECTION("should be able to sub variables") {
//     Variable<Real> result;
//     result = x - y;
//     REQUIRE(result == -1.0);
//     result = x - y - z;
//     REQUIRE(result == -4.0);
//   }
// }

// TEST_CASE("Variables: operations", "[numerics]") {
//   Real a(1.0);
//   Variable<Real> x(2.0);
//   Variable<Real> y(1.0);
//
//   // REQUIRE(a == y);
//
//   // z = x + y;
//
//   SECTION("should be able to assign") {
//     Variable<Real> z(a);
//     REQUIRE(z == a);
//     REQUIRE(z == 1.0);
//   }
//
//   SECTION("should be able to assign") {
//     Variable<Real> z(a);
//     REQUIRE(z == a);
//     REQUIRE(a == 1.0);
//     REQUIRE(z == 1.0);
//     a = 5.0;
//     REQUIRE(a == 5.0);
//     REQUIRE(z == 5.0);
//   }
//
//   SECTION("should be able to assign") {
//     Variable<Real> z;
//     z = a;
//     REQUIRE(z == a);
//   }
//
//   SECTION("should be able to assign") {
//     Variable<Real> z;
//     z = x;
//     REQUIRE(z == x);
//     // REQUIRE(z == 2.0);
//   }
//
//   // SECTION("should be able to assign") {
//   //   Variable<Real> z;
//   //   z = x + a;
//   //   // REQUIRE(z == 3.0);
//   //   // a = 3.0;
//   //   // REQUIRE(z == 5.0);
//   // }
//
// }
