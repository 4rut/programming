#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "*Приветственное сообщение от игры*\n";

A:
	std::srand(time(0));

	int n = rand() * 100 / RAND_MAX;

	int guessing;
	bool showResult = true;
	int crutch = -4;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> guessing;

		if (guessing < n && crutch)
			std::cout << "Загаданное число больше\n";
		if (guessing > n && crutch)
			std::cout << "Загаданное число меньше\n";
		if (guessing == n && crutch)
		{
			std::cout << "Поздравляю! Вы угадали\n";
			showResult = false;
			break;
		}

		crutch++;
	}

	if (showResult)
		std::cout << "Вы проиграли.Было загадано : " << n << '\n';

	int choise = 0;
	std::cout << "Хотите начать сначала? (1 - ДА )";
	std::cin >> choise;

	if (choise == 1)
		goto A;

	return 0;
}