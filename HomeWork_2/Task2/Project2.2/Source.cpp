

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void PrintMenu()
{
    cout << "0 - Выход из программы" << endl;
    cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b" <<endl;
    cout << "2 - Развернуть массив" << endl;
    cout << "3 - Поменять элементы массива местами в парах" << endl;
    cout << "4 - Циклический сдвиг вправо на 1" << endl;
    cout << "5 - Развернуть две половинки массива" << endl;
    cout << "6 - Вывод массива на экран" << endl;
}

void expandArray(int*& arr, int& capacity)
{
    int newCapacity = capacity * 2;
    int* temp = new int[newCapacity];
    for (int j = 0; j < capacity; ++j)
    {
        temp[j] = arr[j];
    }
    delete[]arr;
    arr = temp;
    capacity = newCapacity;
}

void input(int*& arr, int& count, int& cap, int element)
{
    if (count == cap)
    {
        expandArray(arr, cap);
    }
    arr[count] = element;
    count++;
}

void inputRandom(int*& arr, int& count, int& cap, int n, int min, int max)
{
    for (int i = 0; i < n; ++i)
    {
        input(arr, count, cap, rand()%(max-min+1)+min);
    }
}


void output(int* arr, int count)
{
    cout << "{";
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] <<";";
    }
    cout << "}";
}

void BackArr(int* arr, int count)
{
    int temp;
    for (int i = 0; i < count / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[count - 1 - i];
        arr[count - 1 - i] = temp;
    }
}

void shiftArr(int* arr, int count)
{
    int temp = arr[count - 1];
    for (int i = count - 1; i >=1; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void swap(int& a, int& b)
{
    a ^= b; b ^= a; a ^= b;
}

void reverseArray(int* arr, int count)
{
    for (int i = 0; i < count / 2; ++i)
    {
        swap(arr[i],arr[count-1-i]);
    }
}

void swapPairsArray(int* arr, int count)
{
    for (int i = 1; i < count; i += 2)
    {
        swap(arr[i - 1], arr[i]);
    }
}

void abc(int* arr, int count, int n)
{
    reverseArray(arr, n);
    reverseArray(arr + n, count - n);
}



void ProcessChoice(int*& a, int& count, int& cap, int choice)
{
    switch (choice)
    {
    case 1:
    {
        int n;
        int min;
        int max;
        cin >> n;
        cin >> min;
        cin >> max;
        inputRandom(a, count, cap, n, min, max);
        break;
    }
    case 6:
        output(a, count);
        break;
    case 3:
        swapPairsArray(a, count);
        break;
    case 4:
        shiftArr(a, count);
        break;
    case 5:
    {
        int n;
        cin >> n;
        abc(a, count, n);
        break;
    }
    case 2:
        BackArr(a, count);
        break;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int cap = 10;
    int* a = new int[cap];
    int count = 0;
    int choice = -1;
    int t;
    while (choice != 0)
    {
        system("cls");
        PrintMenu();
        cin >> choice;
        ProcessChoice(a, count, cap, choice);
        system("pause");
    }
    delete []a;
    return 0;
}





