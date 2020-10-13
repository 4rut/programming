#include <iostream>

int pow(int a)
{
	if (a == 0)
		return 0;

	int var = 2;
	int counter = 1;
	
	while (var < a)
	{
		var *= 2;
		counter++;
	}
	return counter;
}

int main() 
{
	int num;
	std::cin >> num;

	std::cout << pow(num) << '\n';

	system("pause");
	return 0;
}