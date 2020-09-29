#include<iostream>
using namespace std;
int main()
{
	int sum = 0;
	int t;
	int i, j, k;
	char bilet[6];
	cin >> t;
	for (i = 0; i <= 999999; i++)
	{
		for (k = i, j = 0; j < 6; j++,k/=10) {
			bilet[j] = k % 10;
		}
		if ((bilet[0] + bilet[2] + bilet[4] == t) and (bilet[1] + bilet[3] + bilet[5]==t)) {
			++sum;
		}
	}
	cout << sum;
}