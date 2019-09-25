#include <catch2/catch.hpp>

#include <symmath/type_traits/boolean.hpp>
#include <symmath/type_traits/conditional.hpp>

using namespace sym;

TEST_CASE("Type Traits: conditional", "[type_traits]") {

  SECTION("should evaluate if true") {
    REQUIRE(If_t<true, TrueType, FalseType>{});
    REQUIRE(If_t<TrueType{}, TrueType, FalseType>{});
  }

  SECTION("should evaluate if false") {
    REQUIRE(!If_t<false, TrueType, FalseType>{});
    REQUIRE(!If_t<FalseType{}, TrueType, FalseType>{});
  }

}
