

#include<iostream>
using namespace std;

void printMenu()
{
    cout << "МЕНЮ" << endl;
    cout << "0 - Выход из программы" << endl;
    cout << "1 - Добавить число в массив" << endl;
    cout << "2 - Вывести массив на экран" << endl;
    cout << "3 - Найти номер максимального элемента массива" << endl;
    cout << "4 - Найти минимальный элемент массива" << endl;
    cout << "5 - Посчитать сумму элементов массива" << endl;
    cout << "6 - вывести массив в обратном порядке" << endl;
}

void deleteArray(int* arr)
{
    delete[] arr;
}

void expandArray(int*& arr, int& capacity)
{
    int newCapacity = capacity * 2;
    int* temp = new int[newCapacity];
    for (int j = 0; j < capacity; ++j)
    {
        temp[j] = arr[j];
    }
    delete[] arr; 
    arr = temp;
    capacity = newCapacity;
}

void input(int*& arr, int& count, int& cap)
{
    int x;
    cin >> x;
    if (count == cap)
    {
        expandArray(arr, cap);
    }
    arr[count] = x;
    count++;
}


void output(int* arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }
}

void MaxNumb(int* arr, int count)
{
    int max = -1;
    int m = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            m = i;
        }
    }
    cout << m;
}

void Min(int* arr, int count)
{
    int min = 1000000;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << min;
}

void Sum(int*& arr, int& count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }
    cout << sum;
}

void BackArr(int *arr, int count)
{
    int i;
    for (i = count-1; i >= 0; --i)
    {
        cout << arr[i] << endl;
    }
}

void processChoice(int *&a, int& count, int& cap, int choice)
{
    switch (choice)
    {
    case 1:
        input(a, count, cap);
        break;
    case 2:
        output(a, count);
        break;
    case 3:
        MaxNumb(a, count);
        break;
    case 4:
        Min(a, count);
        break;
    case 5:
        Sum(a, count);
        break;
    case 6:
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
    while (choice != 0)
    {
        system("cls");
        printMenu();
        cin >> choice;
        processChoice(a,count,cap,choice);
        system("pause");
    }
    deleteArray(a);
    return 0;
}





