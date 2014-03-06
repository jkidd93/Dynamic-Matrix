//
//  Matrix.cpp
//  
//
//  Created by Hardik Patel on 11/13/13.
//
//

#include "Matrix.h"
#include <iostream>

using namespace std;

//Default constructor. Consists of number of rows and columns
Matrix::Matrix(int rowSize, int colSize)
{
    rowCount = rowSize;
    colCount = colSize;
    matrixArray = new Complex* [rowCount];
    for(int i = 0; i < rowCount; i++)
    {
        matrixArray[i] = new Complex [colCount];
    }
}

//Copy constructor for Matrix
Matrix::Matrix(const Matrix& rhs)
{
    rowCount = rhs.rowCount;
    colCount = rhs.colCount;
    matrixArray = new Complex* [rowCount];
    for(int i = 0; i < rowCount; i++)  //Sets up a 2-D dynamic array with complex objects
    {
        matrixArray[i] = new Complex [colCount];
    }
    
    for(int i = 0; i < rowCount; i++) //Copies each index from the orginal array
    {
        for(int j = 0; j < colCount; j++)
        {
            matrixArray[i][j] = rhs.matrixArray[i][j];
        }
    }
}

//Destructor for Matrix
Matrix::~Matrix()
{
    if(matrixArray != NULL)
    {
        for(int i = 0; i < rowCount; i++)
        {
            if(matrixArray[i] != NULL)
            delete [] matrixArray[i];
        }
        delete [] matrixArray;
    }

}

//Overloaded >> operator
istream& operator>> (istream& lhs, Matrix& rhs)
{
    //Frees previous memory and prevents memory leaks
    if(rhs.matrixArray != NULL)
    {
    for(int i = 0; i < rhs.rowCount; i++)
        {
            if(rhs.matrixArray[i] != NULL)
            delete [] rhs.matrixArray[i];
        }
            delete [] rhs.matrixArray;
    }
    
    //Obtains number of rows and columns from the input file
    lhs >> rhs.rowCount;
    lhs >> rhs.colCount;
    
    // Sets up the 2-D dynamic Complex array
    rhs.matrixArray = new Complex* [rhs.rowCount];
    for(int i = 0; i < rhs.rowCount; i++)
    {
        rhs.matrixArray[i] = new Complex [rhs.colCount];
    }
    
    //Populates each index of the 2-D array
    for(int i = 0; i < rhs.rowCount; i++)
    {
        for(int j = 0; j < rhs.colCount; j++)
        {
        lhs >> rhs.matrixArray[i][j];
        }
    }
    
    return lhs;
}

//Overloaded << operator
ostream& operator<< (ostream& lhs, const Matrix& rhs)
{
    lhs << "\n";
    for(int i = 0; i < rhs.rowCount; i++)
    {
        for(int j = 0; j < rhs.colCount; j++)
        {
            lhs << rhs.matrixArray[i][j] << "\t"; //Outputs each index seperated by tabs
        }
        lhs << "\n";
    }
    
    return lhs;
}

//Overloaded + operator for Matrix + Matrix
Matrix Matrix::operator+ (const Matrix& rhs)const
{
    //Checks if the dimensions are not the same
    if((rowCount != rhs.rowCount) || (colCount != rhs.colCount))
    {
        
       cerr<< "Only matrices with the same dimensions can be added together. Only matrix 4 will be returned"<< endl;
        
        return *this;
    }
    else //Adds the matrices if the dimensions are the same
    {
        Matrix newMatrix(rowCount, colCount); //Creates new matrix with appropriate rows and columns
        for(int i = 0; i < rhs.rowCount; i++)
        {
            for(int j = 0; j < rhs.colCount; j++)
            {
                newMatrix.matrixArray[i][j] = matrixArray[i][j] + rhs.matrixArray[i][j];
            }
        }
 
        return newMatrix;
    }
}

//Overloaded = operator for Matrix = Matrix
Matrix& Matrix::operator= (const Matrix& rhs)
{
    // If the calling object is the same as the operand, the calling object will be returned
    if (this == &rhs)
    {
        return *this;
    }
    else //If the calling object is different from the operand, proccessing continues
    {
        if(matrixArray != NULL) //Frees previous memory
        {
            for(int i = 0; i < rowCount; i++)
            {
                if(matrixArray[i] != NULL)
                delete [] matrixArray[i];
            }
            delete [] matrixArray;
        }
        
        //Sets up the 2-D dynamic Complex array
        matrixArray = new Complex* [rhs.rowCount];
        for(int i = 0; i < rhs.rowCount; i++)
        {
            matrixArray[i] = new Complex [rhs.colCount];
        }
        
        //Sets calling objects number of rows and columns to that of the operands's
        rowCount = rhs.rowCount;
        colCount = rhs.colCount;
        
        //Populates each index of the calling object with that of the operand
        for(int i = 0; i < rhs.rowCount; i++)
        {
            for(int j = 0; j < rhs.colCount; j++)
            {
            matrixArray[i][j] = rhs.matrixArray[i][j];
        }
     }
    return *this;
    }
}

//Overloaded * operator for Matrix * Matrix
Matrix Matrix::operator* (const Matrix& rhs)const
 {
    if(colCount != rhs.rowCount) //Checks if matrices have necessary dimensions for multiplication
    {
        cerr<< "Matrix does not have necessary dimensions for multiplication. Returning the original matrix now."<<endl;
        return *this;
    }
    else
    {
        Matrix newMatrix(rowCount, rhs.colCount); //Creates new matrix
        for(int i = 0; i < rowCount; i++) //Goes through calling object's rows
        {
            for(int j = 0; j < rhs.colCount; j++)//Goes through operand's columns
            {
                Complex tempComplex(0,0);
                
                for(int k = 0; k < colCount; k++) //Sets a temporary Complex number equal to the result for a future index in the new matrix
                {
                    tempComplex = (matrixArray[i][k] * rhs.matrixArray[k][j]) + tempComplex;
                }
                newMatrix.matrixArray[i][j] = tempComplex; //The new matrix's index consists of the result of the multiplication in the form of a Complex number
            }
        }
        return newMatrix;
    }
 
 }

//Overloaded * operator for Matrix * Complex
Matrix Matrix::operator* (Complex& rhs)const
{
    Matrix newMatrix(rowCount, colCount); //Creates new matrix
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            Complex tempComplex(0,0);
            tempComplex = (matrixArray[i][j] * rhs) + tempComplex; //Multiplies the Complex number by the Complex nubmer in the index of the calling matrix
            newMatrix.matrixArray[i][j] = tempComplex; //Index of the new matrix consists of the mulitplied Complex number
        }
    }
    return newMatrix;
}

//Overloaded + operator for Matrix + Complex
Matrix Matrix::operator+ (const Complex& rhs)const
{
    Matrix newMatrix(rowCount, colCount); //Creates new matrix
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
            newMatrix.matrixArray[i][j] = matrixArray[i][j] + rhs; //Adds the Complex number to each array of the calling matrix
        }
    }
    
    return newMatrix;
}

//Overloaded * operator for Matrix * Complex
Matrix operator* (Complex& lhs,  Matrix& rhs)
{
    return rhs * lhs; //This return statement will just call the overload for Matrix * Complex following the commutative property
}

Matrix operator+ (Complex& lhs,  Matrix& rhs)
{
    return rhs + lhs; //This return statement will just call the overload for Matrix + Complex following the commutative property
}




