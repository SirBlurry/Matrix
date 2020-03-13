#ifndef Matrix_h
#define Matrix_h
#include<iostream>
#include<vector>

using std::vector;

template<typename T> class Matrix
{
private:
	vector<vector<T>> mat;
	unsigned rows;
	unsigned cols;
	unsigned i;
	unsigned j;
	unsigned k;
public:
	Matrix(unsigned row, unsigned col);
	Matrix(unsigned row, unsigned col, const T& initial);
	Matrix(const Matrix& other);
	virtual ~Matrix();

	Matrix<T>& operator=(const Matrix& other);

	Matrix<T> operator+(const Matrix& other);
	Matrix<T>& operator+=(const Matrix& other);
	Matrix<T> operator-(const Matrix& other);
	Matrix<T>& operator -= (const Matrix& other);
	Matrix<T> operator*(const Matrix& other);
	Matrix<T>& operator*=(const Matrix& other);

	Matrix<T> Transpose();

	Matrix<T> operator+(const T& other);
	Matrix<T> operator-(const T& other);
	Matrix<T> operator*(const T& other);
	Matrix<T> operator/(const T& other);

	vector<T> operator*(const vector<T>& other);
	vector<T> DiagVec();

	T& operator()(const unsigned& row, const unsigned& col);
	const T& operator()(const unsigned& row, const unsigned& col)const;

	unsigned GetRows()const;
	unsigned GetCols()const;
	void Print();
};

#include"matrix.cpp"
#endif