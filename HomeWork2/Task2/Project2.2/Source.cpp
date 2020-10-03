

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

void bit_1(int* arr, int count)
{
    int temp;
    for (int i = 0; i < count - 1; i+=2)
    {
        for (int j =i+1; j < count; j+=2)
        {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            
        }
    }

}

void bothArr(int* arr, int count)
{
    int temp;
    for (int i=0; i<int(count/2)*2; i+=2)
    {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void abc(int* arr, int count, int n)
{
        int temp;
        for (int i = 0; i < int(n / 2); i++)
        {
            temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
    for (int i =n + 1; i<= n+int((count-n)/2); i++)
    {
        
            temp = arr[n+i];
            arr[n+i] = arr[count - 1 -(n+i)];
            arr[n + count - 1 - i] = temp;
        
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
        case 6:
            output(a, count);
            break;
        case 3:
            bothArr(a, count);
            break;
        case 4:
            bit_1(a, count);
            break;
        case 5:
            int n;
            abc(a, count,n);
            break;
        case 2:
            BackArr(a, count);
            break;
        }
    }
    delete[] a;
    return 0;
}





