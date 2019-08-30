#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <type_traits>

#include "../symmath/operation/add.hpp"

using sym::Symbolic;
using sym::Operation;
using sym::Add;

TEST_CASE("Operation: Type Traits", "[operation]") {

  REQUIRE(sym::is_symbolic<Add<double, int>>::value);
  REQUIRE(sym::is_symbolic<Symbolic<Add<double, int>>>::value);
  REQUIRE(sym::is_symbolic<Operation<Symbolic<Add<double, int>>>>::value);

  REQUIRE(sym::is_operation<Add<double, int>>::value);
  // REQUIRE(sym::is_operation<Symbolic<Add<double, int>>>::value);
  REQUIRE(sym::is_operation<Operation<Symbolic<Add<double, int>>>>::value);

}
