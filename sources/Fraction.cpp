#include <iostream>
#include <cmath>

#include "Fraction.hpp"
using namespace std;
using namespace ariel;

double ariel::Fraction::roundPoint3(double num) const
{
	double precision = 0.001;
	return std::round(num / precision) * precision;
}
/** arithmetic*/
Fraction ariel::operator+(const Fraction &a, const Fraction &other)
{
	// int nn = a.nom * other.den +
	// 	a.den * other.nom;
	// int dd = a.den * other.den;
	return Fraction(0);
}
Fraction ariel::operator-(const Fraction &a, const Fraction &other)
{
	// int nn = nom * other.den -
	// 	den * other.nom;
	// int dd = den * other.den;
	// return Fraction(nn, dd);
	return Fraction(0);
}

Fraction ariel::operator*(const Fraction &a, const Fraction &other)
{
	return Fraction(0);
}

Fraction ariel::operator/(const Fraction &a, const Fraction &other)
{
	return Fraction(0);
}

/**comparisons*/
bool ariel::operator<(const Fraction &a, const Fraction &other) { return false; }
bool ariel::operator>(const Fraction &a, const Fraction &other) { return false; }
bool ariel::operator==(const Fraction &a, const Fraction &other) { return false; }

// prefix
Fraction &ariel::Fraction::operator++() {return *this;}
Fraction &ariel::Fraction::operator--() {return *this;}
// postfix
Fraction &ariel::Fraction::operator++(int) {return *this;}
Fraction &ariel::Fraction::operator--(int) {return *this;}
/**streams*/
std::ostream &ariel::operator<<(std::ostream &output, const Fraction &frac)
{
	return output << frac.nomintr << '/' << frac.denomintr;
}
std::istream &ariel::operator>>(std::istream &input, Fraction &frac)
{
	// TODO: insert return statement here
	return input >> frac;
}
std::istream &ariel::operator>>(std::istream &input, float frac)
{
	// TODO: insert return statement here
	return input >> Fraction(frac);
}
