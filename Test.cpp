#include "doctest.h"
#include "Fraction.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Valid Fraction")
{
    // denominator must not be 0
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(0, 0));

    // any integer is a fraction
    CHECK_NOTHROW(Fraction(0));
    CHECK_NOTHROW(Fraction(3));
    CHECK_NOTHROW(Fraction(-5));

    // zero fraction
    CHECK_NOTHROW(Fraction(0, 2));
    CHECK_NOTHROW(Fraction(0, -2));
}

TEST_CASE("Test 2 - Arithmetic Operations")
{
    SUBCASE("FRACTION BY FRACTION")
    {
        Fraction a(5, 3), b(14, 21);
        CHECK_NOTHROW(a + b);
        CHECK_NOTHROW(a - b);
        CHECK_NOTHROW(a * b);
        CHECK_NOTHROW(a / b);
    }

    SUBCASE("FLOAT BY FRACTION")
    {
        Fraction a(5, 3);
        float f = 2.421;
        CHECK_NOTHROW(f + a);
        CHECK_NOTHROW(f - a);
        CHECK_NOTHROW(f * a);
        CHECK_NOTHROW(f / a);

        Fraction b(0);
        CHECK_THROWS(f / b);
    }
    SUBCASE("FRACTION BY FLOAT")
    {
        Fraction a(5, 3);
        float f = 2.421;
        CHECK_NOTHROW(a + f);
        CHECK_NOTHROW(a - f);
        CHECK_NOTHROW(a * f);
        CHECK_NOTHROW(a / f);
    }
}

TEST_CASE("Test 3 - Boolean Operations")
{
    Fraction a(5, 2), b(1, 2);
    Fraction c(10, 4); // testing for reduction
    float f = 2.5;
    SUBCASE("FRACTION BY FRACTION")
    {
        CHECK_EQ(a < b, false);
        CHECK_EQ(a > b, true);
        CHECK_EQ(c <= b, false);
        CHECK_EQ(a >= c, true);
        CHECK_EQ(b <= c, true);
        CHECK_EQ(a == c, true);
    }

    SUBCASE("FLOAT BY FRACTION")
    {
        CHECK_EQ(f < b, false);
        CHECK_EQ(f > b, true);
        CHECK_EQ(f <= c, true);
        CHECK_EQ(f >= a, true);
        CHECK_EQ(f == a, true);
    }

    SUBCASE("FRACTION BY FLOAT")
    {
        CHECK_EQ(b < f, true);
        CHECK_EQ(b > f, false);
        CHECK_EQ(c <= f, true);
        CHECK_EQ(a >= f, true);
        CHECK_EQ(c == f, true);
    }
}

TEST_CASE("Test 4 - Increament and Decreament")
{
    Fraction a(5, 2), b(1, 2);
    float f = 1.5;
    Fraction c = b++;
    CHECK_EQ(c == Fraction(1, 2), true);
    CHECK_EQ(c == b, false); // should not be equal now
    CHECK_EQ(b == f, true);
    CHECK_EQ(++b == a, true); // should increament then check if equal.
    b--;                      // decrease
    CHECK_EQ(b == f, true);   // if decreament works this should work
    CHECK_EQ(--b == c, true); // same as at the start
}

TEST_CASE("Test 5 - output stream")
{
    Fraction a(5, 2), b(1, 2);
    float f = 2.5;

    CHECK_NOTHROW(cout << "a: " << a << " b: " << b << endl);
    CHECK_NOTHROW(cout << "a + b = " << a + b << endl);
    CHECK_NOTHROW(cout << "a - b = " << a - b << endl);
    CHECK_NOTHROW(cout << "a / b = " << a / b << endl);
    CHECK_NOTHROW(cout << "a * b = " << a * b << endl);

    CHECK_NOTHROW(cout << f << " + b = " << f + b << endl);
    CHECK_NOTHROW(cout << f << " - b = " << f - b << endl);
    CHECK_NOTHROW(cout << f << " * b = " << f * b << endl);
    CHECK_NOTHROW(cout << f << " / b = " << f / b << endl);

    CHECK_NOTHROW(cout << "a + " << f << " = " << a + f << endl);
    CHECK_NOTHROW(cout << "a - " << f << " = " << a - f << endl);
    CHECK_NOTHROW(cout << "a * " << f << " = " << a * f << endl);
    CHECK_NOTHROW(cout << "a / " << f << " = " << a / f << endl);
}

TEST_CASE("Test 6 - Input Stream")
{
    Fraction b(1, 2);
    SUBCASE("input to fraction")
    {
        istringstream input("1 2");
        Fraction a(5, 2);

        CHECK_NOTHROW(input >> a);
        CHECK_EQ(a == b, true); //'a' should be changed to 1/2 = b
    }
}
// SUBCASE("INPUT TO FLOAT")
// {
//     ifstream input("objects/test.txt");
//     float f = 0;
//     cout << "f before input " << Fraction(f) << endl;
//     input >> f;
//     cout << "f after input " << Fraction(f) << endl;
//     CHECK_EQ(f == 0.5, true); //'f' should be changed to 0.5
//     CHECK_EQ(f == b, true);   // which equals to 1/2 = b
// }

