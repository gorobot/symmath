#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../symmath/symmath.hpp"

TEST_CASE("Number: Add", "[symmath]") {
  sym::Number<int> a(2);
  sym::Number<int> b(1);

  {
    sym::Number<int> result;
    result = a + b;
  }
}

TEST_CASE("Number: Div", "[symmath]") {
  sym::Number<int> a(2);
  sym::Number<int> b(1);

  {
    sym::Number<int> result;
    result = a / b;
  }
}

TEST_CASE("Number: Mul", "[symmath]") {
  sym::Number<int> a(2);
  sym::Number<int> b(1);

  {
    sym::Number<int> result;
    result = a * b;
  }
}

TEST_CASE("Number: Sub", "[symmath]") {
  sym::Number<int> a(2);
  sym::Number<int> b(1);

  {
    sym::Number<int> result;
    result = a - b;
  }
}
