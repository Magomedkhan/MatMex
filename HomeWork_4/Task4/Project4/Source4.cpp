#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"
using namespace std;
void printMenu()
{ 
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
 cout << "4 - Удалить элемент по индексу" << endl;
 cout << "5 - Найти элемент" << endl; cout << "6 - Добавить несколько элементов" << endl;
 cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
} 

void processChoice(ArrayList& a, int choice)
{ 
	
switch (choice)
{ 
case 1: {
	a.print();
} break;
case 2: {
	int x;
	cin >> x;
	a.add(x);
} break;
case 3: {
	int index;
	int x;
	cin >> index >> x;
	a.add(index, x);
} break;
case 4: {
	int index;
	cin >> index;
	a.remove(index);
} break;
case 5: {
	int x = 0;
	cin >> x;
	cout << a.indexOf(x) << endl;
} break;
case 6: {
	ArrayList list;
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int x;
		cin >> x;
		list.add(x);
	}
	a.addAll(list);
	break;
} break;
case 7: { 
	ArrayList list;
	int num;
	int index;
	std::cin >> num >> index;
	for (int i = 0; i < num; ++i)
	{
		int x;
		std::cin >> x;
		list.add(x);
	}
	a.addAll(index, list);
} break;
}
}
int main()
{ 
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a; int choice = 0;
	do { system("cls");
	printMenu(); cin >> choice;
	processChoice(a, choice);
	system("pause");
	}
	while (choice != 0);
	return EXIT_SUCCESS;
}