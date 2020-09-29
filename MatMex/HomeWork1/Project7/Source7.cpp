#include<iostream>
using namespace std;
int main() {
	int x;
	int t=1;
	int n;
	cin >> x;
	cin >> n;
	for (int i = 1; i <=n; i++) {
		t*= x;
	}
	cout << t;
	return 0;
}