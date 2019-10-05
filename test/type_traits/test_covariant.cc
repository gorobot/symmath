#include <catch2/catch.hpp>

#include <symmath/type_traits/covariant.hpp>
#include <symmath/type_traits/is_same.hpp>

using namespace sym;

struct Test1 {
  Test1(double v) {}
  using ResultType = double;
};

struct Test2 {
  using ResultType = Test1;
};

TEST_CASE("Type Traits: covariant type", "[type_traits]") {

  SECTION("should be able to deduce covariant type") {

    using A = Covariant_t<Test1, double>;
    using B = Covariant_t<double, Test1>;
    using C = Covariant_t<Test1, Test1>;

    REQUIRE(IsSame<Test1, A>{});
    REQUIRE(IsSame<Test1, B>{});
    REQUIRE(IsSame<Test1, C>{});

  }

  SECTION("should be able to detect covariance") {

    REQUIRE(IsCovariant<Test1, double>);
    REQUIRE(IsCovariant<double, Test1>);
    REQUIRE(IsCovariant<Test1, Test1>);

    REQUIRE(!IsCovariant<Test1, Test2>);
    REQUIRE(!IsCovariant<Test2, Test1>);

  }

}
