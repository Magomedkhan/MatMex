#include <iostream>

using namespace std;

int flip(int bit) {
    return 1 ^ bit;
}

int sign(int a) {
    return flip((a >> 31) & 0x1);
}

int MyMax(int a, int b)
{
    int k = sign(a - b);
    int q = flip(k);
    return a * k + b * q;
}


int main()
{
    int a, b, t;
    cin >> a >> b;
    t = MyMax(a, b);
    cout << (t % ((a + b) - t)+1);
    return 0;
}