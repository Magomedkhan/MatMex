#include <iostream>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Вывести массив" << endl;
	cout << "3 - Проверить, является ли массив симметричным" << endl;
	cout << "4 - Циклический сдвиг массива на n элементов. n>0 - сдвиг вправо, n<0 - сдвиг влево" << endl;
	cout << "5 - Проверить, может ли массив стать симметричным, если из него удалить один элемент" << endl;
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
		int element = 0;
		cin >> element;
		a.add(element);
		break;
	}
	case 2:
	{
		cout << a.toString() << endl;
		break;
	}
	case 3:
	{
		bool isTrue = true;
		for (int i = 0; i < a.length() / 2; ++i)
		{
			if (a.get(i) != a.get(a.length() - 1 - i))
			{
				isTrue = false;
			}
		}
		if (isTrue == true)
		{
			cout << "Да, является" << endl;
		}
		else
		{
			cout << "Нет, не является" << endl;
		}
		break;
	}
	case 4:
	{
		int n = 0;
		cin >> n;
		if (n < 0)
		{
			for (int i = 0; i < -n % a.length(); ++i)
			{
				int buff = 0;
				buff = a.get(0);
				for (int j = 0; j < a.length() - 1; ++j)
				{
					a.set(j, a.get(j + 1));
				}
				a.set(a.length() - 1, buff);
			}
		}
		if (n > 0)
		{
			for (int i = 0; i < n % a.length(); ++i)
			{
				int buff = 0;
				buff = a.get(a.length() - 1);
				for (int j = a.length() - 1; j > 0; --j)
				{
					a.set(j, a.get(j - 1));
				}
				a.set(0, buff);
			}
		}
		break;
	}
	case 5:
	{
		bool isSymmetrical = false;
		for (int i = 0; i < a.length(); ++i)
		{
			int mem = a.get(i);
			a.remove(i);
			bool isTrue = true;
			for (int j = 0; j < a.length() / 2; ++j)
			{
				if (a.get(j) != a.get(a.length() - 1 - j))
				{
					isTrue = false;
					break;
				}

			}
			a.add(i, mem);
			if (isTrue)
			{
				isSymmetrical = true;
				break;
			}
		}
		if (isSymmetrical == true)
		{
			cout << "Да, может" << endl;
		}
		else
		{
			cout << "Нет, не может" << endl;
		}
		break;
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