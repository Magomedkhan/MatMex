#include<iostream>
using namespace std;
int main() {
	int k, m, n, t;
	cout << "������� k:" << endl;
	cin >> k;
	cout << "������� m:" << endl;
	cin >> m;
	cout << "������� n:" << endl;
	cin >> n;
	if (n <= k) {
		t = 2 * m;
	}
	else if (n * 2 % k == 0) {
		t = m * int(n * 2 / k);
	}
	else { 
		t = m * (1 + int(n * 2 / k)); 
	};
	cout << t;

		return 0;
}