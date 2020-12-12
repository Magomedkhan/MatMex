#include <iostream>
using namespace std;
int main()
{
	int h, a, b;
	cout << "¬ведите последовательно h,a,b" << endl;
	cin >> h >> a >> b;
	cout << int((h - b) / (a - b) + 1);
	return 0;
}