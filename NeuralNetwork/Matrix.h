#pragma once
#include <vector>
#include <iostream>
class Matrix
{
public:
	Matrix(int x, int y);
	Matrix(std::vector<std::vector<float>> matrix);
	static Matrix multiply(Matrix a, Matrix b);
	void printMatrix();
	void transposeMe();
	std::vector<int>  getSize();
	
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
	friend Matrix& operator+(Matrix a, Matrix b)
	{
		Matrix resaultMatrix(a.getSize()[0], a.getSize()[1]);
		for (int i = 0; i < a.getSize()[0]; i++) 
		{
			for (int j = 0; j < a.getSize()[0]; j++)
			{
				resaultMatrix._matrix[i][j] = a._matrix[i][j] + b._matrix[i][j];
			}
		}
		return resaultMatrix;
	}
	friend Matrix& operator-(Matrix a, Matrix b)
	{
		Matrix resaultMatrix(a.getSize()[0], a.getSize()[1]);
		std::cout << a.getSize()[0] << " " << a.getSize()[1] << std::endl;
		std::cout << b.getSize()[0] << " " << b.getSize()[1] << std::endl;
		std::cout << resaultMatrix.getSize()[0] << " " << resaultMatrix.getSize()[1] << std::endl;

		for (int i = 0; i < a.getSize()[0]; i++)
		{
			for (int j = 0; j < a.getSize()[1]; j++)
			{
				resaultMatrix._matrix[i][j] = a._matrix[i][j] - b._matrix[i][j];
			}
		}
		return resaultMatrix;
	}
	void nonlin(bool derivative);
	~Matrix();

	std::vector<std::vector<float>> _matrix;
};

