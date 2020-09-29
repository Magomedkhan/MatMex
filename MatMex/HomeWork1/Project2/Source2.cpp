#include<iostream>
using namespace std;
int main()
{
	int i = 1;
	int x;
	int y;
	int t;
	cin >> x;
	cin >> y;
	t = y;
	while (y < x)
	{
	i += 1;
	y = t;
	y = y * i;
	}
	if (i*t>x)
	{
		i -= 1;
	}
	cout << i;
	return 0;
}