#pragma once
#include <iostream>
#include <cmath>

namespace ariel
{
    class Fraction
    {
    private:
        int nomintr;
        int denomintr;
        //reduce fraction - https://www.tutorialspoint.com/reduce-the-fraction-to-its-lowest-form-in-cplusplus

    public:
        Fraction(int nom, int denom) : nomintr(nom), denomintr(denom) {}
        Fraction(int nom) : Fraction(nom, 1) {}
        Fraction(double num) {}

        operator double() const
        {
            // https://stackoverflow.com/questions/14369673/round-double-to-3-points-decimal
            //  return float(nomintr) / float(denomintr);
        }

        /** arithmetic
         * The + operator to add two fractions and return their sum as another fraction in reduced form.
         * The - operator to subtract two fractions and return their difference as another fraction in reduced form.
         * The * operator to multiply two fractions and return their product as another fraction in reduced form.
         * The / operator to divide two fractions and return their quotient as another fraction in reduced form.
         */
        friend Fraction operator+(const Fraction &a, const Fraction &other);
        friend Fraction operator-(const Fraction &a, const Fraction &other);
        friend Fraction operator*(const Fraction &a, const Fraction &other);
        friend Fraction operator/(const Fraction &a, const Fraction &other);

        //floats/doubles
        friend Fraction operator+(const Fraction &a, const double other) { return a + Fraction(other); }
        friend Fraction operator-(const Fraction &a, const double other) { return a - Fraction(other); }
        friend Fraction operator*(const Fraction &a, const double other) { return a * Fraction(other); }
        friend Fraction operator/(const Fraction &a, const double other) { return a / Fraction(other); }

        friend Fraction operator+(const double a, const Fraction &other) { return other + a; }
        friend Fraction operator-(const double a, const Fraction &other) { return Fraction(a) - other; }
        friend Fraction operator*(const double a, const Fraction &other) { return other * a; }
        friend Fraction operator/(const double a, const Fraction &other) { return Fraction(a) / other; }

        //integers
        friend Fraction operator+(const Fraction &a, const int other) { return a + Fraction(other); }
        friend Fraction operator-(const Fraction &a, const int other) { return a - Fraction(other); }
        friend Fraction operator*(const Fraction &a, const int other) { return a * Fraction(other); }
        friend Fraction operator/(const Fraction &a, const int other) { return a / Fraction(other); }

        friend Fraction operator+(const int a, const Fraction &other) { return other + a; }
        friend Fraction operator-(const int a, const Fraction &other) { return Fraction(a) - other; }
        friend Fraction operator*(const int a, const Fraction &other) { return other * a; }
        friend Fraction operator/(const int a, const Fraction &other) { return Fraction(a) / other; }

        /**
         * comparisons
         * The == operator to compare two fractions for equality and return true or false.
         * All comparison operations (>,<,>=,<=)
         */
        friend bool operator<(const Fraction &a, const Fraction &other);
        friend bool operator>(const Fraction &a, const Fraction &other);
        friend bool operator<=(const Fraction &a, const Fraction &other) { return !(a > other); }
        friend bool operator>=(const Fraction &a, const Fraction &other) { return !(a < other); }
        friend bool operator==(const Fraction &a, const Fraction &other);

        //floats/doubles
        friend bool operator<(const Fraction &a, const double other) { return a < Fraction(other); }
        friend bool operator>(const Fraction &a, const double other) { return a > Fraction(other); }
        friend bool operator<=(const Fraction &a, const double other) { return a <= Fraction(other); }
        friend bool operator>=(const Fraction &a, const double other) { return a >= Fraction(other); }
        friend bool operator==(const Fraction &a, const double other) { return a == Fraction(other); }

        friend bool operator<(const double a, const Fraction &other) { return Fraction(a) < other; }
        friend bool operator>(const double a, const Fraction &other) { return Fraction(a) < other; }
        friend bool operator<=(const double a, const Fraction &other) { return Fraction(a) <= other; }
        friend bool operator>=(const double a, const Fraction &other) { return Fraction(a) >= other; }
        friend bool operator==(const double a, const Fraction &other) { return Fraction(a) == other; }

        //integers
        friend bool operator<(const Fraction &a, const int other) { return a < Fraction(other); }
        friend bool operator>(const Fraction &a, const int other) { return a > Fraction(other); }
        friend bool operator<=(const Fraction &a, const int other) { return a <= Fraction(other); }
        friend bool operator>=(const Fraction &a, const int other) { return a >= Fraction(other); }
        friend bool operator==(const Fraction &a, const int other) { return a == Fraction(other); }

        friend bool operator<(const int a, const Fraction &other) { return Fraction(a) < other; }
        friend bool operator>(const int a, const Fraction &other) { return Fraction(a) < other; }
        friend bool operator<=(const int a, const Fraction &other) { return Fraction(a) <= other; }
        friend bool operator>=(const int a, const Fraction &other) { return Fraction(a) >= other; }
        friend bool operator==(const int a, const Fraction &other) { return Fraction(a) == other; }

        /**
         * increaments & decreaments
         * The ++ and -- operator that adds (or substracts) 1 to the fraction.
         */

        // prefix
        Fraction &operator++();
        Fraction &operator--();
        // postfix
        Fraction &operator++(int);
        Fraction &operator--(int);

        /**
         * streams
         * The << operator to print a fraction to an output stream in the format “numerator/denominator”.
         * The >> operator to read a fraction from an input stream by taking two integers as input.
         */
        friend ostream &operator<<(ostream &os, const Fraction &frac);
        friend istream &operator>>(istream &input, Fraction &frac);
        friend ostream &operator<<(ostream &os, const float frac) {return os<<Fraction(frac);}
        friend istream &operator>>(istream &input, float frac);
    };
}