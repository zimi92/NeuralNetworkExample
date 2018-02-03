#include <iostream>
#include "Matrix.h"
#include <math.h>


int main() 
{
	/*std::vector<std::vector<float>> matrixA = { {1,2},{4,3} };
	std::vector<std::vector<float>> matrixB = { { 2,3,1},{1,1,2} };

	Matrix a(matrixA);
	Matrix b(matrixB);

	a.printMatrix();
	b.printMatrix();

	Matrix::multiply(a, b).printMatrix();
	*/
	std::vector<std::vector<float>> inpuData{ {1,1,1}, 
		 {1,1,1},
		 {1,1,1}, 
		 {1,1,1}};
	std::vector<std::vector<float>> outputData{ { 0,0,1,1} };

	Matrix inputArray(inpuData);
	Matrix outputArray(outputData);
	outputArray.transposeMe();

	auto syn0 = Matrix(3, 3);
	auto syn1 = Matrix(3, 1);

	auto inputMatrix = inputArray;
	inputArray.printMatrix();
	inputMatrix.printMatrix();
	syn0.printMatrix();

	Matrix::multiply(inputMatrix, syn0).printMatrix();
	auto firstMultiplication = Matrix::multiply(inputMatrix, syn0);
	firstMultiplication.printMatrix();
	auto secondMultiplication = Matrix::multiply(firstMultiplication, syn1);
	secondMultiplication.printMatrix();
	auto errorMatrix = outputArray - secondMultiplication;
	//auto delta = errorMatrix * nonlin()
	errorMatrix.printMatrix();
	errorMatrix.nonlin(false);
	errorMatrix.printMatrix();

	getchar();
	return 0;
}