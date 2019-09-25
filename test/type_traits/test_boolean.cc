#include <catch2/catch.hpp>

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/boolean_logic.hpp>

using namespace sym;

TEST_CASE("Type Traits: true type", "[type_traits]") {

  SECTION("should evaluate to true") {
    REQUIRE(TrueType());
    REQUIRE(TrueType{});
  }

}

TEST_CASE("Type Traits: false type", "[type_traits]") {

  SECTION("should evaluate to false") {
    REQUIRE(!FalseType());
    REQUIRE(!FalseType{});
  }

}

TEST_CASE("Type Traits: boolean logic", "[type_traits]") {

  SECTION("should be able to compute logical and") {
    REQUIRE(And<TrueType, TrueType>{});
    REQUIRE(!And<TrueType, FalseType>{});
    REQUIRE(!And<FalseType, TrueType>{});
    REQUIRE(!And<FalseType, FalseType>{});
  }

  SECTION("should be able to compute logical or") {
    REQUIRE(Or<TrueType, TrueType>{});
    REQUIRE(Or<TrueType, FalseType>{});
    REQUIRE(Or<FalseType, TrueType>{});
    REQUIRE(!Or<FalseType, FalseType>{});
  }

  SECTION("should be able to compute logical any") {
    REQUIRE(Any<TrueType, FalseType, FalseType>{});
    REQUIRE(Any<FalseType, TrueType, FalseType>{});
    REQUIRE(Any<FalseType, FalseType, TrueType>{});
    REQUIRE(!Any<FalseType, FalseType, FalseType>{});
  }

  SECTION("should be able to compute logical all") {
    REQUIRE(!All<FalseType, TrueType, TrueType>{});
    REQUIRE(!All<TrueType, FalseType, TrueType>{});
    REQUIRE(!All<TrueType, TrueType, FalseType>{});
    REQUIRE(All<TrueType, TrueType, TrueType>{});
  }

}
