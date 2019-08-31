#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

#include "../symmath/type_traits/is_storage_object.hpp"

TEMPLATE_TEST_CASE(
  "Vector: operations",
  "[numerics]",
  sym::Real) {

  sym::Vector<TestType, 3> a({1, 2, 3});
  sym::Vector<TestType, 3> b({0, 1, 2});

  // sym::Vector<int, 3> c = {1, 2, 3};

  // REQUIRE(sym::is_storage_object<sym::Vector<TestType, 3>>{});

  SECTION("should be able to add") {
    sym::Vector<TestType, 3> result;
    result = a + b;
    REQUIRE(result == sym::Vector<TestType, 3>({1, 3, 5}));
  }

  SECTION("should be able to multiply") {
    sym::Scalar<TestType> s(2);
    sym::Vector<TestType, 3> result;
    result = a * s;
    REQUIRE(result == sym::Vector<TestType, 3>({2, 4, 6}));
  }

  SECTION("should be able to subtract") {
    sym::Vector<TestType, 3> result;
    result = a - b;
    REQUIRE(result == sym::Vector<TestType, 3>({1, 1, 1}));
  }
}
