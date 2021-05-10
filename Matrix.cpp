#include "Matrix.h"

Matrix::Matrix()
{
	N = 1;

	m = new Row[N];
	m[0] = Row(N);
}
Matrix::Matrix(int N = 1)
{
	this->N = N < 1 ? 1 : N;

	m = new Row[this->N];
	for (int i = 0; i < this->N; i++) { m[i] = Row(this->N); }
}
Matrix::Matrix(int N, Row* A)
{
	this->N = N;
	m = A;
}

int Matrix::GetN() const { return N; }

Row& Matrix::operator[] (int i) { return m[i]; }
Matrix& Matrix::operator = (const Matrix& A)
{
	N = A.N;
	m = A.m;
	return *this;
}
Matrix::operator string() const
{
	stringstream ss;
	for (int i = 0; i < this->GetN(); i++)
	{
		for (int j = 0; j < this->GetN(); j++)
		{
			ss << m[i].v[j] << "  ";
		}
		ss << endl;
	}
	return ss.str();
}
ostream& operator << (ostream& out, const Matrix& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Matrix& A)
{
	for (int i = 0; i < A.GetN(); i++)
	{
		cout << "Enter a row of " << A.GetN() << " elements" << endl;
		for (int j = 0; j < A.GetN(); j++)
		{
			in >> A.m[i].v[j];
		}
		cout << endl;
	}
	return in;
}

void operator - (Matrix& A, Matrix& B)
{
	Matrix Result(A.GetN());

	for (int i = 0; i < A.GetN(); i++)
		for (int j = 0; j < B.GetN(); j++)
			Result[i][j] = A[i][j] - B[i][j];
	cout << Result;
}
bool operator == (Matrix& A, Matrix& B)
{
	int Counter = 0;

	for (int i = 0; i < A.GetN(); i++)
		for (int j = 0; j < A.GetN(); j++)
			if (A[i][j] == B[i][j])
				Counter++;
	return Counter == A.GetN() * A.GetN() ? true : false;
}

double Matrix::MatrixNorm()
{
	double SumToSquare = 0;

	for (int i = 0; i < this->GetN(); i++)
		for (int j = 0; j < this->GetN(); j++)
			SumToSquare += this->m[i][j] * this->m[i][j];

	return sqrt(SumToSquare);
}
void Matrix::ComparisonMatrix(Matrix& A, Matrix& B)
{
	if (A == B) cout << "Matrices are equal" << endl;
	else cout << "Matrices are not equal" << endl;
}

Matrix::~Matrix()
{
	for (int i = 0; i < N; i++)
		if (m[i].v != nullptr)
			delete[](m[i].v);

	if (m != nullptr)
		delete[] m;
}
