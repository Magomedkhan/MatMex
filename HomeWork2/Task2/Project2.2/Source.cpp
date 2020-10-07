

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
    int n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    if (count == cap)
    {
        expandArray(arr, cap);
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[count] = a + rand() % (b - a);
        count++;
    }
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

void abc(int* arr, int count)
{
    int n;
    cin >> n;
        int temp;
        for (int i = 0; i < int(n / 2); i++)
        {
            temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
    for (int i = 0; i < n+int((count-n)/2); i++)
    {
            temp = arr[n+i];
            arr[n+i] = arr[count - 1 -(n+i)];
            arr[n + count - 1 - i] = temp;
        
    }
}

void ProcessChoice(int*& a, int& count, int& cap, int choice)
{
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
        abc(a, count);
        break;
    case 2:
        BackArr(a, count);
        break;
    }
}

void deleteArray(int*& arr)
{
    delete[] arr;
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
    deleteArray(a);
    return 0;
}





