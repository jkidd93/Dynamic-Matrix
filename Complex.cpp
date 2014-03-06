//
//  Complex.cpp
//
//
//  Created by Hardik Patel, Thomas Borgia on 10/1/13.
//  Edited by Hardik Patel on 11/22/13
//
//
#include "Complex.h"
#include <iostream>
#include <iomanip>


using namespace std;

// Default constructor
Complex::Complex(float r, float i)

{
    real = r;
    imag = i;
}

// Overloaded add operator to add two complex numbers
const Complex Complex:: operator+(const Complex &rhs) const

{
    return(Complex(real + rhs.real, imag + rhs.imag));
}

// Overloaded << operator to output a Complex number
ostream& operator<< (ostream& lhs, const Complex& rhs)
{
    lhs  << setiosflags(ios::fixed) << setprecision(1) << rhs.real;
    lhs  << "+" << setprecision(1) << rhs.imag << "i";
    
    return lhs;
}

//Overloaded >> operator to input a complex number
istream& operator>> (istream& lhs, Complex& rhs)
{
    lhs  >> rhs.real;
    lhs  >> rhs.imag;

    return lhs;
}

//Overloaded * operator to multiply two Complex numbers
Complex Complex::operator* (Complex& rhs)
{
    Complex tempComplex(0, 0);
    return Complex((real *rhs.real) - (imag * rhs.imag), (real * rhs.imag) + (imag * rhs.real));
    
}

