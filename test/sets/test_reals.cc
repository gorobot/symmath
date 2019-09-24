#include <catch2/catch.hpp>

#include <functional>
#include <iostream>
#include <tuple>

#include <symmath/sets/set.hpp>
#include <symmath/sets/numerics/reals.hpp>
#include <symmath/numerics/real.hpp>
#include <symmath/functions/function.hpp>

#include <symmath/property_traits/addable.hpp>
#include <symmath/type_traits/boolean_logic.hpp>
#include <symmath/operations/addition.hpp>

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

TEST_CASE("Reals: functions", "[real]") {

  REQUIRE(sym::And<sym::TrueType, sym::TrueType>{});
  REQUIRE(!sym::And<sym::TrueType, sym::FalseType>{});
  REQUIRE(!sym::And<sym::FalseType, sym::TrueType>{});
  REQUIRE(!sym::And<sym::FalseType, sym::FalseType>{});

  REQUIRE(sym::Or<sym::TrueType, sym::TrueType>{});
  REQUIRE(sym::Or<sym::TrueType, sym::FalseType>{});
  REQUIRE(sym::Or<sym::FalseType, sym::TrueType>{});
  REQUIRE(!sym::Or<sym::FalseType, sym::FalseType>{});

  REQUIRE(sym::Any<sym::TrueType, sym::FalseType, sym::FalseType>{});
  REQUIRE(sym::Any<sym::FalseType, sym::TrueType, sym::FalseType>{});
  REQUIRE(sym::Any<sym::FalseType, sym::FalseType, sym::TrueType>{});
  REQUIRE(!sym::Any<sym::FalseType, sym::FalseType, sym::FalseType>{});

  REQUIRE(!sym::All<sym::FalseType, sym::TrueType, sym::TrueType>{});
  REQUIRE(!sym::All<sym::TrueType, sym::FalseType, sym::TrueType>{});
  REQUIRE(!sym::All<sym::TrueType, sym::TrueType, sym::FalseType>{});
  REQUIRE(sym::All<sym::TrueType, sym::TrueType, sym::TrueType>{});

  REQUIRE(sym::IsAddable<sym::Real>);
  REQUIRE(sym::IsAddable<sym::Real, sym::Real>);

  sym::Real a, b;
  auto c = a + b; 

  // sym::Real x(1.0);
  //
  // auto f_(sym::Reals) -> sym::Reals;
  //
  // sym::Function<decltype(f_)> f = x;

  // Function f = sym::Reals -> sym::Reals;
  // f(x) = x;

}
