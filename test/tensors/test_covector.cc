#include <catch2/catch.hpp>

#include <symmath/numerics/real.hpp>
#include <symmath/tensors/covector.hpp>
#include <symmath/tensors/vector.hpp>

using namespace sym;

TEST_CASE("Vector: operations", "[tensors]") {
  Vector<Real, 3> a(2.0);
  Vector<Real, 3> b(1.0);
  Vector<Real, 3> c(5.0);

  SECTION("should be able to add") {
    Vector<Real, 3> result;
    result = a + b;
    REQUIRE(result == Vector<Real, 3>(3.0));
    result = a + b + c;
    REQUIRE(result == Vector<Real, 3>(8.0));
  }

  SECTION("should be able to subtract") {
    Vector<Real, 3> result;
    result = a - b;
    REQUIRE(result == Vector<Real, 3>(1.0));
    result = a - b - c;
    REQUIRE(result == Vector<Real, 3>(-4.0));
  }

  SECTION("should be able to perform mixed operations") {
    Vector<Real, 3> result;
    result = a + b - c;
    REQUIRE(result == Vector<Real, 3>(-2.0));
  }
}
