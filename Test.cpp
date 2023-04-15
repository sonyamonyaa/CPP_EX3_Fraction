#include "doctest.h"
#include "Fraction.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Valid Fraction"){
    //denominator must not be 0
    CHECK_THROWS(Fraction(1,0)); 
    CHECK_THROWS(Fraction(0,0));

    //any integer is a fraction
    CHECK_NOTHROW(Fraction(0)); 
    CHECK_NOTHROW(Fraction(3));
    CHECK_NOTHROW(Fraction(-5));

    //zero fraction
    CHECK_NOTHROW(Fraction(0,2));
    CHECK_NOTHROW(Fraction(0,-2));
}

TEST_CASE("Test 2 - Arithmetic Operations"){

}

TEST_CASE("Test 3 - Boolean Operations"){

}

TEST_CASE("Test 4 - Increament and Decreament"){

}

TEST_CASE("Test 5 - streams"){

}

TEST_CASE("Test 6 - Reduce Fraction"){

}