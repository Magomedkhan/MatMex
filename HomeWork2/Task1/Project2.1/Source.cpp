#include<iostream>
using namespace std;

void printMenu()
{
    cout << "����" << endl;
    cout << "0 - ����� �� ���������" << endl;
    cout << "1 - �������� ����� � ������" << endl;
    cout << "2 - ������� ������ �� �����" << endl;
    cout << "3 - ����� ����� ������������� �������� �������" << endl;
    cout << "4 - ����� ����������� ������� �������" << endl;
    cout << "5 - ��������� ����� ��������� �������" << endl;
    cout << "6 - ������� ������ � �������� �������" << endl;
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
    deleteArray(arr); 
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

int MaxNumb(int* arr, int count)
{
    int max = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > arr[max])
        {
            arr[max] = arr[i];
            max = i;
        }
    }
    return max;
}

int Min(int* arr, int count)
{
    int min = arr[0];
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int Sum(int* arr, int count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

void BackArr(int *arr, int count)
{
    cout << "{";
    for (int i = count-1; i >= 0; --i)
    {
        cout << arr[i] << ";";
    }
    cout << "}";
}

void processChoice(int*& a, int& count, int& cap, int choice)
{
    switch (choice)
    {
    case 1:
    {
        int x;
        cin >> x;
        input(a, count, cap, x);
        count++;
    }
        break;
    case 2:
        output(a, count);
        break;
    case 3:
        cout << MaxNumb(a, count);
        break;
    case 4:
        cout << Min(a, count);
        break;
    case 5:
        cout << Sum(a, count);
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





