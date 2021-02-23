#include <iostream>
using namespace std;

void printBits(unsigned int a) {
    int bitLength = sizeof(a) * 8;
    for (int i = 0; i < bitLength; i++) {
        cout << (unsigned int)((a & (1 << (bitLength - 1))) >> (bitLength - 1));
        a = a << 1;
    }
    cout << ' ';
}
void printBits(unsigned long a)
{
    long long bitLength = sizeof(a) * 8;
    for (int i = 0; i < bitLength; i++) {
        cout << (unsigned long long)((a & (1 << (bitLength - 1))) >> (bitLength - 1));
        a = a << 1;
    }
    cout << ' ';
}

void printBits(unsigned long long a) {
    long long bitLength = sizeof(a) * 8;
    for (int i = 0; i < bitLength; i++) {
        cout << (unsigned long long)((a & (1 << (bitLength - 1))) >> (bitLength - 1));
         a = a << 1;
    }
    cout << ' ';
}
void printBits(double a)
{
    double dr0 = a - int(a);
    if (a < 0 && dr0 != 0)
    {
        cout << '-';
        a *= (-1);
    }
    unsigned long long cel = (long long)a;
    long long bitLength = sizeof(a) * 8;
    for (int i = 0; i < bitLength; i++) {
        cout << (unsigned long long)((cel & (1 << (bitLength - 1))) >> (bitLength - 1));
    cel = cel << 1;
    }
  cel = (long long int)a;// что-то не так. Переменная не может принять значение другой переменной при целых отрицательных A;
  double dr = a - cel;
  if (dr != 0) {
      cout << ',';
  }
  else
  {
      return;
  }
    for (int i = 0; i < bitLength; i++)
    {
        dr *= 2.0;
        cel = int(dr);
        cout << cel;
        dr -= cel;
    }
}

void printBits(float a)
{
    float dr0 = a - int(a);
    if (a < 0 && dr0 != 0)
    {
        cout << '-';
        a *= (-1);
    }
    unsigned long cel = (long)a;
    long bitLength = sizeof(a) * 8;
    for (int i = 0; i < bitLength; i++) {
        cout << (unsigned long)((cel & (1 << (bitLength - 1))) >> (bitLength - 1));
        cel = cel << 1;
    }
    cel = (long int)a;// что-то не так. Переменная не может принять значение другой переменной при целых отрицательных A;
    float dr = a - cel;
    if (dr != 0) {
        cout << ',';
    }
    else
    {
        return;
    }
    for (int i = 0; i < bitLength; i++)
    {
        dr *= 2.0;
        cel = int(dr);
        cout << cel;
        dr -= cel;
    }
}
double average(int n, ...)
{
    double result = 0;
    for (int i = 0; i < n; i++)//?
    {
        cout << i <<':';
        void* ptr = &n + 1 + i;
        result += *((double*)ptr);
    }
    return (result / *&n);
 }

/*void printBits(float a)
{
    void* ptr;
    ptr = &a;
    int temp = *((int*)ptr);
    printBits((unsigned int)temp);
}*/

int main()
{
    //float a;
   // cin >> a;
    //printBits(a);
    cout << average(6, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6);
    return 0;
}
