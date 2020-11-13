#include <iostream>
#include <iomanip>

#include "ADD_H1.h"
#include "ADD_H2.h"
#include "ADD_H3.h"

int main() 
{
	std::cout << 'n' << '\t' << "!n\n";
	for (int i = 1; i <= 10; i++)
		std::cout << i << '\t' << F(i) << '\n';


	return 0;
}