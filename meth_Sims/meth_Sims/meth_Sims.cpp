

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

float f(float x) {
	 return sin(x) / log(x);
}
float sims(float a, float b, int m) {
	int n = 3 * m;

	float h = (b - a) / n;

	vector<float>x;
	x.resize(n + 1);
	vector<float>y;
	y.resize(n + 1);

	for (int k = 0; k < n + 1; k++) {
		x[k] = a + h * k;
	}
	for (int k = 0; k < n + 1; k++) {
		y[k] = f(x[k]);
	}
	float s = y[0] + y[3 * m];
	for (int k = 1; k < m; k++) {
		s += 2 * y[3 * k];
	}
	for (int k = 1; k < m + 1; k++) {
		s += 3 * (y[3 * k - 1] + y[3 * k - 2]);
	}
	s = 3 * s * h / 8;
	return s;
}

int main()
{
	setlocale(0, "");
	int maxN = 30;
	float eps = 0.00001;
	float a = 4, b = 6;

	while ((sims(a, b, maxN)- sims(a, b, 2 * maxN)) > eps)
	{
		maxN *= 2;
	}

	cout << sims(a, b, maxN);
	system("pause");
	return 0;
}

