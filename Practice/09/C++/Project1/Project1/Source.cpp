#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	std::pair<int, int> firstPers;
	std::pair<int, int> secondPers;
	char sym;

	std::cin >> firstPers.first >> sym >> firstPers.second;
	std::cin >> secondPers.first >> sym >> secondPers.second;

	if (firstPers.first < 0 || firstPers.first > 23)
		return 1;
	
	if (secondPers.first < 0 || secondPers.first > 23)
		return 1;
	
	if (firstPers.second < 0 || firstPers.second > 59)
		return 1;
	
	if (secondPers.second < 0 || secondPers.second > 59)
		return 1;
	
	if (firstPers.first == secondPers.first)
	{
		if (firstPers.second < secondPers.second && firstPers.second + 15 >= secondPers.second ||
			secondPers.second < firstPers.second && secondPers.second + 15 >= firstPers.second)
			std::cout << "Встреча состоится\n";
		else
			std::cout << "Встреча не состоится\n";
	}
	else if (firstPers.first > secondPers.first)
	{
		if (60 - firstPers.second + secondPers.second <= 15)
			std::cout << "Встреча состоится\n";
		else
			std::cout << "Встреча не состоится\n";
	}
	else if (firstPers.first < secondPers.first)
	{
		if (60 - secondPers.second + firstPers.second <= 15)
			std::cout << "Встреча состоится\n";
		else
			std::cout << "Встреча не состоится\n";
	}
	else
		std::cout << "Встреча не состоится\n";

	return 0;
}