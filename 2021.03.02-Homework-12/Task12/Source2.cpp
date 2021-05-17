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
int temp(T1 a, T2 b, char sign) {
	T1 t = rem(a, b);
	if (t != -1) {
		cout << a << " " << sign << " " << b << " " << "=" << " "; resolveOpNumber(a, b, sign);
	}
	else { cout << "ban"; }
	return 0;
}
template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
void input(T1& a1, T2& a2, T3& a3, T4& a4, T5& a5, T6& a6, T7& a7, T8& a, T9& b, char sign)
{
	char* sign0;
	if (a2 == "--operand1") {
		a = stod(a3);
	}
	else if (a4 == "--operand1") {
		a = stod(a5);
	}
	else {
		a = stod(a7);
	}

	if (a2 == "--operand2") {
		b = stod(a3);
	}
	else if (a4 == "--operand2") {
		b = stod(a5);
	}
	else {
		b = stod(a7);
	}

	if (a2 == "--operator") {
		sign0 = a3;
	}
	else if (a4 == "--operator") {
		sign0 = a5;
	}
	else {
		sign0 = a7;
	}
	sign = *sign0;
	temp(a, b, sign);
}


int main(int argc, char* argv[])
{
	if (argv[0] == NULL || argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL || argv[5] == NULL || argv[6] == NULL || argv[7] == NULL) { cout << "ban"; return 0; }
	else {
		double a; double b; char sign = 0;
		input(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], a, b, sign);
	}
}