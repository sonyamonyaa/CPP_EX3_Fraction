#include <iostream>
#include <cmath>

#include "Fraction.hpp"
using namespace std;
using namespace ariel;

/** arithmetic*/
Fraction ariel::operator+(const Fraction &a, const Fraction &other)
{
	// int nn = a.nom * other.den +
	// 	a.den * other.nom;
	// int dd = a.den * other.den;
	// return Fraction(nn, dd);
}
Fraction ariel::operator-(const Fraction &a, const Fraction &other)
{
	// int nn = nom * other.den -
	// 	den * other.nom;
	// int dd = den * other.den;
	// return Fraction(nn, dd);
}

Fraction ariel::operator*(const Fraction &a, const Fraction &other)
{
}

Fraction ariel::operator/(const Fraction &a, const Fraction &other)
{
}

/**comparisons*/
bool ariel::operator<(const Fraction &a, const Fraction &other){}
bool ariel::operator>(const Fraction &a, const Fraction &other){}
bool ariel::operator==(const Fraction &a, const Fraction &other){}

/**streams*/
ostream &ariel::operator<<(ostream &os, const Fraction &frac)
{
	// return os << frac.nom << '/' << frac.den;
}
istream &ariel::operator>>(istream &input, Fraction &frac)
{
    // TODO: insert return statement here
}
istream &ariel::operator>>(istream &input, float frac)
{
    // TODO: insert return statement here
}
