#include<iostream>
using namespace std;
int main() {
	int x;
	int t;
	cin >> x;
	t = ~((~0 >> x) << x);
	cout << t;
	return 0;
}