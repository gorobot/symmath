#include <catch2/catch.hpp>

#include <symmath/sets/finite_set.hpp>

using namespace sym;

TEST_CASE("FiniteSet: properties", "[sets]") {

  SECTION("should be countable") {
    REQUIRE(HasProperty<FiniteSet<double>, Countable>{});
  }

}

TEST_CASE("FiniteSet: instantiation", "[sets]") {

  SECTION("should be default constructible") {
    FiniteSet<double> t();
  }

  SECTION("should be constructible using inititializer list") {
    FiniteSet<double> t1({1, 2});
    // FiniteSet<double> t2 = {1, 2}; 
  }
}
