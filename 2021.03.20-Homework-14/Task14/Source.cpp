#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void fillArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        a[i] = rand() % 90 + 10;
    }

}

void mixArray(int* a, int len)
{
    for (int i = 0; i < len; ++i)
    {
        swap(a[i], a[rand() % len]);
    }
}

void printCount(int a, int b)
{
    cout << "Количество сравнений: " << a / 1000 << endl;
    cout << "Количество перестановок: " << b / 1000 << endl;
}

void bubbleSort(int* a, int len, int& compBubble, int& permBubble)
{
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            ++compBubble;
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ++permBubble;
            }
        }
    }
}

void insertionSort(int* a, int len, int& compInsertion, int& permInsertion)
{
    for (int i = 1; i < len; ++i)
    {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t)
        {
            ++compInsertion;
            a[j] = a[j - 1];
            --j;
        }
        a[j] = t;
        ++permInsertion;
    }
}

void selectionSort(int* a, int len, int& compSelection, int& permSelection)
{
    for (int i = 0; i < len - 1; ++i)
    {
        int index = i;
        for (int j = i + 1; j < len; ++j)
        {
            ++compSelection;
            if (a[j] < a[index])
            {
                index = j;
            }
        }
        swap(a[i], a[index]);
        ++permSelection;
    }
}

void sort(int* a, int len, int& comp, int& perm, void (*sortFunction)(int*, int, int&, int&))
{
    for (int i = 0; i < 1000; ++i)
    {
        mixArray(a, len);
        sortFunction(a, len, comp, perm);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    for (int k = 5; k <= 20; k += 5)
    {
        int* a = new int[k];
        fillArray(a, k);

        cout << "Cортировка пузырьком:" << endl;
        int compBubble = 0;
        int permBubble = 0;
        sort(a, k, compBubble, permBubble, bubbleSort);
        printCount(compBubble, permBubble);
        cout << endl;

        cout << "Сортировка вставки:" << endl;
        int compInsertion = 0;
        int permInsertion = 0;
        sort(a, k, compInsertion, permInsertion, insertionSort);
        printCount(compInsertion, permInsertion);
        cout << endl;

        cout << "Сортировка выбора:" << endl;
        int compSelection = 0;
        int permSelection = 0;
        sort(a, k, compSelection, permSelection, selectionSort);
        printCount(compSelection, permSelection);

        cout <<"******************";
        cout << endl;

        delete[] a;
    }

    return 0;
}