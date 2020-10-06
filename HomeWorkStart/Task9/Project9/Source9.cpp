#include<iostream>
using namespace std;
int main() {
	int x;
	int t;
	cin >> x;
	t = ~(1<< x);
	cout << t;
	return 0;
}