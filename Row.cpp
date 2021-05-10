#include "Row.h"

Row::Row()
{
	v = new double[1];
	v[0] = 0;
}
Row::Row(int N = 1)
{
	v = new double[N];

	for (int j = 0; j < N; j++)
		v[j] = 0;
}
double& Row::operator[] (int j) { return v[j]; }