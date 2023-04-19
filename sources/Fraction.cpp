#include <iostream>
#include <cmath>

#include "Fraction.hpp"
using namespace std;
using namespace ariel;

void ariel::Fraction::lowestFrac(int &nom, int &denom)
{
	
}

float ariel::Fraction::roundPoint3(float num) const
{
	return 0;
}

/** arithmetic*/
ariel::Fraction ariel::operator+(const Fraction &frac, const Fraction &other)
{
	return Fraction(0);
}
ariel::Fraction ariel::operator-(const Fraction &frac, const Fraction &other)
{
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
bool ariel::operator<(const Fraction &frac, const Fraction &other)
{
	return false;
}
bool ariel::operator>(const Fraction &frac, const Fraction &other)
{
	return false;
}
bool ariel::operator==(const Fraction &frac, const Fraction &other)
{
	return false;
}

/**increaments & decreaments
 * https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading
 */
// prefix
ariel::Fraction &ariel::Fraction::operator++() { return *this; }
ariel::Fraction &ariel::Fraction::operator--() { return *this; }
// postfix
ariel::Fraction &ariel::Fraction::operator++(int) { return *this; }
ariel::Fraction &ariel::Fraction::operator--(int) { return *this; }

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
	return input >> frac.nomintr >> frac.denomintr;
}
std::istream &ariel::operator>>(std::istream &input, float &frac)
{
	// std::istream &operator>>(std::istream &input, float &frac)
	Fraction f = Fraction(frac);
	// TODO: insert return statement here
	input >> f;
	return input;
}
