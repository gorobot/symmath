#include <catch2/catch.hpp>

#include <symmath/numerics/real.hpp>
#include <symmath/tensors/tensor.hpp>

using namespace sym;

TEST_CASE("Tensor: operations", "[tensors]") {

  Tensor<Real, 1, 1> a;
  Tensor<Real, 1, 2> b(2, 2, 1);

  // Tensor<Real, 1, 1> c({{1, 2, 3},
  //                       {4, 5, 6}});
  //
  // REQUIRE(c(0, 0) == 1);
  // REQUIRE(c(0, 1) == 2);
  // REQUIRE(c(0, 2) == 3);
  // REQUIRE(c(1, 0) == 4);
  // REQUIRE(c(1, 1) == 5);
  // REQUIRE(c(1, 2) == 6);
  //
  // Tensor<Real, 1, 2> d({{{1, 2, 3},
  //                        {4, 5, 6}},
  //                       {{7, 8, 9},
  //                        {10, 11, 12}}});
  //
  // REQUIRE(d(0, 0, 0) == 1);
  // REQUIRE(d(0, 0, 1) == 2);
  // REQUIRE(d(0, 0, 2) == 3);
  // REQUIRE(d(0, 1, 0) == 4);
  // REQUIRE(d(0, 1, 1) == 5);
  // REQUIRE(d(0, 1, 2) == 6);
  // REQUIRE(d(0, 2, 0) == 7);
  // REQUIRE(d(0, 2, 1) == 8);
  // REQUIRE(d(0, 2, 2) == 9);
  // REQUIRE(d(0, 3, 0) == 10);
  // REQUIRE(d(0, 3, 1) == 11);
  // REQUIRE(d(0, 3, 2) == 12);

}
