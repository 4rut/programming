#ifndef ADD_H2
#define ADD_H2

double teylor(double x, int k) {
	double sum = 0;
	int minus = -1;

	for (int i = 0; i < k; i++) 
	{
		minus *= -1;
		sum += minus * pow(x, 2 * i + 1) / F(2 * i + 1);
	}

	return sum;
}

#endif ADD_H2