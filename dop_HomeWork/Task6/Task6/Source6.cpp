#include <iostream>
using namespace std;
int main() {
    int k = 1;
    int s; cin >> s;
    for (int i = 1; k <= s; i++)
        for (int j = 1; j <= i && k <= s; j++)
        {
            cout << i << ' ';
            k++;
        }
    return 0;
}