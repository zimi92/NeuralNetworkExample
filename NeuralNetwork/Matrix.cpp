#include "Matrix.h"



Matrix::Matrix(int x, int y)
{
	for (int i = 0; i < x; i++) {
		std::cout << "debug log in" << std::endl;
		_matrix.push_back(std::vector<float>(y));
		for (auto iter : _matrix.back()) 
		{
			iter = (rand() % 100) / 100.F;
		}
	}
	std::cout << _matrix.size() << std::endl;

}
Matrix::Matrix(std::vector<std::vector<float>> matrix)
{
	_matrix = matrix;
}

Matrix Matrix::multiply(Matrix a, Matrix b)
{
	Matrix result(a._matrix.size(), b._matrix[0].size());
	for (int i = 0; i < a._matrix.size(); i++)
	{
		for (int j = 0; j < b._matrix[0].size(); j++)
		{
			float partialResulat = 0;
			for (int r = 0; r < a._matrix[0].size(); r++) {
				std::cout << i << " " << j << " " << r << std::endl;
				std::cout << a._matrix[i][r] * b._matrix[r][j] << std::endl;
				partialResulat += a._matrix[i][r] * b._matrix[r][j];
			}
			result._matrix[i][j] = partialResulat;
		}
	}
	return result;
}

void Matrix::transposeMe() 
{
	std::vector<std::vector<float>> matrix;
	for (int i = 0; i < _matrix[0].size(); i++) 
	{
		matrix.push_back(std::vector<float>(_matrix.size()));
	}
	for (int i = 0; i < _matrix[0].size(); i++) 
	{
		for (int j = 0; j < _matrix.size(); j++)
		{
			matrix[i][j] = _matrix[j][i];
		}
	}
	_matrix = matrix;
}

void Matrix::printMatrix() 
{
	for (auto i : _matrix) 
	{
		for (auto j : i) 
		{
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
}

std::vector<int> Matrix::getSize()
{
	std::cout <<"getSize: "<< _matrix.size() << " " << _matrix[0].size() << std::endl;
	return std::vector<int>{static_cast<int>(_matrix.size()),static_cast<int>( _matrix[0].size())};
}

Matrix::~Matrix()
{

}
