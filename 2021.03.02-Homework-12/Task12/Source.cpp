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
	T1(*ops[5])(T1, T2) = { sum, diff, mult, div, rem };

	switch (sign)
	{
	case '+':
	{
		calc(operand1, operand2, ops[0]);
		break;
	}
	case '-':
	{
		calc(operand1, operand2, ops[1]);
		break;
	}
	case '*':
	{
		calc(operand1, operand2, ops[2]);
		break;
	}
	case '/':
	{
		calc(operand1, operand2, ops[3]);
		break;
	}
	case '%':
	{
		calc(operand1, operand2, ops[4]);
		break;
	}
	}
}

template<class T1, class T2>
void input(T1 operand1, T2 operand2)
{
	char sign;
	cin >> operand1 >> operand2 >> sign;
	resolveOpNumber(operand1, operand2, sign);
}

int main(int argc, char** argv)
{
	input(0, 0);
	return 0;
}