#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	
	double a, b, c;
	std::cin >> a >> b >> c;

	if (a == 0)
	{
		std::cout << "x = " << -c / b << '\n';
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (D < 0) {
			std::cout << "Корней нет\n";
		}
		else if (D == 0)
		{
			std::cout << "x = " << -b / (2 * a) << '\n';
		}
		else
		{
			std::cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << '\n';
			std::cout << "x2 = " << (-b - sqrt(D)) / (2 * a) << '\n';
		}

	}

	system("pause");
	return 0;
}