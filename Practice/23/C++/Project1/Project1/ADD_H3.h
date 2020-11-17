#ifndef ADD_H3
#define ADD_H3

int C(int k, int n = 10) 
{
	return F(n) / (F(k) * F(n - k));
}

#endif ADD_H3