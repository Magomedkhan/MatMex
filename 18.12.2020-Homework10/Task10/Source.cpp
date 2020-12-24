#include<iostream>
using namespace std;

void func1(int n)
{
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = 1 + i + j ;
			cout << A[i][j] <<" ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}


void func2(int n)
{
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = 2 * n - 1 - i - j ;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}


void func3(int n)
{
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = j + 1;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}

void func4(int n)
{
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j <= i)
			{
				A[i][j] = j + 1;
			}
			else
			{
				A[i][j] = i + 1;
			}
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}

void func5(int n)
{
	int** A = new int* [n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[n];
	int i = 1, p = n / 2;
	for (int k = 1; k <= p; k++)
	{
		for (int j = k - 1; j < n - k + 1; j++) A[k - 1][j] = i++;
		for (int j = k; j < n - k + 1; j++) A[j][n - k] = i++;
		for (int j = n - k - 1; j >= k - 1; --j) A[n - k][j] = i++;
		for (int j = n - k - 1; j >= k; j--) A[j][k - 1] = i++;
	}
	if (n % 2 == 1) A[p][p] = n * n;
	for (i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << " ";
			if (j == n - 1) cout << endl;
		}

	for (int i = 0; i < n; ++i)
		delete[] A[i];
	delete[] A;
}
int main()
{
	int n;
	int metka;
	cin >> n;
	cin >> metka;
	switch (metka)
	{
	case 1:
		func1(n);
		break;
	case 2:
		func2(n);
		break;
	case 3:
		func3(n);
		break;
	case 4:
		func4(n);
		break;
	case 5:
		func5(n);
		break;
	}
	return 0;
}