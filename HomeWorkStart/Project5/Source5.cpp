#include<iostream>
using namespace std;
int main() {
	int n;
	int i;
	int k=0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			k+=1;
		}
	}
	cout << (k);
	return 0;
}