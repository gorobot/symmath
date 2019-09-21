#include <catch2/catch.hpp>

#include <iostream>

// #include <symmath/numerics/complex.hpp>
#include <symmath/numerics/real.hpp>
#include <symmath/tensors/scalar.hpp>

TEMPLATE_TEST_CASE(
  "Scalar: operations",
  "[numerics]",
  // sym::Complex,
  sym::Real) {

  // sym::Scalar<TestType> a(2.0);
  // sym::Scalar<TestType> b(1.0);
  // sym::Scalar<TestType> c(5.0);
  //
  // sym::Scalar<TestType> d{5.0};
  // sym::Scalar<TestType> f({5.0});
  //
  // std::cout << d() << '\n';

  // SECTION("should be able to add") {
  //   sym::Scalar<TestType> result;
  //   result = a + b;
  //   REQUIRE(result == sym::Scalar<TestType>(3.0));
  //   // result = a + 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(3.0));
  //   // result = 2.0 + b;
  //   // REQUIRE(result == sym::Scalar<TestType>(3.0));
  //   // result = a + b + c;
  //   // REQUIRE(result == sym::Scalar<TestType>(8.0));
  //   // result = 2.0 + b + c;
  //   // REQUIRE(result == sym::Scalar<TestType>(8.0));
  //   // result += b;
  //   // REQUIRE(result == sym::Scalar<TestType>(9.0));
  //   // result += 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(10.0));
  // }
  //
  // SECTION("should be able to divide") {
  //   sym::Scalar<TestType> result;
  //   result = a / b;
  //   REQUIRE(result == sym::Scalar<TestType>(2.0));
  //   // result = a / 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(2.0));
  //   // result = 2.0 / b;
  //   // REQUIRE(result == sym::Scalar<TestType>(2.0));
  //   // result = a / b / c;
  //   // REQUIRE(result == sym::Scalar<TestType>(.4));
  //   // result = 2.0 / b / c;
  //   // REQUIRE(result == sym::Scalar<TestType>(.4));
  //   // result /= b;
  //   // REQUIRE(result == sym::Scalar<TestType>(.4));
  //   // result /= 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(.4));
  // }
  //
  // SECTION("should be able to multiply") {
  //   sym::Scalar<TestType> result;
  //   result = a * b;
  //   REQUIRE(result == sym::Scalar<TestType>(2.0));
  //   // result = a * 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(2.0));
  //   // result = 2.0 * b;
  //   // REQUIRE(result == sym::Scalar<TestType>(2.0));
  //   // result = a * b * c;
  //   // REQUIRE(result == sym::Scalar<TestType>(10.0));
  //   // result = 2.0 * b * c;
  //   // REQUIRE(result == sym::Scalar<TestType>(10.0));
  //   // result *= b;
  //   // REQUIRE(result == sym::Scalar<TestType>(10.0));
  //   // result *= 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(10.0));
  // }
  //
  // SECTION("should be able to subtract") {
  //   sym::Scalar<TestType> result;
  //   result = a - b;
  //   REQUIRE(result == sym::Scalar<TestType>(1.0));
  //   // result = a - 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(1.0));
  //   // result = 2.0 - b;
  //   // REQUIRE(result == sym::Scalar<TestType>(1.0));
  //   // result = a - b - c;
  //   // REQUIRE(result == sym::Scalar<TestType>(-4.0));
  //   // result = 2.0 - b - c;
  //   // REQUIRE(result == sym::Scalar<TestType>(-4.0));
  //   // result -= b;
  //   // REQUIRE(result == sym::Scalar<TestType>(-5.0));
  //   // result -= 1.0;
  //   // REQUIRE(result == sym::Scalar<TestType>(-6.0));
  // }
}
