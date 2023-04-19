#pragma once
#include <iostream>
#include <cmath>
#include <string>
const int double_denom = 1000;
namespace ariel
{
    class Fraction
    {
    private:
        int nomintr;
        int denomintr;

    public:
        Fraction(int Numinator, const int Denomintr) : nomintr(Numinator), denomintr(Denomintr)
        {
            if (denomintr == 0)
            {
                throw std::string { "denominator cannot be 0" };
            }
            lowestFrac(nomintr, denomintr);
        }
        Fraction(int integer) : Fraction(integer, 1) {}
        Fraction(float num) : denomintr(double_denom)
        {
            float rounded = roundPoint3(num); // make sure it's 3 point decimal
            nomintr = int(rounded * double_denom);
            lowestFrac(nomintr, denomintr);
        }
        // assist funcs
        float roundPoint3(float num) const;
        void lowestFrac(int &nom, int &denom); // reduce fraction - https://www.tutorialspoint.com/reduce-the-fraction-to-its-lowest-form-in-cplusplus

        /** arithmetic
         * The + operator to add two fractions and return their sum as another fraction in reduced form.
         * The - operator to subtract two fractions and return their difference as another fraction in reduced form.
         * The * operator to multiply two fractions and return their product as another fraction in reduced form.
         * The / operator to divide two fractions and return their quotient as another fraction in reduced form.
         */
        friend Fraction operator+(const Fraction &frac, const Fraction &other);
        friend Fraction operator-(const Fraction &frac, const Fraction &other);
        friend Fraction operator*(const Fraction &frac, const Fraction &other);
        friend Fraction operator/(const Fraction &frac, const Fraction &other);

        // floats/doubles
        friend Fraction operator+(const Fraction &frac, const float other) { return frac + Fraction(other); }
        friend Fraction operator-(const Fraction &frac, const float other) { return frac - Fraction(other); }
        friend Fraction operator*(const Fraction &frac, const float other) { return frac * Fraction(other); }
        friend Fraction operator/(const Fraction &frac, const float other) { return frac / Fraction(other); }

        friend Fraction operator+(const float frac, const Fraction &other) { return other + frac; }
        friend Fraction operator-(const float frac, const Fraction &other) { return Fraction(frac) - other; }
        friend Fraction operator*(const float frac, const Fraction &other) { return other * frac; }
        friend Fraction operator/(const float frac, const Fraction &other) { return Fraction(frac) / other; }

        /**
         * comparisons
         * The == operator to compare two fractions for equality and return true or false.
         * All comparison operations (>,<,>=,<=)
         */
        friend bool operator<(const Fraction &frac, const Fraction &other);
        friend bool operator>(const Fraction &frac, const Fraction &other);
        friend bool operator<=(const Fraction &frac, const Fraction &other) { return !(frac > other); }
        friend bool operator>=(const Fraction &frac, const Fraction &other) { return !(frac < other); }
        friend bool operator==(const Fraction &frac, const Fraction &other);

        // floats/doubles
        friend bool operator<(const Fraction &frac, const float other) { return frac < Fraction(other); }
        friend bool operator>(const Fraction &frac, const float other) { return frac > Fraction(other); }
        friend bool operator<=(const Fraction &frac, const float other) { return frac <= Fraction(other); }
        friend bool operator>=(const Fraction &frac, const float other) { return frac >= Fraction(other); }
        friend bool operator==(const Fraction &frac, const float other) { return frac == Fraction(other); }

        friend bool operator<(const float frac, const Fraction &other) { return Fraction(frac) < other; }
        friend bool operator>(const float frac, const Fraction &other) { return Fraction(frac) > other; }
        friend bool operator<=(const float frac, const Fraction &other) { return Fraction(frac) <= other; }
        friend bool operator>=(const float frac, const Fraction &other) { return Fraction(frac) >= other; }
        friend bool operator==(const float frac, const Fraction &other) { return Fraction(frac) == other; }
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
        friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);
        friend std::istream &operator>>(std::istream &input, Fraction &frac);
        friend std::ostream &operator<<(std::ostream &output, const float frac) { return output << Fraction(frac); }
        friend std::istream &operator>>(std::istream &input, float &frac);
    };
}