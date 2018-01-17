#include <iostream>
#include "Matrix.h"
#include <math.h>
float nonlin(float x, bool deriv = false) 
{
	if (deriv)
		return x * (1 - x);
	return 1 / (1 + std::exp(x));
}

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
	std::vector<std::vector<float>> inpuData{ {1,1,0}, 
		 {1,0,1},
		 {1,0,0}, 
		 {0,1,0}};
	std::vector<std::vector<float>> outputData{ { 0,0,1,1} };

	Matrix inputArray(inpuData);
	Matrix outputArray(outputData);
	outputArray.transposeMe();

	auto syn0 = Matrix(3, 3);
	auto syn1 = Matrix(3, 1);

	auto inputMatrix = inputArray;
	auto firstMultiplication = Matrix::multiply(inputMatrix, syn0);
	auto secondMultiplication = Matrix::multiply(firstMultiplication, syn1);

	auto errorMatrix = outputArray - secondMultiplication;
	//auto delta = errorMatrix * nonlin()

	getchar();
	return 0;
}