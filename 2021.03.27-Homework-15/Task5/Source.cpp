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
void merge(int* a1, int* a2, int len1, int len2, int* mergeArr)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len1 && j < len2)
    {
        if (a1[i] < a2[j])
        {
            mergeArr[k++] = a1[i++];
        }
        else
        {
            mergeArr[k++] = a2[j++];
        }
    }

    while (i < len1)
    {
        mergeArr[k++] = a1[i++];
    }
    while (j < len2)
    {
        mergeArr[k++] = a2[j++];
    }
}


int main()
{
    int len = 0;
    cout << "¬ведиите количество элементов массива" << endl;
    cin >> len;
    int* a = new int[len];

    cout << "¬вести 0 - вручную или 1 - рандомно?" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice) {
    case 0:
        initArray(a, len);
        break;

    case 1:
        fillArray(a, len);
        printArray(a, len);
        break;
    }

    cout << "быстра€ сортировка - 0 или сортировка с подсчетом - 1 ?" << endl;
    choice = 0;
    cin >> choice;
    switch (choice) {

    case 0:
        cout << "быстра€ сортировка" << endl;
        quick_Sort(a, len);
        break;

    case 1:
        cout << "сортировка подсчетом" << endl;
        count_Sort(a, len);
        break;

    }

    printArray(a, len);

    cout << "—мешать два массива 0 - да или 1 - нет" << endl;
    choice = 0;
    cin >> choice;
    switch (choice) {

    case 0:
        int len_ = 0;
        cout << "¬ведите количество элементов массива" << endl;
        cin >> len_;
        int* a_ = new int[len_] {0};
        for (int i = 0; i < len_; ++i)
        {
            cout << '<' << i + 1 << '>' << ' ';
            cin >> a_[i];
        }
        count_Sort(a_, len_);
        int* a0 = new int[len + len_];
        merge(a, a_, len, len_, a0);
        cout << "Merge" << endl;
        printArray(a0, len + len_);
        delete[] a_;
        delete[] a0;
        break;
    }


    delete[] a;
    return 0;
}