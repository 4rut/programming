#include <iostream>

int main() 
{
	setlocale(LC_ALL, "rus");

	double a, b;
	char sym;
	
	std::cin >> a >> sym >> b;

	if (sym == '/' && b == 0) 
	{
		std::cout << "На 0 делить нельзя!\n";
		return 0;
	}

	switch (sym)
	{
	case '+':
		std::cout << a + b;
		break;
	case '-':
		std::cout << a - b;
		break;
	case '*':
		std::cout << a * b;
		break;
	case '/':
		std::cout << a / b;
		break;

	default:
		break;
	}

	return 0;
}