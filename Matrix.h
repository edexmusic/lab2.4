#pragma once
#include "Row.h"

class Matrix
{
private:
	int N;
	Row* m;
public:
	Matrix();
	Matrix(int);
	Matrix(int N, Row*);

	int GetN() const;

	Row& operator[] (int);
	Matrix& operator = (const Matrix&);//
	friend ostream& operator << (ostream&, const Matrix&);//
	friend istream& operator >> (istream&, Matrix&);//
	operator string() const;//

	friend void operator - (Matrix&, Matrix&);
	friend bool operator == (Matrix&, Matrix&);

	double MatrixNorm();
	void ComparisonMatrix(Matrix&, Matrix&);



	~Matrix();
};

