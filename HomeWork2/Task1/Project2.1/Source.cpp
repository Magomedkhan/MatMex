

#include<iostream>
using namespace std;

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

int main()
{
    int cap = 10;
    int* a = new int[cap];
    int count = 0;
    int choice = -1;
    while (choice != 0)
    {
        cin >> choice;
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
    delete[] a;
    return 0;
}





