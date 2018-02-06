#include "SimpleExample.h"



SimpleExample::SimpleExample()
{
	inpuData = {
		{ 1., 1., 0 },
		{ 1., 1., 0. },
		{ 1., 0., 1. },
		{ 1., 0., 1. } };

	outputData = { { 0, 0, 1., 1. } };

}

///All calculations in this method
void SimpleExample::calculate() 
{
	//Making Matrix from input/output vectors
	Matrix inputArray(inpuData);
	Matrix outputArray(outputData);
	outputArray = outputArray.transposeMe();

	//Wages of Neural Networks are randomise at the begginging
	auto syn0 = Matrix(3, 3);
	auto syn1 = Matrix(3, 1);

	//the process of backpropagation learning of Neural Network will last for a chosen amount of time
	//higher repetition number, more precise the network will be
	for (int i = 0; i < HOWMUCHREPETITION; i++) {
		auto inputMatrix = inputArray;
		//all imputs are being multiply by all wages and sums, then calculated values are being flatted 
		//to numbers between 0-1 by sigma function to be values of hidden neural network layer
		auto firstMultiplication = (inputMatrix * syn0).sigmaOnMatrix(false);
		//than simmilar process is taking place between hiddden layer and output
		auto secondMultiplication = (firstMultiplication * syn1).sigmaOnMatrix(false);

		//################################################################################
		//this is the end of neural networ calculation if it is trained, unfortunately
		//at the begginging we have random wage values so now it is necessary to calculate 
		//the error betwen calculated values and designed output
		//################################################################################

		auto errorMatrix = outputArray - secondMultiplication;
		auto delta = Matrix::multiply(errorMatrix, (secondMultiplication.sigmaOnMatrix(true)));

		auto errorMatrix2 = delta * syn1.transposeMe();

		auto delta2 = Matrix::multiply(errorMatrix2, (firstMultiplication.sigmaOnMatrix(true)));

		syn1 = syn1 + (firstMultiplication.transposeMe() * delta);
		syn0 = syn0 + (inputMatrix.transposeMe() * delta2);
	}

	Matrix testInputArray(testInputData);
	auto inputMatrix = testInputArray;
	auto firstMultiplication = (inputMatrix * syn0).sigmaOnMatrix(false);

	auto secondMultiplication = (firstMultiplication * syn1).sigmaOnMatrix(false);
	std::cout << "for given test data the output looks like this:" << std::endl;
	secondMultiplication.printMatrix();
}

SimpleExample::~SimpleExample()
{
}
