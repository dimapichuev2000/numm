#include <iostream>
#include <math.h>

using namespace std;
float f(float x, float y, float z)
{
	return (x * x) - (2 * x) + (y * y) - (8 * y) + (z * z) + (6 * z) + 26;

}

int main()
{
	setlocale(0, "");

	float e = 0.0001,
		h, m, d,
		a1, a2, a3,
		b1, b2, b3,
        min, x, y, z, temp,
		xmin = 0, ymin = 0, zmin = 0;

	a1 = a2 = a3 = -5;
	b1 = b2 = b3 = 5;

	min = f(a1, a2, a3);

	d = b1 - a1;
	m = 5;
	h = d / m;

	while (h > e)
	{
		for (int i = 0; i <= m; i++)
		{
			x = a1 + (i * h);
			for (int j = 0; j <= m; j++)
			{
				y = a2 + (j * h);
				for (int k = 0; k <= m; k++)
				{
					z = a3 + (k * h);

					temp = f(x, y, z);
					if (temp < min)
					{
						min = temp;
						xmin = x;
						ymin = y;
						zmin = z;
					}
				}
			}
		}
		a1 = xmin - h;
		b1 = xmin + h;

		a2 = ymin - h;
		b2 = ymin + h;

		a3 = zmin - h;
		b3 = zmin + h;

		d = b1 - a1;
		h = d / m;
	}

	cout << "Приближённое значение точки минимума" << endl;
	b1 = b1 - h;
	b2 = b2 - h;
	b3 = b3 - h;

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;

	system("pause");
	return 0;
	
}



