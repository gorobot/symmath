#include <catch2/catch.hpp>

#include "../../symmath/sets/set.hpp"
#include "../../symmath/numerics/real.hpp"
#include "../../symmath/numerics/sets/reals.hpp"

TEST_CASE("Sets: numbers", "[sets]") {

  SECTION("should be able to add") {
    REQUIRE(sym::has_property<sym::Real, sym::addition>{});
  }

  REQUIRE(1);
}
