#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
    cout << "����" << endl;
    cout << "0 - ����� �� ���������" << endl;
    cout << "1 - ������ ��������� ��������� � ����������" << endl;
    cout << "2 - �������� � ������ n ��������� ����� � ���������� �� a �� b(n, a, b �������� � ����������)" << endl;
    cout << "3 - ������� ������ �� �����" << endl;
    cout << "4 - ����� ������� ��������" << endl;
    cout << "5 - ���������� ������ � �������" << endl;
    cout << "6 - ����������� ��������" << endl;
    cout << "7 - ������� �������� � ������" << endl;
    cout << "8 - �������� ���������� ������ ������ ��������� �������" << endl;
    cout << "9 - ����� ���������������������" << endl;
}

int* initArray(int capacity = 10)
{
    return (new int[capacity + 2]{0, capacity}) + 2;
}

/// <summary>
/// ������������ ������ ��-��� �������
/// </summary>
/// <param name="arr">����, �� ��������� ��� �� �����-�� ������� �������. ���������� ����������� �������� ����</param>
void deleteArray(int* arr)
{
    delete[] (arr-2);
}

void expandArray(int*& arr)
{
    int newCapacity = *(arr-1) * 2;
    int* temp = new int[newCapacity]; //������ ������ ������� �����
    for (int j = 0; j < *(arr-1); ++j)
    {
        temp[j] = arr[j]; //������������ �����������
    }
    delete[] arr; //����� ������ ������
    arr = temp;
    *(arr-1) = newCapacity;
}

void addElement(int*& arr, int element)
{
    if (*(arr-2) == *(arr-1))
    {
        expandArray(arr);
    }
    arr[*(arr-2)] = element;
    arr[-2]++;
}

void addRandomElements(int*& arr, int n = 10, int min = 10, int max = 99)
{
    for (int i = 0; i < n; ++i)
    {
        addElement(arr, rand() % (max - min + 1) + min);
    }
}

void printArray(int* arr)
{
    cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
    for (int i = 0; i < *(arr - 2); ++i)
    {
        cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
    }
}

/// <summary>
/// ������� ������ ������� ��������� �������� � �������.
/// </summary>
/// <param name="arr">������ � ����������</param>
/// <param name="element">������� �������</param>
/// <param name="start">����� ������ ������</param>
/// <returns>������ ������� ���������� �������� ��� -1, ���� ������� �� ������</returns>
int search(int* arr, int element, int start = 0)
{
    for (int i = start; i < *(arr - 2); ++i)
    {
        if (*(arr + i) == element)
        {
            return i;
        }
        return -1;
    }
}

/// <summary>
/// ���������� ������� ���������.
/// </summary>
/// <param name="arr">������, � �������� ����������� ��������, ����������� ������ ���� �� ������� ����� ��� ��������� �� ������������ �������</param>
/// <param name="addedArr">������ � ������������ ����������</param>
void add(int*& arr, int* addedArr)
{
    for (int i = 0; i < (addedArr[-2]); i++)
    {
        addElement(arr, addedArr[i]);
    }
}

/// <summary>
/// ����������� ���� �������� � ����.
/// {a1, a2, a3, a4, a5} {b1, b2, b3, b4, b5, b6, b7, b8}
/// </summary>
/// <param name="a">������, �������� �������� ������ ������ �� ������ ������ � �������������� �������</param>
/// <param name="b">������, �������� �������� ������ ������ �� �������� ������ � �������������� �������</param>
/// <returns>
/// result[-1] = a[-2] + b[-2]
/// {a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, b6, b7, b8}
///</returns>
int* unify(int* a, int* b)
{
    int maxCount = (*(a - 2) > * (b - 2) ? *(a - 2):*(b-2));
    int minCount = (*(a - 2) > * (b - 2) ? *(b - 2) : *(a - 2));
    int* maxArrCount = (*(a - 2) > * (b - 2) ? a : b);
    int* result = initArray(minCount + maxCount);
    for (int i = 0; i < minCount; ++i) 
    {
        addElement(result, *(a + i));
        addElement(result, *(b + i));
    }
    for (int i = minCount; i < maxCount; ++i) 
    {
        addElement(result, *(maxArrCount + i));
    }
    return result;
}

/// <summary>
/// ���������� �������� �� �������. ��� ��������, ������� ����� ����, ������ ���� �������� �� 1 �����.
/// </summary>
/// <param name="a">������ � �������</param>
/// <param name="index">������ ������������ ��������</param>
/// <returns>�������, �������� ��� �������� index, ���� index ��� ����������� - ������� -1</returns>
int extract(int* a, int index)
{
    if ((index < 0) or (index > a [- 2]))
    {
        return -1;
    }

    int result = a[index];
    for (int i = index; i < a[- 2] - 1; ++i)
    {
        a[i] = a[i + 1];
    }
    --a[-2];

    return result;
}

/// <summary>
/// ������� �������� � ������. � ������������ �������� � ����� ������ ���� ������ index, ��� ����������� �������� ���������� �� 1 ������.
/// </summary>
/// <param name="a">�������������� ������</param>
/// <param name="index">������ ������������ ��������</param>
/// <param name="element">�������� ��������</param>
/// <returns>������������ 0, ���� ��� ������ � ������ ��� ���������, 1 - ���� ����� ��� �����������</returns>
int insert(int*& a, int index, int element)
{
    if ((index < 0) or (index > * (a - 2))) 
    {
        return 1;
    }

    if (*(a - 2) == *(a - 1))
    {
        expandArray(a);
    }

    for (int i = *(a - 2); i > index; --i)
    {
        *(a + i) = *(a + i - 1);
    }
    *(a + index) = element;
    return 0;
}

