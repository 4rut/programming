#ifndef ADD_H2
#define ADD_H2

double teylor(int x, int k = 5) 
{
	double minus = -1;
	double sum = 0;
	double _x = x;

	for(int i = 0, j = 3; i < k; i++, j += 2)
	{
		_x *= x * x;
		sum += minus * (_x / F(j));
	}

	return sum;
}


#endif ADD_H2