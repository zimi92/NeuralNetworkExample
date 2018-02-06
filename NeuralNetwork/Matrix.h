#pragma once
#include <vector>
#include <iostream>
#include <cassert>

class Matrix
{
public:
	Matrix(int x, int y);
	Matrix(std::vector<std::vector<long double>> matrix);
	void printMatrix();
	Matrix transposeMe();
	std::vector<int>  getSize(bool printMe = false);
	
	void operator*(int scalar) 
	{
		for (int i = 0; i < _matrix.size(); i++)
		{
			for (int j = 0; j <  _matrix[0].size(); j++)
			{
				_matrix[i][j] *= scalar;
			}
		}
	}

	friend Matrix operator+(Matrix a, Matrix b)
	{
		Matrix resaultMatrix(a.getSize()[0], a.getSize()[1]);
		for (int i = 0; i < a.getSize()[0]; i++) 
		{
			for (int j = 0; j < a.getSize()[1]; j++)
			{
				resaultMatrix._matrix[i][j] = a._matrix[i][j] + b._matrix[i][j];
			}
		}
		return resaultMatrix;
	}

	friend Matrix operator*(Matrix a, Matrix b)
	{
		assert(a.getSize()[1] == b.getSize()[0]);
		Matrix result(a._matrix.size(), b._matrix[0].size());
		for (int i = 0; i < a._matrix.size(); i++)
		{
			for (int j = 0; j < b._matrix[0].size(); j++)
			{
				long double partialResulat = 0;
				for (int r = 0; r < a._matrix[0].size(); r++) {
					partialResulat += a._matrix[i][r] * b._matrix[r][j];
				}
				result._matrix[i][j] = partialResulat;
			}
		}
		return result;
	}

	friend Matrix operator-(Matrix a, Matrix b)
	{
		Matrix resaultMatrix(a.getSize()[0], a.getSize()[1]);
		for (int i = 0; i < a.getSize()[0]; i++)
		{
			for (int j = 0; j < a.getSize()[1]; j++)
			{
				resaultMatrix._matrix[i][j] = a._matrix[i][j] - b._matrix[i][j];
			}
		}
		return resaultMatrix;
	}

	Matrix nonlin(bool derivative);
	static Matrix multiply(Matrix a, Matrix b);
	~Matrix();

	std::vector<std::vector<long double>> _matrix;
};

