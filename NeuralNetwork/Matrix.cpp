#include "Matrix.h"



Matrix::Matrix(int x, int y)
{
	for (int i = 0; i < x; i++) {
		_matrix.push_back(std::vector<float>(y));
		for (auto &iter : _matrix.back()) 
		{
			iter = (rand() % 100) / 100.F;
			std::cout << iter << std::endl;
		}
	}
	std::cout <<"Matrix constructor(int, int)" <<  _matrix.size() << std::endl;
}
Matrix::Matrix(std::vector<std::vector<float>> matrix)
{
	_matrix = matrix;
	std::cout << "Matrix constructor(vector)" << _matrix.size() << std::endl;
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
				std::cout << a._matrix[i][r] <<" "<< b._matrix[r][j] << std::endl;
				partialResulat += a._matrix[i][r] * b._matrix[r][j];
			}
			std::cout << partialResulat << std::endl;
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
	std::cout << "printing matrix" << std::endl;
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
void Matrix::nonlin(bool deriv = false)
{
	if(deriv)
	for (auto& iter : _matrix) 
	{
		for (auto& iterElement : iter)
		{
			std::cout << "changing element" << std::endl;
			iterElement = iterElement * (1.0F - iterElement);
		}
	}
	return;
	for (auto& iter : _matrix)
	{
		for (auto& iterElement : iter)
		{
			std::cout << "changing element" << std::endl;
			iterElement = 1 / (1 + std::exp(iterElement));
		}
	}
	return;
}
Matrix::~Matrix()
{

}
