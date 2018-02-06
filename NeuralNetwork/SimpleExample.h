#pragma once
#include "NeuralNetwork.h"

class SimpleExample : public NeuralNetwork
{
public:
	SimpleExample();
	void calculate() override;

	~SimpleExample();
private:
	const int HOWMUCHREPETITION = 500;
	std::vector<std::vector<long double>> testInputData = { { 0, 1., 0 } };
};

