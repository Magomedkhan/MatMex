#include<iostream>
using namespace std;
int main(){
	int n;
	int i;
	int t=1;
	cin >> n;
	for (i = 1; i <= n; i++) {
		t *= i;
	}
	cout << t;
	return 0;
}