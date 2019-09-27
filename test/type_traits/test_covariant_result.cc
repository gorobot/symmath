#include <catch2/catch.hpp>

#include <symmath/type_traits/covariant_result.hpp>
#include <symmath/type_traits/is_same.hpp>

using namespace sym;

struct Test1 {
  Test1(double v) {}
  using ResultType = double;
};

struct Test2 {
  using ResultType = Test1;
};

TEST_CASE("Type Traits: covariant result type", "[type_traits]") {

  SECTION("should be able to deduce covariant result type") {

    using A = CovariantResult_t<Test2, Test1>;
    using B = CovariantResult_t<Test2, double>;

    REQUIRE(IsSame<Test1, A>{});
    REQUIRE(IsSame<Test1, B>{});

  }

}
