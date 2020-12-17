#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

void resolveError(int errorCode)
{
	string output1[15] = { " ввели пробел", " ввели символ", " ввели букву из латиницы", " ввели лишнюю точку" };

	int ran = rand() % 2 + 1;
	if (ran == 1)
	{
		cout << "Извините за ограниченный функционал программы, возможно, вы случайно " << output1[errorCode - 1] << ". Введите, пожалуйста, еще раз" << endl;
	}
	else
	{
		cout << "Простите за ограниченный функционал программы, наверно, вы нечаянно" << output1[errorCode - 1] << ". Пожалуйста, повторите ввод" << endl;
	}
}

int readLong(long long& ll)
{
	string str1;
	long long temp = 0;
	getline(cin, str1);
	for (int i = 0; i < str1.size(); ++i)
	{
		if (str1[i] == 32)
		{
			resolveError(1);
			return 0;
		}
		if ((str1[i] >= 33) and (str1[i] <= 47))
		{
			resolveError(2);
			return 0;
		}
		if ((str1[i] >= 58) and (str1[i] <= 64))
		{
			resolveError(2);
			return 0;
		}
		if ((str1[i] >= 91) and (str1[i] <= 96))
		{
			resolveError(2);
			return 0;
		}
		if ((str1[i] >= 123) and (str1[i] <= 127))
		{
			resolveError(2);
			return 0;
		}
		if ((str1[i] >= 65) and (str1[i] <= 90))
		{
			resolveError(3);
			return 0;
		}
		if ((str1[i] >= 97) and (str1[i] <= 122))
		{
			resolveError(3);
			return 0;
		}
		
		if ((str1[i] >= 48) and (str1[i] <= 57))
		{
			temp = temp * 10 + (str1[i] - '0');
		}
		else
		{
			cout << " допущена ошибка " << endl;
			return 0;
		}
	}
	ll = temp;
	return ll;
}

double readDouble(double& d)
{
	string str2;
	double t = 0;
	getline(cin, str2);
	bool metka = false;
	int k = 0;
	for (int i = 0; i < str2.size(); ++i)
	{
		if (str2[i] == 32)
		{
			resolveError(1);
			return 0;
		}
		if ((str2[i] >= 33) and (str2[i] <= 45))
		{
			resolveError(2);
			return 0;
		}
		if (str2[i] == 47)
		{
			resolveError(2);
			return 0;
		}
		if ((str2[i] >= 58) and (str2[i] <= 64))
		{
			resolveError(2);
			return 0;
		}
		if ((str2[i] >= 91) and (str2[i] <= 96))
		{
			resolveError(2);
			return 0;
		}
		if ((str2[i] >= 123) and (str2[i] <= 127))
		{
			resolveError(2);
			return 0;
		}
		if ((str2[i] >= 65) and (str2[i] <= 90))
		{
			resolveError(3);
			return 0;
		}
		if ((str2[i] >= 97 )and (str2[i] <= 122))
		{
			resolveError(3);
			return 0;
		}
		if ((metka == true) and (str2[i] == '.'))
		{
			resolveError(4);
			return 0;
		}
		if (metka == true)
		{
			k++;
		}
		if (str2[i] == '.')
		{
			metka = true;
		}
		if ((str2[i] >= 48) and (str2[i] <= 57))
		{
			t = t * 10 + (str2[i] - '0');
		}
		else if (str2[i] != '.')
		{
			cout << " допущена ошибка " << endl;
			return 0;
		}

	}
	d = t;
	d /= pow(10, k);
	return d;
}