#include<iostream>
#include<cmath>
#include<vector>
#include"matr.h"

using namespace std;

vector<vector<float>> mul(vector<vector<float>>& A, vector<vector<float>>& B)
{
	int row = A.size();
	int col = B[0].size();
	vector<vector<float>> temp;

	temp.resize(row);
	for (int i = 0; i < row; i++)
	{
		temp[i].resize(col);
		for (int j = 0; j < col; j++)
			temp[i][j] = 0;
	}

	for (unsigned i = 0; i < row; i++)
		for (unsigned j = 0; j < col; j++)
			for (unsigned k = 0; k < row; k++)
				temp[i][j] += A[i][k] * B[k][j];
	return temp;
}

int main()
{
	
	vector<vector<float>> A = {
	
		{2, 0, 2, 2, 5},
		{-1, 2, -1, -3, 0},
		{-2, -4, 0, 4, 5},
		{-3, -4, -1, -1, 0},
		{-3, 3, -2, -1, -5}
	};

	unsigned n = A.size();

	vector<vector<vector<float>>> Y;
	Y.resize(n + 1);
	for (unsigned i = 0; i < n + 1; i++)
	{
		Y[i].resize(n);
		for (unsigned j = 0; j < n; j++)
		{
			Y[i][j].resize(1);
		}
	}

	for (unsigned i = 0; i < n; i++)
	{
		Y[0][i][0] = (-10 + rand() % 20);
	}

	
	float** SLAU = new float* [n];
	for (unsigned i = 0; i < n; i++)
	{
		SLAU[i] = new float[n + 1];
	}



	for (unsigned i = 1; i < n + 1; i++)
	{
		Y[i] = mul(A, Y[i - 1]);
	}


	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			SLAU[i][j] = Y[n - (j + 1)][i][0];
		}
		SLAU[i][n] = Y[n][i][0];
	}
	
	SLAU = matrixJardanGaus(SLAU, n, n + 1);
	outResult(SLAU, n, n + 1);

	
	system("pause");
	return 0;
}