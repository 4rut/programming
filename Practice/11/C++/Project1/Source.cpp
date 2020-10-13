#include <iostream>

int64_t myPow(int a, int b) 
{
	int var = 1;
	int i = 0;
	
	while (i++ < b)
		var *= a;

	return var;
}

int main() 
{
	int num, pow;
	std::cin >> num >> pow;

	std::cout << myPow(num, pow) << '\n';

	system("pause");
	return 0;
}