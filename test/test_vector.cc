#include <catch2/catch.hpp>

#include "../symmath/numerics.hpp"
#include "../symmath/matrix.hpp"

#include "../symmath/type_traits/is_storage_object.hpp"

TEMPLATE_TEST_CASE(
  "Vector: operations",
  "[numerics]",
  sym::Natural,
  sym::Integer,
  sym::Real) {

  sym::Vector<TestType> a({1, 2, 3});
  sym::Vector<TestType> b({0, 1, 2});

  sym::Vector<int> c = {1, 2, 3};

  REQUIRE(sym::is_storage_object<sym::Vector<TestType>>{});

  SECTION("should be able to add") {
    sym::Vector<TestType> result;
    result = a + b;
    REQUIRE(result == sym::Vector<TestType>({1, 3, 5}));
    REQUIRE(result[0] == 1);
  }

  SECTION("should be able to multiply") {
    sym::Vector<TestType> result;
    result = a * b;
  }

  SECTION("should be able to subtract") {
    sym::Vector<TestType> result;
    result = a - b;
  }
}
