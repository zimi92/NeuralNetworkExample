#include "Matrix.h"

Matrix::Matrix(int x, int y)
{
	for (int i = 0; i < x; i++) {
		_matrix.push_back(std::vector<long double>(y));
		for (auto &iter : _matrix.back()) 
		{
			iter = static_cast<long double>((rand() % 100) / 100.F);
		}
	}
}

Matrix::Matrix(std::vector<std::vector<long double>> matrix)
{
	_matrix = matrix;
}

Matrix Matrix::transposeMe() 
{
	std::vector<std::vector<long double>> matrix;
	for (int i = 0; i < _matrix[0].size(); i++) 
	{
		matrix.push_back(std::vector<long double>(_matrix.size()));
	}
	for (int i = 0; i < _matrix[0].size(); i++) 
	{
		for (int j = 0; j < _matrix.size(); j++)
		{
			matrix[i][j] = _matrix[j][i];
		}
	}
	return matrix;
}

void Matrix::printMatrix() 
{
	std::cout << "printing matrix" << std::endl;
	for (auto i : _matrix) 
	{
		for (auto j : i) 
		{
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

std::vector<int> Matrix::getSize(bool printMe)
{
	if (printMe)
	{
		std::cout << "getSize: " << _matrix.size() << " " << _matrix[0].size() << std::endl;
	}
	return std::vector<int>{static_cast<int>(_matrix.size()),static_cast<int>( _matrix[0].size())};
}

Matrix Matrix::sigmaOnMatrix(bool deriv = false)
{
	auto nonLinMatrix = _matrix;
	if (deriv) 
	{
		for (auto& iter : nonLinMatrix)
		{
			for (auto& iterElement : iter)
			{
				iterElement = iterElement * (1.0 - iterElement);
			}
		}
		return nonLinMatrix;
	}
	for (auto& iter : nonLinMatrix)
	{
		for (auto& iterElement : iter)
		{
			iterElement = 1.0 / (1.0 + std::expl(-iterElement));
		}
	}
	return nonLinMatrix;
}

Matrix Matrix::multiply(Matrix a, Matrix b) 
{
	Matrix matrixReturn(a.getSize()[0], a.getSize()[1]);
	assert((a.getSize()[0] == b.getSize()[0] && a.getSize()[1] == b.getSize()[1]));
	
	for (int i = 0; i < a.getSize()[0]; i++) 
	{
		for (int j = 0; j < a.getSize()[1]; j++) 
		{
			matrixReturn._matrix[i][j] = a._matrix[i][j] * b._matrix[i][j];
		}
	}
	
	return matrixReturn;
}

Matrix::~Matrix()
{

}
