#include "Matrix.h"

void  Matrix::f(int _i, int _j)
{
	for (int i = _i; i < size; i++){
		float t = arr[i][_j] / arr[_j][_j];
		for (int j = _j; j < size; j++){
			float cof = arr[_j][j] * (-t);
			arr[i][j] += cof;
		}
	}
}

float Matrix::det(){
	for (int i = 1; i < size; i++)
		f(i, i - 1);
	float res = 1;
	for (size_t i = 0; i < size; i++)
		res *= arr[i][i];
	return res;
}
