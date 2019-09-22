#include <catch2/catch.hpp>

#include "../../symmath/sets/set.hpp"
#include "../../symmath/sets/numerics/reals.hpp"

using sym::HasProperty;
using sym::Reals;

TEST_CASE("Reals: properties", "[sets]") {

  REQUIRE(HasProperty<Reals, sym::Addition>{});
  REQUIRE(HasProperty<Reals, sym::AssociativeProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Reals, sym::ClosureProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Reals, sym::CommutativeProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Reals, sym::DistributiveProperty<sym::Addition>>{});
  REQUIRE(HasProperty<Reals, sym::IdentityElement<sym::Addition>>{});
  REQUIRE(HasProperty<Reals, sym::InverseElement<sym::Addition>>{});
  REQUIRE(HasProperty<Reals, sym::Multiplication>{});
  REQUIRE(HasProperty<Reals, sym::AssociativeProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Reals, sym::ClosureProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Reals, sym::CommutativeProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Reals, sym::DistributiveProperty<sym::Multiplication>>{});
  REQUIRE(HasProperty<Reals, sym::IdentityElement<sym::Multiplication>>{});
  REQUIRE(HasProperty<Reals, sym::InverseElement<sym::Multiplication>>{});
  REQUIRE(HasProperty<Reals, sym::TotalOrder>{});

}
