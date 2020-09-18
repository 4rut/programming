#include <iostream>

int main() 
{
	double a_double, b_double;
	std::cin >> a_double >> b_double;
	
	int a_int(a_double), b_int(b_double);

	// int int
	std::cout << "int & int: \n";
	std::cout << a_int + b_int << '\n';
	std::cout << a_int - b_int << '\n';
	std::cout << a_int * b_int << '\n';
	std::cout << a_int / b_int << '\n';

	// int double
	std::cout << "int & double: \n";
	std::cout << a_int + b_double << '\n';
	std::cout << a_int - b_double << '\n';
	std::cout << a_int * b_double << '\n';
	std::cout << a_int / b_double << '\n';
	
	// double int
	std::cout << "double & int: \n";
	std::cout << a_double + b_int << '\n';
	std::cout << a_double - b_int << '\n';
	std::cout << a_double * b_int << '\n';
	std::cout << a_double / b_int << '\n';

	// double double
	std::cout << "double & double: \n";
	std::cout << a_double + b_double << '\n';
	std::cout << a_double - b_double << '\n';
	std::cout << a_double * b_double << '\n';
	std::cout << a_double / b_double << '\n';

	system("pause");
	return 0;
}