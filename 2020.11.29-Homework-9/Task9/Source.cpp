#include <iostream>
#include <string>
#include <clocale>
#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long ll = 0;
	while (readLong(ll) == 0) {}
	double d = 0.0;
	while (readDouble(d) == 0) {}

	cout << ll << " + " << d << " = " << ll + d;
	return 0;
}