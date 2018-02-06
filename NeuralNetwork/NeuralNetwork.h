#pragma once
#include "Matrix.h"

class NeuralNetwork
{
public:
	NeuralNetwork();
	std::vector<std::vector<long double>> inpuData;
	std::vector<std::vector<long double>> outputData;
	void virtual calculate() = 0;
	~NeuralNetwork();
};

