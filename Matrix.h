//
//  Matrix.h
//  
//
//  Created by Hardik Patel on 11/13/13.
//
//
#ifndef HEADERFILE_H
#define HEADERFILE_H

#include "Complex.h"
#include <iostream>
using namespace std;

class Matrix
{
private:
    
    Complex **matrixArray; //Pointer to pointer (2-D) dynamic array
    int rowCount, colCount; //Represents row and columns of matrix
    
public:
    Matrix(int = 3, int = 4); //default constructor
    Matrix(const Matrix&); //copy constructor
    ~Matrix(); //destructor
    
    //------------------------------------------------------------------------------
    //	Pre-condition:  >> operator must be recognized
    //  Post-condition: Matrix processed from input file
    //------------------------------------------------------------------------------
    friend istream& operator>> (istream&, Matrix&); //cout overload

    //------------------------------------------------------------------------------
    //	Pre-condition: << operator must be recognized
    //  Post-condition: Matrix displayed on console
    //------------------------------------------------------------------------------
    friend ostream& operator<< (ostream&, const Matrix&); //cin overload

    //------------------------------------------------------------------------------
    //	Pre-condition: Matrices being added must have same dimensions
    //  Post-condition: Two matrices are added together
    //------------------------------------------------------------------------------
    Matrix operator+ (const Matrix&)const; //add overload

    //------------------------------------------------------------------------------
    //	Pre-condition: Two matrices are being multiplied. Must satisfy dimensions.
    //  Post-condition: Two matrices are multiplied together
    //------------------------------------------------------------------------------
    Matrix operator* (const Matrix&)const; //multiplication overload

    //------------------------------------------------------------------------------
    //	Pre-condition: = operator must be recognized
    //  Post-condition: One matrix is set equal to the other matrix
    //------------------------------------------------------------------------------
    Matrix& operator= (const Matrix&); //equals overload

    //------------------------------------------------------------------------------
    //	Pre-condition: Complex number  is being multipled by a matrix
    //  Post-condition: The result is a matrix
    //------------------------------------------------------------------------------
     friend Matrix operator* (Complex&, Matrix&);

    //------------------------------------------------------------------------------
    //	Pre-condition: Matrix is added to a Complex number
    //  Post-condition: The result is a matrix
    //------------------------------------------------------------------------------
     friend Matrix operator+ (Complex&, Matrix&);

    //------------------------------------------------------------------------------
    //	Pre-condition: Matrix is multipled by Complex number
    //  Post-condition: The result is a matrix
    //------------------------------------------------------------------------------
    Matrix operator* (Complex&)const;
 
    //------------------------------------------------------------------------------
    //	Pre-condition: Complex number is being added to a matrix
    //  Post-condition: The result is a matrix
    //------------------------------------------------------------------------------
    Matrix operator+ (const Complex&)const;
    
    
};

#endif
