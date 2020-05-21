#include<iostream>
#include<cstdlib>
#include"matr.h"

using namespace std;

int* ArrWithLineNumUsed;
int LenAWLNU = 0;


bool notReturnRow(unsigned ColCheck)
{
	for (int i = 0; i < LenAWLNU; i++)
		if (ColCheck == ArrWithLineNumUsed[i]) return 0;

	for (int i = 0; i < LenAWLNU; i++)
		if (ArrWithLineNumUsed[i] == -1)
		{
			ArrWithLineNumUsed[i] = ColCheck;
			break;
		}
	return 1;
}



int searchNotZeroCol(float** Arr, unsigned ColCheck, unsigned Row)
{
	for (int i = 0; i < Row; i++)

		if (Arr[i][ColCheck] != 0 && notReturnRow(i))

			return i;
}



float* splitLine(float* Row, unsigned Col)
{
	float divider = 0;

	for (int i = 0; i < Col - 1; i++)
		if (Row[i] != 0)
		{
			divider = Row[i];

			for (int j = i; j < Col; j++)
				Row[j] /= divider;

			break;
		}
	return Row;
}



float** zeroingLineItem(float** Arr, unsigned Row, unsigned Col, unsigned numString, unsigned numColumn)
{
	for (int i = 0; i < Row; i++)
		if (i != numString)
			Arr[i] = subLine(Arr[i], Arr[numString], Col, numColumn);

	return Arr;
}



float* subLine(float* Minuend, float* Subtrahend, unsigned Col, unsigned numColumn)
{
	float multi = Minuend[numColumn];

	for (int i = 0; i < Col; i++)
	{
		Minuend[i] -= Subtrahend[i] * multi;
	}

	return Minuend;
}



void initArrWithLineNumUsed(int Len)
{
	ArrWithLineNumUsed = new int(Len);
	for (int i = 0; i < Len; i++)
	{
		ArrWithLineNumUsed[i] = -1;
	}
}


float** recCallToFunc(float** Arr, unsigned Row, unsigned Col, unsigned numIteration)
{
	
	int StringUse = searchNotZeroCol(Arr, numIteration, Row);
	Arr[StringUse] = splitLine(Arr[StringUse], Col);

	
	Arr = zeroingLineItem(Arr, Row, Col, StringUse, numIteration);

	Arr = (numIteration != Col - 2) ? recCallToFunc(Arr, Row, Col, numIteration + 1) : Arr;

	return Arr;
}


float** matrixJardanGaus(float** Arr, unsigned Row, unsigned Col)
{
	
	LenAWLNU = Row;
	initArrWithLineNumUsed(LenAWLNU);

	
	Arr = recCallToFunc(Arr, Row, Col, 0);

	return Arr;
}





void outResult(float** Arr, unsigned Row, unsigned Col)
{
	cout << endl;

	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			if (Arr[i][j] == 1)
			{
				cout << "p" << j + 1 << " = ";
				cout.width(10);
				cout << Arr[i][Col - 1] << endl;
				break;
			}
}