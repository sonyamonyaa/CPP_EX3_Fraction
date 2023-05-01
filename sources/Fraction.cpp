#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include "Fraction.hpp"
using namespace std;

namespace ariel
{

	void Fraction::lowestFrac(int &nom, int &denom)
	{ // generalize 0 values
		if (nom == 0)
		{
			denom = 1;
		}

		int gcd = __gcd(nom, denom);
		nom /= gcd;
		denom /= gcd;

		// reduction makes only the denom negative, negate both if it happens.
		if (denom < 0)
		{
			nom *= -1;
			denom *= -1;
		}
	}

	double Fraction::roundPoint3(double num) const
	{
		double precision = 0.001;
		return std::round(num / precision) * precision;
	}

	void check_overflow(const int num1, const int num2, bool mult = false)
	{
		int max_int = std::numeric_limits<int>::max();
		int min_int = std::numeric_limits<int>::min();

		bool overflow = (num1 > 0 && num2 > 0 && num2 > (max_int - num1)) || (num1 < 0 && num2 < 0 && num2 < (min_int - num1));
		bool underflow = (num2 > 0 && num1 < (min_int + num2)) || (num2 < 0 && num1 > (max_int + num2));

		if (mult) // if multiplication check
		{
			overflow = num1 > 0 && (max_int / num1) < num2;
			underflow = overflow; // doesn't matter
		}

		if (overflow || underflow)
			throw std::overflow_error{"operation has overflowed"};
	}
	/** arithmetic*/
	Fraction operator+(const Fraction &frac, const Fraction &other)
	{
		// check overflow of multiplication
		check_overflow(frac.nomintr, other.denomintr, true);
		check_overflow(frac.denomintr, other.nomintr, true);

		int prod1 = frac.nomintr * other.denomintr;
		int prod2 = frac.denomintr * other.nomintr;

		// overflow check of nn and dd
		check_overflow(prod1, prod2); // addition overflow check
		check_overflow(frac.denomintr, other.denomintr, true);

		int nn = prod1 + prod2;
		int dd = frac.denomintr * other.denomintr;

		return Fraction(nn, dd);
	}
	Fraction operator-(const Fraction &frac, const Fraction &other)
	{
		// check overflow of multiplication
		check_overflow(frac.nomintr, other.denomintr, true);
		check_overflow(frac.denomintr, other.nomintr, true);

		int prod1 = frac.nomintr * other.denomintr;
		int prod2 = frac.denomintr * other.nomintr;

		// overflow check of nn and dd
		check_overflow(prod1, prod2); // subtraction overflow check
		check_overflow(frac.denomintr, other.denomintr, true);
		int nn = prod1 - prod2;
		int dd = frac.denomintr * other.denomintr;

		return Fraction(nn, dd);
	}

	Fraction operator*(const Fraction &frac, const Fraction &other)
	{
		check_overflow(frac.nomintr, other.nomintr, true);
		check_overflow(frac.denomintr, other.denomintr, true);
		int nn = frac.nomintr * other.nomintr;
		int dd = frac.denomintr * other.denomintr;
		return Fraction(nn, dd);
	}

	Fraction operator/(const Fraction &frac, const Fraction &other)
	{
		check_overflow(frac.nomintr, other.denomintr, true);
		check_overflow(frac.denomintr, other.nomintr, true);

		int nn = frac.nomintr * other.denomintr;
		int dd = frac.denomintr * other.nomintr;
		if (dd == 0)
		{
			throw std::runtime_error{"the other fraction is a zero"};
		}

		return Fraction(nn, dd);
	}

	/**comparisons*/
	bool operator<(const Fraction &frac, const Fraction &other)
	{
		// int common_denom = frac.denomintr * other.denomintr;
		int frac_nom = frac.nomintr * other.denomintr;
		int other_nom = other.nomintr * frac.denomintr;
		return frac_nom < other_nom;
	}
	bool operator>(const Fraction &frac, const Fraction &other)
	{
		// int common_denom = frac.denomintr * other.denomintr;
		int frac_nom = frac.nomintr * other.denomintr;
		int other_nom = other.nomintr * frac.denomintr;
		return frac_nom > other_nom;
	}
	// since both fractions are reduced on creation all is left is just comparing nominators and denominators
	bool operator==(const Fraction &frac, const Fraction &other)
	{
		bool same_nom = frac.nomintr == other.nomintr;
		bool same_denom = frac.denomintr == other.denomintr;
		return same_nom && same_denom;
	}

	/**increaments & decreaments
	 * https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading
	 */
	// prefix
	Fraction &Fraction::operator++()
	{
		this->nomintr += this->denomintr;
		return *this;
	}
	Fraction &Fraction::operator--()
	{
		this->nomintr -= this->denomintr;
		return *this;
	}
	// postfix
	Fraction Fraction::operator++(int)
	{
		Fraction old = *this;
		operator++();
		return old;
	}
	Fraction Fraction::operator--(int)
	{
		Fraction old = *this;
		operator--();
		return old;
	}

	/**streams
	 * https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
	 */
	std::ostream &operator<<(std::ostream &output, const Fraction &frac)
	{
		return output << frac.nomintr << '/' << frac.denomintr;
	}
	std::istream &operator>>(std::istream &input, Fraction &frac)
	{
		int x , y;
		input >> x >> y;
		if(!input){
			throw std::runtime_error{"only got one number"};
		}
		if (y == 0)
		{
			throw std::runtime_error{"denominator cannot be a zero"};
		}
		frac.nomintr = x; frac.denomintr = y;
		frac.lowestFrac(frac.nomintr, frac.denomintr);
		return input;
	}
	// std::istream &operator>>(std::istream &input, float &frac)
	// {
	// 	// std::istream &operator>>(std::istream &input, float &frac)
	// 	Fraction f = Fraction(frac);
	// 	// TODO: insert return statement here
	// 	input >> f;
	// 	return input;
	// }
}