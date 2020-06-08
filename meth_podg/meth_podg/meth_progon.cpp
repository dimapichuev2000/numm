#include<iostream>
#include<vector>
#include<cmath>
#include<random>
using namespace std;

float* generateMatr(int n)
{
	float* array = new float[n];
	for (int i = 0; i < n; i++) {
		array[i] = 5 + (int)(rand()*10);
	}
	return array;
}
float* generateZero(int n)
{
	float* array = new float[n];
	for (int i = 0; i < n; i++) {
		array[i] = 0;
	}
	return array;
}
void write(float *array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << "   ";	
	}
	cout << endl;
}
const int n = 5;




int main()
{
	setlocale(0, "");
	float* a = generateMatr(n - 1); // Число уравнений
	float* b = generateMatr(n - 1);
	float* c = generateMatr(n);
	float* f = generateMatr(n);// Столбец
	float* alp = generateMatr(n - 1);
	float* bet = generateMatr(n);
	float* gam = generateMatr(n);
	float* x = generateMatr(n);// Ответ

	gam[0] = c[0];
	alp[0] = -b[0] / gam[0];
	bet[0] = f[0] / gam[0];
	cout << "b" << endl;
	write(b, n - 1);
	cout << "c" << endl;
	write(c, n);
	cout << "a" << endl;
	write(a, n - 1);
	cout << "f" << endl;
	write(f, n - 1);
	

	for (int i = 1; i < n - 1; i++) {
		gam[i] = c[i] + a[i - 1] * alp[i - 1];
		alp[i] = -b[i] / gam[i];
		bet[i] = (f[i] - a[i - 1] * bet[i - 1]) / gam[i];
	}
	cout << "Альфа"<< endl;
	write(alp, n-1);
	gam[n - 1] = c[n - 1] + (a[n - 2] * alp[n - 2]);
	bet[n - 1] = (f[n - 1] - (a[n - 2] * bet[n - 2])) / gam[n - 1];
	cout << "Бета" << endl;
	write(alp, n);
	cout << "Гамма" << endl;
	write(alp, n);

	//Обратная подгонка
	x[n - 1] = bet[n - 1];
	for (int i = n - 2; i > -1; i--) {
		x[i] = (alp[i] * x[i + 1]) + bet[i];
	}
	cout << "x" << endl;
	write(x, n);


	system("pause");
	return 0;
}