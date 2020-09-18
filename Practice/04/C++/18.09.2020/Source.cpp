#include <iostream>

int main()
{
	// С помощью дополнительной переменной
	
	double a, b;
	std::cin >> a >> b;
	std::cout << a << ' ' << b << '\n';
	
	int t = a;
	a = b;
	b = t;
	
	std::cout << a << ' ' << b << '\n';

	// Без помощи дополнительной переменной
	
	a += b;
	b = a - b;
	a -= b;

	std::cout << a << ' ' << b << '\n';
	
	system("pause");
	return 0;
}