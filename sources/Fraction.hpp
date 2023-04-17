#pragma once
#include <iostream>
#include <cmath>
const int double_denom = 1000;
namespace ariel
{
    class Fraction
    {
    private:
        int nomintr;
        int denomintr;
        void reduceFrac(){}  // reduce fraction - https://www.tutorialspoint.com/reduce-the-fraction-to-its-lowest-form-in-cplusplus
       
    public:
        Fraction(int Numinator, const int Denomintr) : nomintr(Numinator), denomintr(Denomintr) {}
        Fraction(int integer) : Fraction(integer, 1) {}
        Fraction(double num): denomintr(double_denom) {
            double rounded =  roundPoint3(num); //make sure it's 3 point decimal
            nomintr = int(rounded * double_denom);
            reduceFrac();
        }

        operator double() const
        {
            // https://stackoverflow.com/questions/14369673/round-double-to-3-points-decimal
            double rounded = roundPoint3(double(nomintr) / double(denomintr));
            return rounded;
        }
        double roundPoint3(double num) const;
       

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
        friend Fraction operator+(const Fraction &frac, const double other) { return frac + Fraction(other); }
        friend Fraction operator-(const Fraction &frac, const double other) { return frac - Fraction(other); }
        friend Fraction operator*(const Fraction &frac, const double other) { return frac * Fraction(other); }
        friend Fraction operator/(const Fraction &frac, const double other) { return frac / Fraction(other); }

        friend Fraction operator+(const double frac, const Fraction &other) { return other + frac; }
        friend Fraction operator-(const double frac, const Fraction &other) { return Fraction(frac) - other; }
        friend Fraction operator*(const double frac, const Fraction &other) { return other * frac; }
        friend Fraction operator/(const double frac, const Fraction &other) { return Fraction(frac) / other; }

        // integers
        friend Fraction operator+(const Fraction &frac, const int other) { return frac + Fraction(other); }
        friend Fraction operator-(const Fraction &frac, const int other) { return frac - Fraction(other); }
        friend Fraction operator*(const Fraction &frac, const int other) { return frac * Fraction(other); }
        friend Fraction operator/(const Fraction &frac, const int other) { return frac / Fraction(other); }

        friend Fraction operator+(const int frac, const Fraction &other) { return other + frac; }
        friend Fraction operator-(const int frac, const Fraction &other) { return Fraction(frac) - other; }
        friend Fraction operator*(const int frac, const Fraction &other) { return other * frac; }
        friend Fraction operator/(const int frac, const Fraction &other) { return Fraction(frac) / other; }

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
        friend bool operator<(const Fraction &frac, const double other) { return frac < Fraction(other); }
        friend bool operator>(const Fraction &frac, const double other) { return frac > Fraction(other); }
        friend bool operator<=(const Fraction &frac, const double other) { return frac <= Fraction(other); }
        friend bool operator>=(const Fraction &frac, const double other) { return frac >= Fraction(other); }
        friend bool operator==(const Fraction &frac, const double other) { return frac == Fraction(other); }

        friend bool operator<(const double frac, const Fraction &other) { return Fraction(frac) < other; }
        friend bool operator>(const double frac, const Fraction &other) { return Fraction(frac) < other; }
        friend bool operator<=(const double frac, const Fraction &other) { return Fraction(frac) <= other; }
        friend bool operator>=(const double frac, const Fraction &other) { return Fraction(frac) >= other; }
        friend bool operator==(const double frac, const Fraction &other) { return Fraction(frac) == other; }

        // integers
        friend bool operator<(const Fraction &frac, const int other) { return frac < Fraction(other); }
        friend bool operator>(const Fraction &frac, const int other) { return frac > Fraction(other); }
        friend bool operator<=(const Fraction &frac, const int other) { return frac <= Fraction(other); }
        friend bool operator>=(const Fraction &frac, const int other) { return frac >= Fraction(other); }
        friend bool operator==(const Fraction &frac, const int other) { return frac == Fraction(other); }

        friend bool operator<(const int frac, const Fraction &other) { return Fraction(frac) < other; }
        friend bool operator>(const int frac, const Fraction &other) { return Fraction(frac) < other; }
        friend bool operator<=(const int frac, const Fraction &other) { return Fraction(frac) <= other; }
        friend bool operator>=(const int frac, const Fraction &other) { return Fraction(frac) >= other; }
        friend bool operator==(const int frac, const Fraction &other) { return Fraction(frac) == other; }

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
        friend std::istream &operator>>(std::istream &input, float frac);
    };
}