//  Driver to test implementation of the Matrix class
//  Programmed by: Dr. Monisha Pulimood
//  Course: CSC 415
//  Semester: Fall 2013

#include "Matrix.h"

#include <iostream>
#include <fstream>

using namespace std;

int main (void)
{
    Matrix m1, m2, m3, m4, m5, m6;
    ifstream inStr1a, inStr1, inStr2, inStr3, inStr5;
    Complex number (5.2, 3.4);
    string infilename;
 	
    //Test overloaded stream insertion and extraction operators
    cout << "Opening Matrix 1 from file" << endl;
    cin >> infilename;
    inStr1a.open (infilename.c_str());
    inStr1a >> m1;
    cout << "Matrix 1a is " << m1 << endl;
    inStr1a.close();
    
    // Test overloaded assignment operator
    cout << "After assigning m1 to m4, m4 is: " << endl;
    m4 = m1;
    cout << m4 << endl;
    
    cout << "Re-enter Matrix 1 from a file" << endl;
    cin >> infilename;
    inStr1.open (infilename.c_str());
    inStr1 >> m1;
    cout << "Matrix 1 is " << endl << m1 << endl;
    inStr1.close();
	
    // Test if Matrix 4 is impacted by the change in Matrix 1
    cout << "Matrix 4 is now: " << endl;
    cout << m4 << endl;
    
    cout << "Enter Matrix 2 from a file" << endl;
    cin >> infilename;
    inStr2.open (infilename.c_str());
    inStr2 >> m2;
    cout << "Matrix 2 is " << endl << m2 << endl;
    inStr2.close();
    
    cout << "Enter larger Matrix 3 from a file" << endl;
    cin >> infilename;
    inStr3.open (infilename.c_str());
    inStr3 >> m3;
    cout << "Matrix 3 is " << m3 << endl;
    inStr3.close();
    
    
    // Test overloaded plus operator
    cout << "Adding compatible Matrix 1 and Matrix 2 gives:" << endl;
    m3 = m1 + m2;
    cout << m3 << endl;
    
    cout << "Adding incompatible Matrix 4 and Matrix 2 gives:" << endl;
    m3 = m4 + m2;
    cout << m3 << endl;
    
    
    cout << "Adding Matrix 1 and number gives:" << endl;
    m3 = m1 + number;
    cout << m3 << endl;
    
    cout << "Adding number and Matrix 2 gives:" << endl;
    m3 = number + m2;
    cout << m3 << endl;
    
    
    // Test overloaded multiplication operator
    
    
    cout << "Enter Matrix 5 from a file" << endl;
    cin >> infilename;
    inStr5.open (infilename.c_str());
    inStr5 >> m5;
    cout << "Matrix 5 is " << endl << m5 << endl;
    inStr5.close();
    
    cout << "Multiplying compatible Matrix 1 and Matrix 5 gives:" << endl;
    m6 = m1 * m5;
    cout << m6 << endl;
    
    cout << "Multiplying incompatible Matrix 4 and Matrix 5 gives:" << endl;
    m6 = m4 * m5;
    cout << m6 << endl;
    
    
    cout << "Multiplying Matrix 1 and number gives:" << endl;
    m6 = m1 * number;
    cout << m6 << endl;
    
    cout << "Multiplying number and Matrix 5 gives:" << endl;
    m6 = number * m5;
    cout << m6 << endl;
    
    
    cout << "Testing m1 = m1 " << endl;
    m1 = m1;
    cout << "Matrix 1 is " << endl << m1 << endl;
    
    
    
    cout << "Testing copy constructor " << endl;
    Matrix m7(m2);
    cout << "Matrix 7 is " << endl << m7 << endl;
    
    // Test if Matrix 2 is impacted by the change in Matrix 7
   
    
    m7 = m7 * number;
    
    cout << "Matrix 7 is now: " << endl;
    cout << m7 << endl;
    cout << "Matrix 2 is now: " << endl;
    cout << m2 << endl;
    
    
    
    cout << "Bye!" << endl << endl;    
	
    return 0;
}