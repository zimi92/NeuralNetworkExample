/*############################################################
this is demonstrated usage of Matrix class which uses some 
basic matrix operations. Using those i wrote a simple 
neural network example where program learns when three digits
should print 1 and when 0
##############################################################*/
#include <iostream>
#include "Matrix.h"
#include <cmath>

int main() 
{
	std::vector<std::vector<long double>> inpuData{
		 {1., 1., 0 },
		 {1., 1., 0.},
		 {1., 0., 1. },
		 {1., 0., 1. }};
	std::vector<std::vector<long double>> outputData{ { 0, 0, 1., 1.} };

	Matrix inputArray(inpuData);
	Matrix outputArray(outputData);
	outputArray = outputArray.transposeMe();

	auto syn0 = Matrix(3, 3);
	auto syn1 = Matrix(3, 1);

	const int HOWMUCHREPETITION = 500;
	syn0.nonlin(false).printMatrix();

	for (int i = 0; i < HOWMUCHREPETITION; i++) {
		auto inputMatrix = inputArray;
		auto firstMultiplication = (inputMatrix * syn0).nonlin(false);

		auto secondMultiplication = (firstMultiplication * syn1).nonlin(false);

		auto errorMatrix = outputArray - secondMultiplication;
		auto delta = Matrix::multiply(errorMatrix, (secondMultiplication.nonlin(true)));

		auto errorMatrix2 = delta * syn1.transposeMe();

		auto delta2 = Matrix::multiply(errorMatrix2, (firstMultiplication.nonlin(true)));

		syn1 = syn1 + (firstMultiplication.transposeMe() * delta);
		syn0 = syn0 + (inputMatrix.transposeMe() * delta2);
	}

	inpuData = { { 0, 1., 0 } };
	Matrix testInputArray(inpuData);
	auto inputMatrix = testInputArray;
	auto firstMultiplication = (inputMatrix * syn0).nonlin(false);

	auto secondMultiplication = (firstMultiplication * syn1).nonlin(false);
	secondMultiplication.printMatrix();

	getchar();
	return 0;
}