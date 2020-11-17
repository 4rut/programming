#include <iostream>
#include <iomanip>

#include "ADD_H1.h"
#include "ADD_H2.h"
#include "ADD_H3.h"


int main() 
{
	// 1 
	std::cout << 'n' << '\t' << "!n\n";
	
	for (int i = 1; i <= 10; i++)
		std::cout << i << '\t' << F(i) << '\n';
	std::cout << '\n';

	// 2
	const double pi = 3.1415;

	std::cout << "x" << '\t' << "sin(x)\n";
	
	int k = 5;

	for (double x = 0; x <= pi / 4; x += pi / 180) {
		std::cout << x << "\t" << std::setprecision(4) << teylor(x, k) << "\n";
	}
	std::cout << '\n';

	// 3

	std::cout << 'k' << '\t' << "C(k, 10)\n";

	for (int i = 1; i <= 10; i++)
		std::cout << i << '\t' << C(i, 10) << '\n';

	return 0;
}