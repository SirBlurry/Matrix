#ifndef Matrix_cpp
#define Matrix_cpp

#include"Matrix.h"

template<typename T>
Matrix<T>::Matrix(unsigned row, unsigned col, const T& initial)
{
	rows = row;
	cols = col;
	mat.resize(row);
	for (i = 0; i < mat.size(); i++)
	{
		mat[i].resize(col, initial);
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
	mat = other.mat;
	rows = other.GetRows();
	cols = other.GetCols();
}

template<typename T>
Matrix<T>::~Matrix() {}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	if (&other == this)
	{
		return *this;
	}
	unsigned newRows = other.GetRows();
	unsigned newCols = other.GetCols();

	mat.resize(newRows);
	for (i = 0; i < mat.size(); i++)
	{
		mat[i].resize(newCols);
	}
	for (i = 0; i < newRows; i++)
	{
		for (j = 0; j < newCols; j++)
		{
			mat[i][j] = other(i, j);
		}
	}
	rows = newRows;
	cols = newCols;

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other)
{
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[i][j] + other(i, j);
		}
	}
	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
{
	unsigned rows = other.GetRows();
	unsigned cols = other.GetCols();
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			this->mat[i][j] += other(i, j);
		}
	}
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other)
{
	unsigned rows = other.GetRows();
	unsigned cols = other.GetCols();
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[i][j] - other(i, j);
		}
	}
	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
{
	unsigned rows = other.GetRows();
	unsigned cols = other.GetCols();
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			this->mat[i][j] -= other(i, j);
		}
	}
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other)
{
	unsigned rows = other.GetRows();
	unsigned cols = other.GetCols();
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (i = 0; j < cols; j++)
		{
			for (k = 0; k < rows; k++)
			{
				result(i, j) += this->mat[i][k] * other(k, j);
			}
		}
	}
	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& other)
{
	Matrix result = (*this) * other;
	(*this) = result;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::Transpose()
{
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[j][i];
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& other)
{
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[i][j] + other;
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& other)
{
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[i][j] - other;
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& other)
{
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[i][j] * other;
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& other)
{
	Matrix result(rows, cols, 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result(i, j) = this->mat[i][j] / other;
		}
	}
	return result;
}

template<typename T>
vector<T> Matrix<T>::operator*(const vector<T>& other)
{
	vector<T>result(other.size(), 0.0);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			result[i] = this->mat[i][j] * other[j];
		}
	}
	return result;
}

template<typename T>
vector<T> Matrix<T>::DiagVec()
{
	vector<T>result(rows, 0.0);
	for (i = 0; i < rows; i++)
	{
		result[i] = this->mat[i][i];
	}
	return result;
}

template<typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col)
{
	return this->mat[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const
{
	return this->mat[row][col];
}

template<typename T>
unsigned Matrix<T>::GetRows() const
{
	return this->rows;
}

template<typename T>
unsigned Matrix<T>::GetCols() const
{
	return this->rows;
}

#endif