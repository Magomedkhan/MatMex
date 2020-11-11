#include <iostream>
#include "ArrayList.h"
#include <cstdlib>

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в список 10 случайных положительных двузначных чисел" << endl;
	cout << "2 - Добавить в список 10 случайных отрицательных чисел" << endl;
	cout << "3 - Поменять местами первый минимальный и последний максимальный элемент" << endl;
	cout << "4 - Перемешать все элементы массива" << endl;
	cout << "5 - Заменить каждый отрицательный элемент массива на 0" << endl;
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 0:
	{
		exit(0);
	}
	case 1:
	{
		int min = 10;
		int max = 99;
		for (int i = 0; i < 10; ++i)
		{
			a.add(rand() % (max - min + 1) + min);
		}
		cout << a.toString() << endl;
		break;
	}
	case 2:
	{
		int min = -99;
		int max = -10;
		for (int i = 0; i < 10; ++i)
		{
			a.add(rand() % (max - min + 1) + min);
		}
		cout << a.toString() << endl;
		break;
	}
	case 3:
	{
		int min = a.get(0);
		int minIndex = 0;
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) < min)
			{
				min = a.get(i);
				minIndex = i;
			}

		}
		int max = a.get(0);
		int maxIndex = 0;
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) >= max)
			{
				max = a.get(i);
				maxIndex = i;
			}

		}
		a.swap(minIndex, maxIndex);
		cout << a.toString() << endl;
		break;
	}
	case 4:
	{
		bool metka[a.length()] = { 0 };
		for (int i = 0; i < a.length(); ++i)
		{
			int num = rand() % (a.length() - i + 1) + i;
			if (metka[num])
			{
				a.swap(i, num);
				metka[num] = true;
			}
			else
			{
				--i;
			}
		}
		cout << a.toString() << endl;
		break;
	}
	case 5:
	{
		for (int i = 0; i < a.length(); ++i)
		{
			if (a.get(i) < 0)
			{
				a.set(i, 0);
			}
		}
		cout << a.toString() << endl;
	}
	}

}

int main()
{
	ArrayList a;
	int choice = 0;

	do
	{
		printMenu();
		cin >> choice;
		processChoice(a, choice);

	} while (choice != 0);

	return EXIT_SUCCESS;
}