#include <iostream>
using namespace std;
int main(int argc, char* argv[]) 
{
	int x; int res; int t;
	cin >> x;
	res = x * x;
	t = 1 + x + res * ((1 + x) + res);
	cout << t;
	return 0;
}