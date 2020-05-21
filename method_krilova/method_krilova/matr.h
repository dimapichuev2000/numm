#pragma once

/**
	����� �� ������� �� �������
**/
int searchNotZeroCol(float** Arr, unsigned ColCheck, unsigned Row);

/**
	������������� ������� � �������� ���. �����
**/
void initArrWithLineNumUsed(int Len);

/**
	�������� �� ��������� ������������� ������
	������ ������ ������, ��� ���������� � ���������� �������������
**/
bool notReturnRow(unsigned ColCheck);


/**
	������� ������, � ���� �� �� ���� ��
**/
float* splitLine(float* Row, unsigned Col);

/**
	���������� ���� ������ �� �� ������ �����,
	(����� ����� � ����) � ��������� �� ��� ���� ������
**/
float** zeroingLineItem(float** Arr, unsigned Row, unsigned Col, unsigned numString, unsigned numColumn);

/**
	��������� ����� ������ �� ������
**/
float* subLine(float* Minuend, float* Subtrahend, unsigned Col, unsigned numColumn);

/**
	����������� ����� �������
**/
float** recCallToFunc(float** Arr, unsigned Row, unsigned Col, unsigned numIteration);

/**
	�������������� ������� �� ������ �������-�����
**/
float** matrixJardanGaus(float** Arr, unsigned Row, unsigned Col);

/**
	����� ����������
**/
void outResult(float** Arr, unsigned Row, unsigned Col);

