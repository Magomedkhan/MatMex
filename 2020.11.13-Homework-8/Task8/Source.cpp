#include "Connect_List.h"
#include <iostream>
using namespace std;

int main()
{
	Connect_List list;
	for (int i = 0; i < 12; ++i)
	{
		list += i;
	}
	cout << list << endl;

	list.extractHead();
	cout << list << endl;

	list.extractTail();
	cout << list << endl;

	list.extract(6);
	cout << list << endl;

	list -= 3;
	cout << list << endl;

	cout << list.contains(7) << endl;

	Connect_List list2;
	list2 += 12;
	list2 += 42;
	list2 += 67;
	list2 += 133;
	list2 += 94;
	list = list2;
	cout << list << endl;
	return EXIT_SUCCESS;
}