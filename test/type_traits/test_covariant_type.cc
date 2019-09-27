#include <catch2/catch.hpp>

#include <symmath/type_traits/covariant_type.hpp>
#include <symmath/type_traits/is_same.hpp>

using namespace sym;

struct Test {
  Test(double v) {}
};

TEST_CASE("Type Traits: covariant type", "[type_traits]") {

  SECTION("should be able to deduce covariant type") {

    using A = CovariantType_t<Test, double>;
    using B = CovariantType_t<double, Test>;
    using C = CovariantType_t<Test, Test>;

    REQUIRE(IsSame<Test, A>{});
    REQUIRE(IsSame<Test, B>{});
    REQUIRE(IsSame<Test, C>{});

  }

}
