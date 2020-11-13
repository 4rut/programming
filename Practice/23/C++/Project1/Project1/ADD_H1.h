#pragma once

int F(int a) {
	if (a > 1)
		return F(a - 1) * a;
	else
		return 1;
}