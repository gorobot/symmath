#include <catch2/catch.hpp>

#include <iostream>
#include <type_traits>

#include <symmath/numerics/real.hpp>
#include <symmath/tensors/tensor.hpp>

TEST_CASE("Tensor: operations", "[tensors]") {

  sym::Tensor<sym::Real, 1, 1> a;
  sym::Tensor<sym::Real, 1, 2> b(2, 2, 1);

  // std::cout << b.size() << '\n';
  //
  // std::cout << b(0, 0, 0) << '\n';

  sym::Tensor<double, 1, 1> c({{1, 2, 3}, {4, 5, 6}});

  std::cout << c(0, 0) << '\n';
  std::cout << c(0, 1) << '\n';
  std::cout << c(0, 2) << '\n';
  std::cout << c(1, 0) << '\n';
  std::cout << c(1, 1) << '\n';
  std::cout << c(1, 2) << '\n';  

  // struct dummy {
  //   std::vector<double> a;
  //   std::vector<double> b;
  // };
  //
  // dummy v = {{1, 2}, {3, 4}};

  // sym::Vector<TestType, 3> a(2.0);
  // sym::Vector<TestType, 3> b(1.0);
  // sym::Vector<TestType, 3> c(5.0);
  //
  // SECTION("should be able to add") {
  //   sym::Vector<TestType, 3> result;
  //   result = a + b;
  //   REQUIRE(result == sym::Vector<TestType, 3>(3.0));
  //   result = a + b + c;
  //   REQUIRE(result == sym::Vector<TestType, 3>(8.0));
  // }
  //
  // SECTION("should be able to subtract") {
  //   sym::Vector<TestType, 3> result;
  //   result = a - b;
  //   REQUIRE(result == sym::Vector<TestType, 3>(1.0));
  //   result = a - b - c;
  //   REQUIRE(result == sym::Vector<TestType, 3>(-4.0));
  // }
  //
  // SECTION("should be able to perform mixed operations") {
  //   sym::Vector<TestType, 3> result;
  //   result = a + b - c;
  //   REQUIRE(result == sym::Vector<TestType, 3>(-2.0));
  // }

}
