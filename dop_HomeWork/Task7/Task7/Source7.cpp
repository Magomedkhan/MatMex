#include <iostream>
using namespace std;
int main() {
    long long i, s, n, f;
    double sum;
    cin >> n;
    sum = 1;
    f = 1;
    for (i = 1; i <= n; ++i) {
        f = f * i;
        sum = sum + 1.0 / f;
    }
    cout << sum;
    return 0;
}