#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "Polynomial.h"
#include "catch.hpp"

using namespace std;


int main() {

    Catch::Session().run();
    return 0;
}

TEST_CASE("PolynomialClass tests", "[Square]") {
SECTION("Laba 1") {
Polynomial test;
REQUIRE(test.toString() == nullptr);

double c1[] = {-1, 8, -9, 2, 4};
Polynomial one(4, c1);
REQUIRE(strcmp(one.toString(), "4x^4 + 2x^3 - 9x^2 + 8x^1 - 1") == 0);

double c2[] = {-3, 32, 1, -12, 5, 6, -9};
Polynomial two(6, c2);
REQUIRE(strcmp(two.toString(), "-9x^6 + 6x^5 + 5x^4 - 12x^3 + 1x^2 + 32x^1 - 3") == 0);

Polynomial three(one);
REQUIRE(strcmp(three.toString(), one.toString()) == 0);

REQUIRE(one.getDegree() == 4);
REQUIRE(two.getDegree() == 6);

REQUIRE(one.evaluate(2) == 59);
REQUIRE(two.evaluate(2) == -335);
}

SECTION("Laba 2") {
double c1[] = {1, 11, 9, -3, 5};
Polynomial one(4, c1);
double c2[] = {-9, 3, -17, 10, 8, -6};
Polynomial two(5, c2);

Polynomial three;
three = one + two;
REQUIRE(strcmp(three.toString(), "-6x^5 + 13x^4 + 7x^3 - 8x^2 + 14x^1 - 8") == 0);
Polynomial four;
four = two - one;
REQUIRE(strcmp(four.toString(), "-6x^5 + 3x^4 + 13x^3 - 26x^2 - 8x^1 - 10") == 0);

++one;
REQUIRE(strcmp(one.toString(), "5x^5 - 3x^4 + 9x^3 + 11x^2 + 1x^1 - 0") == 0);
--two;
REQUIRE(strcmp(two.toString(), "-6x^4 + 8x^3 + 10x^2 - 17x^1 + 3") == 0);

REQUIRE(three(-1) == -18);
REQUIRE(four(5) == -15950);

REQUIRE(three[1] == 14);
REQUIRE(four[2] == -26);
}
}


