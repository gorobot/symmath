#include <catch2/catch.hpp>

#include "../../symmath/numerics/natural.hpp"
#include "../../symmath/type_traits/is_element_of.hpp"
#include "../../symmath/type_traits/is_field.hpp"
#include "../../symmath/type_traits/is_scalar.hpp"

TEST_CASE("Natural: properties", "[numerics]") {

  SECTION("should be an element of the naturals") {
    REQUIRE(sym::is_element_of<sym::Naturals, sym::Natural>{});
  }

  SECTION("should have addition operator") {
    REQUIRE(sym::HasProperty<sym::Natural, sym::addition>{});
  }

  SECTION("should have multiplication operator") {
    REQUIRE(sym::HasProperty<sym::Natural, sym::multiplication>{});
  }

  SECTION("should not be a scalar") {
    REQUIRE(!sym::is_scalar<sym::Natural>{});
  }

}

TEST_CASE("Natural: operations", "[numerics]") {
  sym::Natural a(2);
  sym::Natural b(1);
  sym::Natural c(5);

  SECTION("should be able to add") {
    sym::Natural result;
    result = a + b;
    REQUIRE(result == 3);
    result = a + 1;
    REQUIRE(result == 3);
    result = 2 + b;
    REQUIRE(result == 3);
    result = a + b + c;
    REQUIRE(result == 8);
    result = 2 + b + c;
    REQUIRE(result == 8);
    result += b;
    REQUIRE(result == 9);
    result += 1;
    REQUIRE(result == 10);
  }

  SECTION("should be able to multiply") {
    sym::Natural result;
    result = a * b;
    REQUIRE(result == 2);
    result = a * 1;
    REQUIRE(result == 2);
    result = 2 * b;
    REQUIRE(result == 2);
    result = a * b * c;
    REQUIRE(result == 10);
    result = 2 * b * c;
    REQUIRE(result == 10);
    result *= b;
    REQUIRE(result == 10);
    result *= 1;
    REQUIRE(result == 10);
  }

  SECTION("should be able to perform mixed operations") {
    sym::Natural result;
    result = a + (b * a);
    REQUIRE(result == 4);
  }
}
