#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

float f1(float x) {
	return 1 / sqrt(pow(x, 2) + 9);
}

float f2(float x) {
	return cos(3 * pow(x, 2)) / (pow(x, 2) + 3);
}

// вторая производная функции f1
float f1_xx(float x) {
	return (2 * pow(x, 2) - 9) / pow((pow(x, 2) + 9), 5 / 2);
}

// функция вернула 8.935..., следовательно за max можно взять значение 9
float max_f1_xx(float a, float b, float eps) {
	float k = ceil((b - a) / eps);
	float d = (b - a) / k;
	vector<float> vec;
	for (int i = 0; i < k + 1; i++)
	{
		vec.push_back(f1_xx(a + i * d));
	}
	return *max_element(vec.begin(), vec.end());
}

float trapezoid_method(float a, float b, float eps, float max) {
	int n = sqrt(max * pow(b - a, 3) / (12 * eps));
	float h = (b - a) / n;
	float w = 0;
	float x;
	for (int k = 1; k <= n - 1; k++)
	{
		x = a + k * h;
		w += f1(x);
	}
	w = (2 * w + f1(a) + f1(b)) * h / 2;
	return w;
}

float simps_method(float a, float b, float m) {
	float n = 2 * m;
	float h = (b - a) / n;
	float s = 0;
	float s1 = 0;
	float s2 = 0;
	float x;
	for (int k = 1; k <= m; k++)
	{
		x = a + (2 * k - 1) * h;
		s1 += f2(x);
	}
	for (int k = 1; k <= m - 1; k++)
	{
		x = a + 2 * k * h;
		s2 += f2(x);
	}
	s = (4 * s1 + 2 * s2 + f2(a) + f2(b)) * h / 3;
	return s;
}

int main()
{
	setlocale(0, "");
	float a = 0.3;
	float b = 1.3;
	const float eps = 0.001;
	float max =9;
	cout << trapezoid_method(a, b, eps, max) << endl;
	float a1 = 1.6;
	float b1 = 2.4;
	float m = 8;
	float I1 = simps_method(a1, b1, m);
	m++;
	float I2 = simps_method(a1, b1, m);
	// оценка погрешности
	while (fabs(I1 - I2) > eps) {
		I1 = I2;
		m++;
		I2 = simps_method(a1, b1, m);
	}
	cout << I2 << endl;

	system("pause");
	return 0;
}