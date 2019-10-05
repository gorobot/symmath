#include <catch2/catch.hpp>

#include <type_traits>

#include <symmath/type_traits/detect.hpp>

using namespace sym;

template< typename T >
using Has = typename T::has;

template< typename T >
using NotHas = typename T::not_has;

template< typename T >
using HasFunction = decltype(std::declval<T&>().has_function());

template< typename T >
using NotHasFunction = decltype(std::declval<T&>().not_has_function());

struct Test {
  using has = void;
  void has_function();
};

TEST_CASE("Type Traits: detect", "[type_traits]") {

  SECTION("should be able to detect types") {

    REQUIRE(Detect<Has, Test>);
    REQUIRE(!Detect<NotHas, Test>);

  }

  SECTION("should be able to detect functions") {

    REQUIRE(Detect<HasFunction, Test>);
    REQUIRE(!Detect<NotHasFunction, Test>);

  }

}
