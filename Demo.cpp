/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(2,3), b(14,21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c(-1,5);
    cout << c++ << endl;
    cout << --c << endl;

    cout << "-3/4 , 3/-4 : " <<(Fraction{-3, 4} == Fraction{3, -4}) <<endl;

    cout << "c >=b ? : " << (c >= a) << endl;
    if (c >= a) cout << c << " is bigger than" << a << endl;
    else cout <<  c << " is smaller than" << a << endl;


}
