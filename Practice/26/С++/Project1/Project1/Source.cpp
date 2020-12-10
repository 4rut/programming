#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

template <typename T>
std::vector<T> bozoSort(std::vector<T> arr, bool bl = 1)
{
	bool checker = 1;
	while (checker)
	{
		int rand1 = rand() * arr.size() / RAND_MAX;
		int rand2 = rand() * arr.size() / RAND_MAX;

		T tmp = arr[rand1];
		arr[rand1] = arr[rand2];
		arr[rand2] = tmp;

		if (bl)
		{
			bool tmpBool = 1;
			for (auto i = arr.begin(); i != arr.end() - 1; i++)
				if (*i > * (i + 1))
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
				if (*i < *(i + 1))
				{
					tmpBool = 0;
					break;
				}
			checker = !tmpBool;
		}
	}

	return arr;
}

template <typename T>
std::vector <std::vector<T>> bozoSort(std::vector<std::vector<T>> arr, bool bl = 1)
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

		T tmp = arr[rand_1_2][rand_1_1];
		arr[rand_1_2][rand_1_1] = arr[rand_2_2][rand_2_1];
		arr[rand_2_2][rand_2_1] = tmp;

		if (bl)
		{
			bool tmpBool = 1;
			T previousNumber = arr[0][0];
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
			T previousNumber = arr[0][0];
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

template <typename T> 
std::vector<T> bozoSort(T a, T b, T c, bool bl = 1)
{
	std::vector<T> arr;

	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);

	return bozoSort(arr, bl);
}

template <typename T>
void printVector(std::vector<T> vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << ' ';

	std::cout << '\n';
}

template <typename T>
void printVector(std::vector<std::vector<T>> vec)
{
	for (auto i = 0; i < vec.size(); i++)
		for (auto j = 0; j < vec[i].size(); j++)
			std::cout << vec[i][j] << ' ';
	std::cout << '\n';
}


int main()
{
	srand(time(NULL));

	int n;
	std::cin >> n;

	std::vector<double> arr(n);


	auto arr1 = bozoSort<double>(arr);


	return 0;
}