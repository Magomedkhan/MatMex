#include<iostream>
using namespace std;

template <class T1, class T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template <class T1, class T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template <class T1, class T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template <class T1, class T2>
T1 div(T1 a, T2 b)
{
	return a / b;
}


template <class T1, class T2>
T1 rem(T1 a, T2 b)
{
	return a % b;
}

template<class T1, class T2>
void calc(T1 a, T2 b, T1(*op)(T1, T2))
{
	cout << op(a, b) << endl;
}

template<class T1, class T2>
void resolveOpNumber(T1 operand1, T2 operand2, char sign)
{
	switch (sign)
	{
	case '+':
	{
		calc(operand1, operand2, sum);
		break;
	}
	case '-':
	{
		calc(operand1, operand2, diff);
		break;
	}
	case '*':
	{
		calc(operand1, operand2, mult);
		break;
	}
	case '/':
	{
		calc(operand1, operand2, div);
		break;
	}
	case '%':
	{
		calc(operand1, operand2, rem);
		break;
	}
	}
}



int main()
{
	char sign;
	int operand1, operand2; // как задать шаблон?
	cin >> operand1 >> operand2 >> sign;
	resolveOpNumber(operand1, operand2, sign);


	return 0;
}