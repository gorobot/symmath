#include <catch2/catch.hpp>

#include <iostream>
#include <vector>

#include <symmath/tensors/tensor_initializer.hpp>

TEST_CASE("Tensor: initializer", "[tensors]") {

  SECTION("should flatten 1D initializer lists") {
    std::vector<int> v({1, 2, 3, 4, 5, 6});
    std::vector<int> result;
    result = sym::flatten_initializer_list<int>({1, 2, 3, 4, 5, 6});

    REQUIRE(v == result);
  }

  SECTION("should flatten 2D initializer lists") {
    std::vector<int> v({1, 2, 3, 4, 5, 6});
    std::vector<int> result;
    result = sym::flatten_initializer_list<int>({{1, 2}, {3, 4}, {5, 6}});

    REQUIRE(v == result);
  }

  SECTION("should flatten 3D initializer lists") {
    std::vector<int> v({1, 2, 3, 4, 5, 6});
    std::vector<int> result;
    result = sym::flatten_initializer_list<int>({{{1, 2, 3}}, {{4, 5, 6}}});
    REQUIRE(v == result);
    result = sym::flatten_initializer_list<int>({{{1, 2}, {3, 4}}, {{5, 6}}});
    REQUIRE(v == result);
  }

  SECTION("should get 1d initializer list dimensions") {
    std::array<size_t, 1> d({6});
    std::array<size_t, 1> result;
    result = sym::dim_initializer_list<int>({1, 2, 3, 4, 5, 6});
    REQUIRE(d == result);
  }

  SECTION("should get 2d initializer list dimensions") {
    std::array<size_t, 2> d({3, 2});
    std::array<size_t, 2> result;
    result = sym::dim_initializer_list<int>({{1, 2}, {3, 4}, {5, 6}});
    REQUIRE(d == result);
  }

  // SECTION("should get 3d initializer list dimensions") {
  //   std::array<size_t> d({1, 2, 3});
  //   std::array<size_t> result;
  //   result = sym::dim_initializer_list<int>({{{1, 2, 3}}, {{4, 5, 6}}});
  //   // REQUIRE(d == result);
  // }

}
