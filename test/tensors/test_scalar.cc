#include <catch2/catch.hpp>

#include <iostream>
#include <type_traits>
#include <vector>

#include <symmath/numerics/real.hpp>
#include <symmath/tensors/scalar.hpp>
#include <symmath/tensors/tensor.hpp>

using namespace sym;

TEST_CASE("Scalar: assignment", "[tensors]") {
  Real x(1.0);
  Real y(2.0);

  // Real result;
  //
  // result = x * y;

  // Tensor<Real, 2, 0> M({{0.0, 1.0}, {2.0, 3.0}});

  // std::vector<Real> w;
  // std::vector<Real> v = {x, y};
  //
  // std::cout << v[0] << '\n';
  // std::cout << v[1] << '\n';

  // w.insert(w.end(), v.begin(), v.end());

  // v.insert(v.begin(), {x, y});

  // Scalar<Real> a(1.0);
  // Scalar<Real> b(2.0);
  //
  // Scalar<Real> result;
  // result = a + b;

  // std::cout << result << '\n';
}

// TEST_CASE("Scalar: addition", "[tensors]") {
//   Scalar<Real> a(1.0);
//   Scalar<Real> b(2.0);
//   Scalar<Real> c(3.0);
//   Scalar<Real> d(4.0);
//
//   SECTION("should be able to add reals") {
//     Scalar<Real> result;
//     result = a + b;
//     REQUIRE(result == 3.0);
//     result = a + b + c;
//     REQUIRE(result == 6.0);
//     result = a + b + c + d;
//     REQUIRE(result == 10.0);
//   }
//
//   SECTION("should be able to add basic number types") {
//     Scalar<Real> result;
//     result = a + 1.0;
//     REQUIRE(result == 2.0);
//     result = 1.0 + b;
//     REQUIRE(result == 3.0);
//
//     result = a + 1.0 + c;
//     REQUIRE(result == 5.0);
//     result = 1.0 + b + c;
//     REQUIRE(result == 6.0);
//     result = a + b + 1.0;
//     REQUIRE(result == 4.0);
//
//     result = 1.0 + b + c + d;
//     REQUIRE(result == 10.0);
//     result = a + 1.0 + c + d;
//     REQUIRE(result == 9.0);
//     result = a + b + 1.0 + d;
//     REQUIRE(result == 8.0);
//     result = a + b + c + 1.0;
//     REQUIRE(result == 7.0);
//   }
//
//   // SECTION("should be able to add assign") {
//   //   Scalar<Real> result(a);
//   //   result += b;
//   //   REQUIRE(result == 3.0);
//   // }
//   //
//   // SECTION("should be able to add assign basic number types") {
//   //   Scalar<Real> result(a);
//   //   result += 1.0;
//   //   REQUIRE(result == 2.0);
//   // }
// }
//
// TEST_CASE("Scalar: division", "[tensors]") {
//   Scalar<Real> a(1.0);
//   Scalar<Real> b(2.0);
//   Scalar<Real> c(3.0);
//   Scalar<Real> d(4.0);
//
//   SECTION("should be able to divide reals") {
//     Scalar<Real> result;
//     result = b / a;
//     REQUIRE(result == 2.0);
//     result = d / b / a;
//     REQUIRE(result == 2.0);
//     result = d / b / a / a;
//     REQUIRE(result == 2.0);
//   }
//
//   SECTION("should be able to divide basic number types") {
//     Scalar<Real> result;
//     result = b / 1.0;
//     REQUIRE(result == 2.0);
//     result = 2.0 / a;
//     REQUIRE(result == 2.0);
//
//     result = 4.0 / b / a;
//     REQUIRE(result == 2.0);
//     result = d / 2.0 / a;
//     REQUIRE(result == 2.0);
//     result = d / b / 1.0;
//     REQUIRE(result == 2.0);
//
//     result = 4.0 / b / a / a;
//     REQUIRE(result == 2.0);
//     result = d / 2.0 / a / a;
//     REQUIRE(result == 2.0);
//     result = d / b / 1.0 / a;
//     REQUIRE(result == 2.0);
//     result = d / b / a / 1.0;
//     REQUIRE(result == 2.0);
//   }
//
//   // SECTION("should be able to divide assign") {
//   //   Scalar<Real> result(b);
//   //   result /= a;
//   //   REQUIRE(result == 2.0);
//   // }
//   //
//   // SECTION("should be able to divide assign basic number types") {
//   //   Scalar<Real> result(b);
//   //   result /= 1.0;
//   //   REQUIRE(result == 2.0);
//   // }
// }
//
// TEST_CASE("Scalar: multiplication", "[tensors]") {
//   Scalar<Real> a(1.0);
//   Scalar<Real> b(2.0);
//   Scalar<Real> c(3.0);
//   Scalar<Real> d(4.0);
//
//   SECTION("should be able to multiply reals") {
//     Scalar<Real> result;
//     result = a * b;
//     REQUIRE(result == 2.0);
//     result = a * b * c;
//     REQUIRE(result == 6.0);
//     result = a * b * c * d;
//     REQUIRE(result == 24.0);
//   }
//
//   SECTION("should be able to multiply basic number types") {
//     Scalar<Real> result;
//     result = 1.0 * b;
//     REQUIRE(result == 2.0);
//     result = a * 2.0;
//     REQUIRE(result == 2.0);
//
//     result = 1.0 * b * c;
//     REQUIRE(result == 6.0);
//     result = a * 2.0 * c;
//     REQUIRE(result == 6.0);
//     result = a * b * 3.0;
//     REQUIRE(result == 6.0);
//
//     result = 1.0 * b * c * d;
//     REQUIRE(result == 24.0);
//     result = a * 2.0 * c * d;
//     REQUIRE(result == 24.0);
//     result = a * b * 3.0 * d;
//     REQUIRE(result == 24.0);
//     result = a * b * c * 4.0;
//     REQUIRE(result == 24.0);
//   }
//
//   // SECTION("should be able to multiply assign") {
//   //   Scalar<Real> result(a);
//   //   result *= b;
//   //   REQUIRE(result == 2.0);
//   // }
//   //
//   // SECTION("should be able to multiply assign basic number types") {
//   //   Scalar<Real> result(a);
//   //   result *= 2.0;
//   //   REQUIRE(result == 2.0);
//   // }
// }
//
// TEST_CASE("Scalar: subtraction", "[tensors]") {
//   Scalar<Real> a(1.0);
//   Scalar<Real> b(2.0);
//   Scalar<Real> c(3.0);
//   Scalar<Real> d(4.0);
//
//   SECTION("should be able to subtract reals") {
//     Scalar<Real> result;
//     result = a - b;
//     REQUIRE(result == -1.0);
//     result = a - b - c;
//     REQUIRE(result == -4.0);
//     result = a - b - c - d;
//     REQUIRE(result == -8.0);
//   }
//
//   SECTION("should be able to subtract basic number types") {
//     Scalar<Real> result;
//     result = 1.0 - b;
//     REQUIRE(result == -1.0);
//     result = a - 2.0;
//     REQUIRE(result == -1.0);
//
//     result = 1.0 - b - c;
//     REQUIRE(result == -4.0);
//     result = a - 2.0 - c;
//     REQUIRE(result == -4.0);
//     result = a - b - 3.0;
//     REQUIRE(result == -4.0);
//
//     result = 1.0 - b - c - d;
//     REQUIRE(result == -8.0);
//     result = a - 2.0 - c - d;
//     REQUIRE(result == -8.0);
//     result = a - b - 3.0 - d;
//     REQUIRE(result == -8.0);
//     result = a - b - c - 4.0;
//     REQUIRE(result == -8.0);
//   }
//
//   // SECTION("should be able to subtract assign") {
//   //   Scalar<Real> result(a);
//   //   result -= b;
//   //   REQUIRE(result == -1.0);
//   // }
//   //
//   // SECTION("should be able to subtract assign basic number types") {
//   //   Scalar<Real> result(a);
//   //   result -= 2.0;
//   //   REQUIRE(result == -1.0);
//   // }
// }
//
// TEST_CASE("Scalar: mixed arithmetic operations", "[tensors]") {
//   Scalar<Real> a(1.0);
//   Scalar<Real> b(2.0);
//   Scalar<Real> c(3.0);
//   Scalar<Real> d(4.0);
//
//   SECTION("should be able to perform mixed operations") {
//     Scalar<Real> result;
//     result = a + (b / (a * d)) - a;
//     REQUIRE(result == 0.5);
//   }
// }
