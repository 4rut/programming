﻿#include <iostream>

int main()
{
	int a1(3), b1(3.14);
	double a2(3), b2(3.14);

	std::cout << a1 << '\t' << b1 << '\n';
	std::cout << a2 << '\t' << b2 << '\n';
	
	// Т к int явл целочисленным типом и при нестрогом присваивании
	// берется только целая часть от числа
	
	return 0;
}