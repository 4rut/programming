#include <iostream>
#include <string>
#include <vector>

int main() 
{
	int n;
	std::cin >> n;
	bool isExisted = 0;
	std::string* arr = new std::string[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	std::vector<std::string> vec;

	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] == 'a' && arr[i][8] == '1' && arr[i][7] == '6' && arr[i][6] == '6' && arr[i][5] == '5' && arr[i][4] == '5')
		{
			vec.push_back(arr[i]);
			isExisted = 1;
		}
	}

	if (isExisted)
		for (auto i = vec.begin(); i < vec.end(); i++)
			std::cout << *i << ' ';
	else
		std::cout << "-1\n";

	delete[] arr;
	return 0;
}