#include<iostream>
using namespace std;//все команды кроме 5 работают без двумерного массива, так как без него можно получить требуемый результат 

void func1(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1+i; j <= n+i; ++j)
		{
			cout << j;
		}
		cout << endl;
	}
}


void func2(int n)
{
	for (int i = n; i > 0; --i)
	{
		for (int j = n+i-1; j > i-1; --j)
		{
			cout << j;
		}
		cout << endl;
	}

}

void func3(int n)
{

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << j;
		}
		cout << endl;
	}
}

void func4(int n)
{
	for (int i = 1; i <= n; ++i)
	{ 
		for (int j = 1; j <= n; ++j)
		{
			if (i <= j) {
				cout << i;
			}
			else {
				cout << j;
			}
		}
		cout << endl;
	}
}

void func5(int n)//я не смог здесь обойтись без двумерного массива
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