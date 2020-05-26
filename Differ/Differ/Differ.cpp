#include<iostream>
#include<vector>

using namespace std;

struct Point
{
public:
	double x;
	double y;
	Point(double _x = 0, double _y = 0)
	{
		x = _x;
		y = _y;
	}
};

double Ln1(double x, vector<Point>& point)
{
	long double y = 0,
		mul1 = 1,
		mul2 = 1,
		sum = 0;

	unsigned n = point.size();

	for (unsigned k = 0; k < n; k++)
	{
		mul1 = 1;
		for (unsigned j = 0; j < n; j++)
		{
			if (k == j) continue;
			mul1 *= (point[k].x - point[j].x);
		}

		sum = 0;
		for (unsigned m = 0; m < n; m++)
		{
			if (k == m) continue;

			mul2 = 1;
			for (unsigned i = 0; i < n; i++)
			{
				if (i == m || i == k) continue;
				mul2 *= (x - point[i].x);
			}
			sum += mul2;
		}

		y += (point[k].y * (sum / mul1));
	}

	return y;
}

int main()
{
	vector<Point> Points =
	{
		Point(0.03, 3.07039),
		Point(0.05, 3.22639),
		Point(0.07, 3.40512),
		Point(0.09, 3.60989),
		Point(0.11, 3.84451),
		Point(0.13, 4.11333),
		Point(0.15, 4.42132),
		Point(0.17, 4.77419)
	};

	double x1 = 0.05,
		x2 = 0.1;

	cout << Ln1(x1, Points) << endl;
	cout << Ln1(x2, Points) << endl;

	system("pause");
	return 0;
}