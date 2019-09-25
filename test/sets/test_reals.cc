#include <catch2/catch.hpp>

#include <functional>
#include <iostream>
#include <tuple>

#include <symmath/sets/set.hpp>
#include <symmath/sets/numerics/reals.hpp>
#include <symmath/numerics/real.hpp>

using namespace sym;

TEST_CASE("Reals: properties", "[sets]") {

  REQUIRE(HasProperty<Reals, Addition>{});
  REQUIRE(HasProperty<Reals, AssociativeProperty<Addition>>{});
  REQUIRE(HasProperty<Reals, ClosureProperty<Addition>>{});
  REQUIRE(HasProperty<Reals, CommutativeProperty<Addition>>{});
  REQUIRE(HasProperty<Reals, DistributiveProperty<Addition>>{});
  REQUIRE(HasProperty<Reals, IdentityElement<Addition>>{});
  REQUIRE(HasProperty<Reals, InverseElement<Addition>>{});
  REQUIRE(HasProperty<Reals, Multiplication>{});
  REQUIRE(HasProperty<Reals, AssociativeProperty<Multiplication>>{});
  REQUIRE(HasProperty<Reals, ClosureProperty<Multiplication>>{});
  REQUIRE(HasProperty<Reals, CommutativeProperty<Multiplication>>{});
  REQUIRE(HasProperty<Reals, DistributiveProperty<Multiplication>>{});
  REQUIRE(HasProperty<Reals, IdentityElement<Multiplication>>{});
  REQUIRE(HasProperty<Reals, InverseElement<Multiplication>>{});
  REQUIRE(HasProperty<Reals, TotalOrder>{});

}

TEST_CASE("Reals: functions", "[real]") {

  REQUIRE(And<TrueType, TrueType>{});
  REQUIRE(!And<TrueType, FalseType>{});
  REQUIRE(!And<FalseType, TrueType>{});
  REQUIRE(!And<FalseType, FalseType>{});

  REQUIRE(Or<TrueType, TrueType>{});
  REQUIRE(Or<TrueType, FalseType>{});
  REQUIRE(Or<FalseType, TrueType>{});
  REQUIRE(!Or<FalseType, FalseType>{});

  REQUIRE(Any<TrueType, FalseType, FalseType>{});
  REQUIRE(Any<FalseType, TrueType, FalseType>{});
  REQUIRE(Any<FalseType, FalseType, TrueType>{});
  REQUIRE(!Any<FalseType, FalseType, FalseType>{});

  REQUIRE(!All<FalseType, TrueType, TrueType>{});
  REQUIRE(!All<TrueType, FalseType, TrueType>{});
  REQUIRE(!All<TrueType, TrueType, FalseType>{});
  REQUIRE(All<TrueType, TrueType, TrueType>{});

}
