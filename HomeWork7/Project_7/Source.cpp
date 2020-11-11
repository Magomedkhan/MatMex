#include <iostream>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ����� ������ � �����" << endl;
	cout << "2, 3 - ���������� �������� � ����� ������" << endl;
	cout << "4 - ���������� �������� � ������ ������" << endl;
	cout << "5, 9 - �������� ���������� ��������� ��������" << endl;
	cout << "6 - ����������" << endl;
	cout << "7 - �������� �������" << endl;
	cout << "8 - �������� ������� �������� �� ������" << endl;
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
		cout << a << endl;
		break;
	}
	case 2:
	{
		int element = 0;
		cin >> element;
		a += element;
		break;
	}
	case 3:
	{
		int element = 0;
		cin >> element;
		a = a + element;
		break;
	}
	case 4:
	{
		int element = 0;
		cin >> element;
		a = element + a;
		break;
	}
	case 5:
	{
		int element = 0;
		cin >> element;
		a -= element;
		break;
	}
	case 6:
	{
		ArrayList list;
		// list.add(...)
		a = list;
		break;
	}
	case 7:
	{
		a = a + a;
		break;
	}
	case 8:
	{
		int element = 0;
		cin >> element;
		a = element - a;
		break;
	}
	case 9:
	{
		int element = 0;
		cin >> element;
		a = a - element;
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