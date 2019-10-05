#include <catch2/catch.hpp>

#include <symmath/type_traits/result_type.hpp>
#include <symmath/type_traits/is_same.hpp>

using namespace sym;

struct Test1 {
  Test1(double v) {}
  using ResultType = double;
};

struct Test2 {
  using ResultType = Test1;
};

TEST_CASE("Type Traits: result type", "[type_traits]") {

  SECTION("should be able to deduce result type") {

    using A = ResultType_t<Test1>;
    using B = ResultType_t<Test2>;

    REQUIRE(IsSame<double, A>{});
    REQUIRE(IsSame<Test1, B>{});

  }

}
