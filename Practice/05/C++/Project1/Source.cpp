#include <iostream>

int main() 
{
	int x0, t, v0;
	const double g = 9.8;

	std::cin >> x0 >> v0 >> t;

	std::cout << x0 + v0 * t - (g * t * t) / 2;

	system("pause");
	return 0;
}