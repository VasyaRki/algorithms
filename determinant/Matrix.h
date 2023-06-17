#pragma once
#include <iostream>
class Matrix
{
public:
	Matrix(size_t size) : size(size)
	{
		arr = new float* [size];
		for (int i = 0; i < size; i++)
			arr[i] = new float[size];
		for (size_t i = 0; i < size; i++)
			for (size_t j = 0; j < size; j++)
				arr[i][j] = rand()%3+1;
	}
	float det();
	void f(int i, int j);
public:
	size_t size;
	float** arr;
};
