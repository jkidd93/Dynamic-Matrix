all:dynamicMatrixExec

dynamicMatrixExec: matrixDriver.o Complex.o Matrix.o
	g++ matrixDriver.o Complex.o Matrix.o -o dynamicMatrixExec
	
matrixDriver.o: matrixDriver.cpp
	g++ -c matrixDriver.cpp
	
Complex.o: Complex.cpp
	g++ -c Complex.cpp

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp
	
clean: 
	rm -rf *o dynamicMatrixExec