#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> bozoSort(std::vector<int> arr, bool bl=1) 
{
	bool checker = 1;
	while (checker)
	{
		int rand1 = rand() * arr.size() / RAND_MAX;
		int rand2 = rand() * arr.size() / RAND_MAX;

		int tmp = arr[rand1];
		arr[rand1] = arr[rand2];
		arr[rand2] = tmp;

		if (bl)
		{
			bool tmpBool = 1;
			for (auto i = arr.begin(); i != arr.end() - 1; i++)
				if (*i >= *(i + 1))
				{
					tmpBool = 0;
					break;
				}
			checker = !tmpBool;
		}
		else
		{
			bool tmpBool = 1;
			for (auto i = arr.begin(); i != arr.end() - 1; i++)
				if (*i <= *(i + 1))
				{
					tmpBool = 0;
					break;
				}
			checker = !tmpBool;
		}
	}

	return arr;
}

std::vector <std::vector<int>> bozoSort(std::vector<std::vector<int>> arr, bool bl = 1)
{
	const int m = arr.size();
	const int n = arr[0].size();

	bool checker = 1;
	while (checker)
	{
		int rand_1_1 = rand() * n / RAND_MAX;
		int rand_1_2 = rand() * m / RAND_MAX;
		int rand_2_1 = rand() * n / RAND_MAX;
		int rand_2_2 = rand() * m / RAND_MAX;

		int tmp = arr[rand_1_1][rand_1_2];
		arr[rand_1_1][rand_1_2] = arr[rand_2_1][rand_2_2];
		arr[rand_2_1][rand_2_2] = tmp;

		if (bl)
		{
			bool tmpBool = 1;
			int previousNumber = arr[0][0];
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					if (previousNumber > arr[i][j])
					{
						tmpBool = 0;
					}
					previousNumber = arr[i][j];
				}
			checker = !tmpBool;
		}
		else
		{
			bool tmpBool = 1;
			int previousNumber = arr[0][0];
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					if (previousNumber < arr[i][j])
					{
						tmpBool = 0;
					}
					previousNumber = arr[i][j];
				}
			checker = !tmpBool;
		}
	}

	return arr;
}

int main() 
{
	srand(time(NULL));

	return 0;
}