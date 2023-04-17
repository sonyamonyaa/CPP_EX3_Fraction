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
ariel::Fraction  ariel::operator+(const Fraction &frac, const Fraction &other)
{
	// int nn = frac.nom * other.den +
	// 	frac.den * other.nom;
	// int dd = frac.den * other.den;
	// return Fraction(nn, dd);
	return Fraction(0);
}
ariel::Fraction ariel::operator-(const Fraction &frac, const Fraction &other)
{
	// int nn = nom * other.den -
	// 	den * other.nom;
	// int dd = den * other.den;
	// return Fraction(nn, dd);
	return Fraction(0);
}

ariel::Fraction ariel::operator*(const Fraction &frac, const Fraction &other)
{
	return Fraction(0);
}

ariel::Fraction ariel::operator/(const Fraction &frac, const Fraction &other)
{
	return Fraction(0);
}

/**comparisons*/
bool ariel::operator<(const Fraction &frac, const Fraction &other) { return false; }
bool ariel::operator>(const Fraction &frac, const Fraction &other) { return false; }
bool ariel::operator==(const Fraction &frac, const Fraction &other) { return false; }

/**increaments & decreaments
 * https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading
*/
// prefix
ariel::Fraction &ariel::Fraction::operator++() {return *this;}
ariel::Fraction &ariel::Fraction::operator--() {return *this;}
// postfix
ariel::Fraction &ariel::Fraction::operator++(int) {return *this;}
ariel::Fraction &ariel::Fraction::operator--(int) {return *this;}

/**streams
 * https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm 
*/
std::ostream &ariel::operator<<(std::ostream &output, const Fraction &frac)
{
	return output << frac.nomintr << '/' << frac.denomintr;
}
std::istream &ariel::operator>>(std::istream &input, Fraction &frac)
{
	// TODO: insert return statement here
	return input >> frac.nomintr >>frac.denomintr;
}
std::istream &ariel::operator>>(std::istream &input, float frac)
{
	// TODO: insert return statement here
	return input >> Fraction(frac);
}
