#include <iostream>

int F(int a) {
	if (a > 1)
		return F(a - 1) * a;
	else
		return 1;
}

int main() 
{
	int var;
	std::cin >> var;

	std::cout << F(var) << '\n';

	system("pause");
	return 0;
}