/// <summary>
/// ������� ������������������ ��������� �� �������
/// </summary>
/// <param name="a">�������������� ������</param>
/// <param name="startIndex">������ ���������� �����</param>
/// <param name="count">���������� ��������� ���������</param>
/// <returns>0, ���� ��� ������ ������, 1, ���� ������� ������ ���� �������������</returns>
int deleteGroup(int* a, int startIndex, int count = 1)
{
    if (startIndex<0 || startIndex> *(a - 2))
    {
        return 1;
    }
    for (int i = 0; i < count; ++i)
    {
        *(a + startIndex + i) = *(a + startIndex + i + count);
    }
    *(a - 2) -= count;

    return 0;
}

/// <summary>
/// ����� ��������������������� � �������
/// </summary>
/// <param name="a">������, � ������� ���� ���������������������</param>
/// <param name="b">������� ���������������������</param>
/// <returns>������ ������ ��������������������� ��� -1, ���� ������� ���</returns>
int subSequence(int* a, int* b)
{
    for (int i = 0; i < *(a - 2) - *(b - 2) + 1; ++i)
    {
        if (*(a + i) == *(b))
        {
            bool metka = true;
            for (int j = 0; j < *(b - 2); ++j)
            {
                if (*(b + j) != *(a + i + j))
                {
                    metka = false;
                }
                if (metka)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

int* resolveArray(int* arr1, int* arr2)
{
    int a = 0;
    cout << "����� ������� (1/2)";
    cin >> a;
    return(a == 1 ? arr1 : arr2);
}

void choice1Processor(int*& arr1,int*& arr2)
{
    int* arr = resolveArray(arr1, arr2);
    cout << "������� ��������(0 - ��������� �����)" << endl;
    while (true)
    {
        int x = 0;
        cin >> x;
        if (x == 0)
        {
            break;
        }
        addElement(arr, x);
    }
}

void choice2Processor(int*& arr1, int*& arr2)
{
    int* arr = resolveArray(arr1, arr2);
    cout << "���������� -";
    int n;
    cin >> n;
    cout << "Min =";
    int min;
    cin >> min;
    cout << "Max =";
    int max;
    cin >> max;
    addRandomElements(arr, n, min, max);
}

void choice3Processor(int*& arr1, int*& arr2)
{
    int* arr = resolveArray(arr1, arr2);
    printArray(arr);
}

void choice4Processor(int*& arr1, int*& arr2)
{
    int* arr = resolveArray(arr1, arr2);
    int x;
    cin >> x;
    search(arr,x,0);
}

void choice5Processor(int*& arr1, int*& arr2)
{
    cout << "������, � �������� ���������";
    int* arr_1 = resolveArray(arr1,arr2);
    cout << "������ � ������������ ����������";
    int* arr_2 = resolveArray(arr1, arr2);
    add(arr_1, arr_2);
}

void choice6Processor(int*& arr1, int*& arr2)
{
    unify(arr1, arr2);
}

void choice7Processor(int*& arr1, int*& arr2)
{
    int i, x;
    int *arr = resolveArray(arr1, arr2);
    cout << "������� ������ ������������ ��������";
    cin >> i;
    cout << "������� �������";
    cin >> x;
    insert(arr, i, x);
}

void choice8Processor(int*& arr1, int*& arr2)
{
    int startIndex, k;
    int* arr = resolveArray(arr1,arr2);
    cout << "������� ��������� ������";
    cin >> startIndex;
    cout << "������� ����������";
    cin >> k;
    deleteGroup(arr,startIndex,k);
}

void choice9Processor(int*& arr1, int*& arr2)
{
    cout << "�������� ������������������, � ������� ����� ������";
    int* arr_1 = resolveArray(arr1,arr2);
    cout << "�������� ������������������, ������� ����� ������";
    int* arr_2 = resolveArray(arr1, arr2);
    subSequence(arr_1, arr_2);
}




void processChoice(int*& arr1, int*& arr2, int choice)
{
    switch (choice)
    {
    case 1:
        choice1Processor(arr1, arr2);
        break;
    case 2:
        choice2Processor(arr1, arr2);
        break;
    case 3:
        choice3Processor(arr1, arr2);
        break;
    case 4:
        choice4Processor(arr1, arr2);
        break;
    case 5:
        choice5Processor(arr1, arr2);
        break;
    case 6:
        choice6Processor(arr1, arr2);
        break;
    case 7:
        choice7Processor(arr1, arr2);
        break;
    case 8:
        choice8Processor(arr1, arr2);
        break;
    case 9:
        choice9Processor(arr1, arr2);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int* a = initArray(10);
    int* b = initArray(10);

    int choice = 0;
    do
    {
        system("cls");
        printMenu();
        cin >> choice;
        processChoice(a, b, choice);
        system("pause");
    } while (choice != 0);

    deleteArray(a);
    deleteArray(b);
    return EXIT_SUCCESS;
}