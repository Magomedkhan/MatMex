#include <iostream>
using namespace std;

int max_Element(int* a, int len)
{
    int max = a[0];
    for (int i = 1; i < len; ++i)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void count_Sort(int* a, int len)
{
    int k = max_Element(a, len);
    int temp[k + 1] = { 0 };
    for (int i = 0; i < len; ++i)
    {
        ++temp[a[i]];
    }

    int b = 0;
    for (int i = 0; i < k + 1; ++i)
    {
        for (int j = 0; j < temp[i]; ++j)
        {
            a[b++] = i;
        }
    }
}

void swap(int*& a, int i, int j)
{
    int temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void quick_Sort(int* a, int len) {
    int i = 0;
    int j = len - 1;
    int p = a[len / 2];

    do
    {
        while (a[i] < p) i++;
        while (a[j] > p) j--;

        if (i <= j)
        {
            swap(a, i, j);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) quick_Sort(a, j);
    if (len > i) quick_Sort(a + i, len - i);
}

void initArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << "<" << i + 1 << ">" << ' ';
        cin >> a[i];
    }
}

void fillArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        a[i] = rand() % 90 + 10;
    }
}

void printArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int num = 0;
    cout << "Введиите количество элементов массива" << endl;
    cin >> num;
    int* a = new int[num];

    cout << "Ввести 0 - вручную или 1 - рандомно?" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice) {
    case 0:
        initArray(a, num);
        break;

    case 1:
        fillArray(a, num);
        printArray(a, num);
        break;
    }

    cout << "быстрая сортировка - 0 или сортировка с подсчетом - 1 ?" << endl;
    choice = 0;
    cin >> choice;
    switch (choice) {

    case 0:
        cout << "быстрая сортировка" << endl;
        quick_Sort(a, num);
        break;

    case 1:
        cout << "сортировка подсчетом" << endl;
        count_Sort(a, num);
        break;

    }

    printArray(a, num);

    delete[] a;
    return 0;
}