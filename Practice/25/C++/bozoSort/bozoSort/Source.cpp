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

	return arr;
}

int main() 
{
	srand(time(NULL));

	int n;
	std::cin >> n;
	
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	
	auto res = bozoSort(arr);
	for (int i = 0; i < n; i++)
		std::cout << res[i] << ' ';

	return 0;
}