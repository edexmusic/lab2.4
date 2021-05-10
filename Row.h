#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Row
{
public:
	double* v;

	Row();
	Row(int);
	double& operator [] (int);
};