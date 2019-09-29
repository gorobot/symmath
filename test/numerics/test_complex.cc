#include <catch2/catch.hpp>

#include <symmath/numerics/complex.hpp>

using namespace sym;
using namespace std::complex_literals;

TEST_CASE("Complex: operations", "[numerics]") {
  Complex a(1.0 + 0.0i);
  Complex b(2.0 + 0.0i);
  Complex c(3.0 + 0.0i);
  Complex d(4.0 + 0.0i);

  SECTION("should be able to add complex numbers") {
    Complex result;
    result = a + b;
    REQUIRE(result == 3.0);
    result = a + b + c;
    REQUIRE(result == 6.0);
    result = a + b + c + d;
    REQUIRE(result == 10.0);
  }

  SECTION("should be able to add basic number types") {
    Complex result;
    result = a + 1.0;
    REQUIRE(result == 2.0);
    result = 1.0 + b;
    REQUIRE(result == 3.0);

    result = a + 1.0 + c;
    REQUIRE(result == 5.0);
    result = 1.0 + b + c;
    REQUIRE(result == 6.0);
    result = a + b + 1.0;
    REQUIRE(result == 4.0);

    result = 1.0 + b + c + d;
    REQUIRE(result == 10.0);
    result = a + 1.0 + c + d;
    REQUIRE(result == 9.0);
    result = a + b + 1.0 + d;
    REQUIRE(result == 8.0);
    result = a + b + c + 1.0;
    REQUIRE(result == 7.0);
  }

  SECTION("should be able to add basic (complex) number types") {
    Complex result;
    result = a + b + c + 1.0i;
    REQUIRE(result == 6.0 + 1.0i);
  }

  SECTION("should be able to add assign") {
    Complex result(a);
    result += b;
    REQUIRE(result == 3.0);
  }

  SECTION("should be able to add assign basic number types") {
    Complex result(a);
    result += 1.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to add assign basic (complex) number types") {
    Complex result(a);
    result += 1.0i;
    REQUIRE(result == 1.0 + 1.0i);
  }

  SECTION("should be able to divide complex numbers") {
    Complex result;
    result = b / a;
    REQUIRE(result == 2.0);
    result = d / b / a;
    REQUIRE(result == 2.0);
    result = d / b / a / a;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide basic number types") {
    Complex result;
    result = b / 1.0;
    REQUIRE(result == 2.0);
    result = 2.0 / a;
    REQUIRE(result == 2.0);

    result = 4.0 / b / a;
    REQUIRE(result == 2.0);
    result = d / 2.0 / a;
    REQUIRE(result == 2.0);
    result = d / b / 1.0;
    REQUIRE(result == 2.0);

    result = 4.0 / b / a / a;
    REQUIRE(result == 2.0);
    result = d / 2.0 / a / a;
    REQUIRE(result == 2.0);
    result = d / b / 1.0 / a;
    REQUIRE(result == 2.0);
    result = d / b / a / 1.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide basic (complex) number types") {
    Complex result;
    result = d / b / a / 1.0i;
    REQUIRE(result == -2.0i);
  }

  SECTION("should be able to divide assign") {
    Complex result(b);
    result /= a;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide assign basic number types") {
    Complex result(b);
    result /= 1.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to divide assign basic (complex) number types") {
    Complex result(b);
    result /= 1.0i;
    REQUIRE(result == -2.0i);
  }

  SECTION("should be able to multiply complex numbers") {
    Complex result;
    result = a * b;
    REQUIRE(result == 2.0);
    result = a * b * c;
    REQUIRE(result == 6.0);
    result = a * b * c * d;
    REQUIRE(result == 24.0);
  }

  SECTION("should be able to multiply basic number types") {
    Complex result;
    result = 1.0 * b;
    REQUIRE(result == 2.0);
    result = a * 2.0;
    REQUIRE(result == 2.0);

    result = 1.0 * b * c;
    REQUIRE(result == 6.0);
    result = a * 2.0 * c;
    REQUIRE(result == 6.0);
    result = a * b * 3.0;
    REQUIRE(result == 6.0);

    result = 1.0 * b * c * d;
    REQUIRE(result == 24.0);
    result = a * 2.0 * c * d;
    REQUIRE(result == 24.0);
    result = a * b * 3.0 * d;
    REQUIRE(result == 24.0);
    result = a * b * c * 4.0;
    REQUIRE(result == 24.0);
  }

  SECTION("should be able to multiply basic (complex) number types") {
    Complex result;
    result = a * b * c * 4.0i;
    REQUIRE(result == 24.0i);
  }

  SECTION("should be able to multiply assign") {
    Complex result(a);
    result *= b;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to multiply assign basic number types") {
    Complex result(a);
    result *= 2.0;
    REQUIRE(result == 2.0);
  }

  SECTION("should be able to multiply assign basic (complex) number types") {
    Complex result(a);
    result *= 2.0i;
    REQUIRE(result == 2.0i);
  }

  SECTION("should be able to subtract complex numbers") {
    Complex result;
    result = a - b;
    REQUIRE(result == -1.0);
    result = a - b - c;
    REQUIRE(result == -4.0);
    result = a - b - c - d;
    REQUIRE(result == -8.0);
  }

  SECTION("should be able to subtract basic number types") {
    Complex result;
    result = 1.0 - b;
    REQUIRE(result == -1.0);
    result = a - 2.0;
    REQUIRE(result == -1.0);

    result = 1.0 - b - c;
    REQUIRE(result == -4.0);
    result = a - 2.0 - c;
    REQUIRE(result == -4.0);
    result = a - b - 3.0;
    REQUIRE(result == -4.0);

    result = 1.0 - b - c - d;
    REQUIRE(result == -8.0);
    result = a - 2.0 - c - d;
    REQUIRE(result == -8.0);
    result = a - b - 3.0 - d;
    REQUIRE(result == -8.0);
    result = a - b - c - 4.0;
    REQUIRE(result == -8.0);
  }

  SECTION("should be able to subtract basic (complex) number types") {
    Complex result;
    result = a - b - c - 4.0i;
    REQUIRE(result == -4.0 - 4.0i);
  }

  SECTION("should be able to subtract assign") {
    Complex result(a);
    result -= b;
    REQUIRE(result == -1.0);
  }

  SECTION("should be able to subtract assign basic number types") {
    Complex result(a);
    result -= 2.0;
    REQUIRE(result == -1.0);
  }

  SECTION("should be able to subtract assign basic (complex) number types") {
    Complex result(a);
    result -= 2.0i;
    REQUIRE(result == 1.0 - 2.0i);
  }

  SECTION("should be able to perform mixed operations") {
    Complex result;
    result = a + (b / (a * d)) - a;
    REQUIRE(result == 0.5);
  }
}
