//
//  Complex.h
//  
//
//  Created by Hardik Patel, Thomas Borgia on 10/1/13.
//  Edited by Hardik Patel on 11/22/13
//
//

#include <iostream>

using namespace std;

class Complex
{
    
private:
    float real; //The real number part of a Complex number
    float imag; //The imaginary part of a Complex number
    
public:
    Complex (float = 0.0, float = 0.0); //Default constructor
    const Complex operator+(const Complex&)const;
    //------------------------------------------------------------------------------
    //	Pre-condition:  Two complex number are being added
    //  Post-condition: Result is a complex number
    //------------------------------------------------------------------------------
    
    friend ostream& operator<< (ostream&, const Complex&);
    //------------------------------------------------------------------------------
    //	Pre-condition: << operator is recognized
    //  Post-condition: Complex number is outputted with proper formatting
    //------------------------------------------------------------------------------
    
    friend istream& operator>> (istream&, Complex&);
    //------------------------------------------------------------------------------
    //	Pre-condition: >> operator is recognized
    //  Post-condition: Complex number is inputted
    //------------------------------------------------------------------------------
    
    Complex operator* (Complex&);
    //------------------------------------------------------------------------------
    //	Pre-condition: Two complex numbers are being multiplied
    //  Post-condition: Product is a Complex number
    //------------------------------------------------------------------------------
};
