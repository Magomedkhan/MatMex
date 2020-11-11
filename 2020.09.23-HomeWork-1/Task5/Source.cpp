#include <iostream>
using namespace std;
int main()
{
    int k=0;
    int n;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            k += 1;
        }
    }
    if (k % 2 == 0)
    {
        cout << k + 2;
    }
    else cout << k + 1;

    return 0;
}