#include<iostream>

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
        int a, b;
        cin >> a >> b;
        cout << MyMax(a, b);
        return 0;
    }
