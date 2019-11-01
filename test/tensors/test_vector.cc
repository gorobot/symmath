#include <catch2/catch.hpp>

#include <iostream>

#include <symmath/numerics/real.hpp>
#include <symmath/tensors/vector.hpp>

using namespace sym;

TEST_CASE("Vector: operations", "[tensors]") {
  Vector<Real> a({1.0, 2.0, 3.0});
  Vector<Real> b({1.0, 2.0, 3.0});
  Vector<Real> c({1.0, 2.0, 3.0});

  // a + b;

  // SECTION("should be able to add") {
  //   Vector<Real> result;
  //   result = a + b;
  //   REQUIRE(result == Vector<Real>(3.0));
  //   result = a + b + c;
  //   REQUIRE(result == Vector<Real>(8.0));
  // }
  //
  // SECTION("should be able to subtract") {
  //   Vector<Real> result;
  //   result = a - b;
  //   REQUIRE(result == Vector<Real>(1.0));
  //   result = a - b - c;
  //   REQUIRE(result == Vector<Real>(-4.0));
  // }
  //
  // SECTION("should be able to perform mixed operations") {
  //   Vector<Real> result;
  //   result = a + b - c;
  //   REQUIRE(result == Vector<Real>(-2.0));
  // }
}
