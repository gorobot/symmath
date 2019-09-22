#include <catch2/catch.hpp>

#include <iostream>
#include <type_traits>

#include <symmath/numerics/real.hpp>
#include <symmath/tensors/tensor.hpp>

TEST_CASE("Tensor: operations", "[tensors]") {

  sym::Tensor<sym::Real, 1, 1> a;
  sym::Tensor<sym::Real, 1, 2> b(2, 2, 1);

  sym::Tensor<double, 1, 1> c({{1, 2, 3},
                               {4, 5, 6}});

  std::cout << c(0, 0) << '\n';
  std::cout << c(0, 1) << '\n';
  std::cout << c(0, 2) << '\n';
  std::cout << c(1, 0) << '\n';
  std::cout << c(1, 1) << '\n';
  std::cout << c(1, 2) << '\n';

  sym::Tensor<double, 1, 2> d({{{1, 2, 3},
                                {4, 5, 6}},
                               {{7, 8, 9},
                                {10, 11, 12}}});

  std::cout << d(0, 0, 0) << '\n';
  std::cout << d(0, 0, 1) << '\n';
  std::cout << d(0, 0, 2) << '\n';
  std::cout << d(0, 1, 0) << '\n';

}
