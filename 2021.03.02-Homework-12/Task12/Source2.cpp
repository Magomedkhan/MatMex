#include<iostream>
#include<string>
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
T1 div_(T1 a, T2 b)
{
	return a / b;
}


template <class T1, class T2>
T1 rem(T1 a, T2 b)
{
	int t_a = (int)(a * 10);  int t_b = (int)(b * 10);

	if (t_a % 10 == 0 && t_b % 10 == 0)
	{
		int t = (int)a / b;
		t = a - t * b;
		return t;

	}
	else
	{
		return -1;
	}
}

template<class T1, class T2>
void calc(T1 a, T2 b, T1(*op)(T1, T2))
{
	cout << op(a, b) << endl;
}

template<class T1, class T2>
void resolveOpNumber(T1 operand1, T2 operand2, char sign)
{
	T1(*ops[5])(T1, T2) = { sum, diff, mult, div_, rem };

	switch(sign)
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




int main(int argc, char* argv[])
{
	if (argv[0] == NULL || argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL || argv[5] == NULL || argv[6] == NULL || argv[7] == NULL) { cout << "ban"; return 0; }
	else {
		double a = stod(argv[3]); double b = stod(argv[5]);
		char* sign0 = argv[7];
		char sign = *sign0;
		if (rem(a, b) != -1) {
			cout << a << " " << sign << " " << b << " " << "=" << " "; resolveOpNumber(a, b, sign);
		}
		else { cout << "ban"; }
		return 0;
	}
}