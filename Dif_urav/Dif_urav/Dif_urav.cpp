#include<iostream>
#include<vector>
#include<cmath>

float fun(float x, float y)
{
	return ((4 * x * x) - 2) * cos(y);
}


float Eyler(float yk, float xk, float h)
{
	return yk + h * fun(xk, yk);
}

float EylerModif(float yk, float xk, float h)
{
	return yk + h * fun(xk + (h / 2), yk + ((h / 2) * fun(xk, yk)));
}

float RungeCutt(float yk, float xk, float h)
{
	float a = h * fun(xk, yk),
		b = h * fun(xk + (h / 2), yk + (a / 2)),
		c = h * fun(xk + (h / 2), yk + (b / 2)),
		d = h * fun(xk + h, yk + c);

	return yk + (a + (2 * b) + (2 * c) + d) / 6.;
}

float Adams1(float yk, float xk, float yk_1, float xk_1, float h)
{
	return yk + ((h / 2) * (3 * fun(xk, yk)- fun(xk_1, yk_1)));
}

float Adams2(float yk, float xk, float yk_1, float xk_1, float yk_2, float xk_2,
	float h)
{
	return yk + (h / 12) * (23 * fun(xk, yk)- 16 * fun(xk_1, yk_1)+ 5 * fun(xk_2, yk_2));
}

float Adams3(float yk, float xk, float yk_1, float xk_1, float yk_2, float xk_2,
	float yk_3, float xk_3, float h)
{
	return yk + (h / 24) * (55 * fun(xk, yk)- 59 * fun(xk_1, yk_1)+ 37 * fun(xk_2, yk_2)- 9 * fun(xk_3, yk_3));
}

void Out(std::vector<float> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << "    ";
	}
	std::cout << std::endl;
}



int main()
{
	setlocale(0, "");

	float h = 0.1,
		y0 = 1,
		e = 0.001,
		x = 0;


	
	std::cout << "Метод Эйлера " << "\n";

	std::vector<float> y;
	y.push_back(y0);
	while (x < 1)
	{
		y.push_back(Eyler(y[y.size() - 1], x, h));
		x += h;
	}
	Out(y);
	std::cout << std::endl;

	
	std::cout << "модифицированный метод Эйлера " << "\n";

	x = 0;
	for (int i = 1; i < y.size(); i++)
	{
		y[i] = EylerModif(y[i - 1], x, h);
		x += h;
	}
	Out(y);
	std::cout << std::endl;


	
	std::cout << "метод Рунге-Кутты" << "\n";

	x = 0;
	for (int i = 1; i < y.size(); i++)
	{
		y[i] = RungeCutt(y[i - 1], x, h);
		x += h;
	}
	Out(y);
	std::cout << std::endl;





	std::cout << " метод Адамса порядка m = 3" << "\n";

	x = 0;
	y[1] = RungeCutt(y[0], x, h);
	x += h;
	y[2] = RungeCutt(y[1], x, h);
	x += h;
	y[3] = RungeCutt(y[2], x, h);
	for (int i = 4; i < y.size(); i++)
	{
		x += h;
		y[i] = Adams3(y[i - 1], x, y[i - 2], x - h, y[i - 3], x - (2 * h), y[i - 4], x - (3 * h), h);
	}
	Out(y);
	std::cout << std::endl;

	


	
	std::cout << " метод Адамса порядка m = 2 " << "\n";

	x = 0;
	y[1] = RungeCutt(y[0], x, h);
	x += h;
	y[2] = RungeCutt(y[1], x, h);
	for (int i = 3; i < y.size(); i++)
	{
		x += h;
		y[i] = Adams2(y[i - 1], x, y[i - 2], x - h,y[i - 3], x - (2 * h),h);
	}
	Out(y);
	std::cout << std::endl;
	



	std::cout << " метод Адамса порядка m = 1 " << "\n";

	x = 0;
	y[1] = RungeCutt(y[0], x, h);
	for (int i = 2; i < y.size(); i++)
	{
		x += h;
		y[i] = Adams1(y[i - 1], x, y[i - 2], x - h, h);
	}
	Out(y);
	std::cout << std::endl;



	system("pause");
	return 0;
}