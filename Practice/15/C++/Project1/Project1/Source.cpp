#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "*�������������� ��������� �� ����*\n";

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
			std::cout << "���������� ����� ������\n";
		if (guessing > n && crutch)
			std::cout << "���������� ����� ������\n";
		if (guessing == n && crutch)
		{
			std::cout << "����������! �� �������\n";
			showResult = false;
			break;
		}

		crutch++;
	}

	if (showResult)
		std::cout << "�� ���������.���� �������� : " << n << '\n';

	int choise = 0;
	std::cout << "������ ������ �������? (1 - �� )";
	std::cin >> choise;

	if (choise == 1)
		goto A;

	return 0;
}