#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

bool check_letter(char a);
bool check_digit(char a);
bool id(char a);
bool unsigned_int(string a, int l);
bool mult(string a, int l);
int inspection(string a, int l, char ch);
bool term(string a, int l);
bool check_expression(string a, int l);



int main() {

	fstream fin;
	fin.open("in.txt");

	string str = "";
	char symb;

	while (fin >> symb) {
		str.push_back(symb);
	}

	fin.close();

	if (check_expression(str, str.length())) {
		cout << "= )";
		return 0;
	}

	cout << "= (";
	return 0;
}

bool check_letter(char a) {
	return ('x' <= a) && (a <= 'z');
}

bool check_digit(char a) {
	return (a == '0') || (a == '1');
}

bool id(char a) {
	return check_letter(a);
}

bool unsigned_int(string a, int len) {
	if (len != 0) {
		return check_digit(a[0]) && unsigned_int(a.substr(1, len - 1), len - 1);
	}
	else return true;
}




int inspection(string a, int len, char ch) {

	int i = 0;
	while ((i < len) && (a[i] != ch)) {
		i++;
	}
	return i;
}

bool check_expression(string a, int len) {
	int index = 0;
	if (((inspection(a, len, '+') != -1) || (inspection(a, len, '-') != -1)) && ((len - 1 - inspection(a, len, '+')) > 0) && ((len - 1 - inspection(a, len, '-')) > 0)) 
	{

		if (inspection(a, len, '+') < inspection(a, len, '-'))
		{
			index = inspection(a, len, '+');
		}
		else
		{
			index = inspection(a, len, '-');
		}

		return term(a.substr(0, index), index) && check_expression(a.substr(index + 1, len - 1 - index), len - 1 - index);
	}
	else return term(a, len);
}

bool mult(string a, int len) {

	bool isID = ((len == 1) && (id(a[0])));
	bool isExpr = ((len > 2) && (check_expression(a.substr(1, len - 2), len - 2)));

	return unsigned_int(a, len) || isID || isExpr;
}


bool term(string a, int len) {
	if ((inspection(a, len, '*') != -1) && (a[0] == '(') && (a[len - 1] == ')') && ((len - 2 - inspection(a, len, '*')) > 0)) {
		int index = inspection(a, len, '*');
		return mult(a.substr(1, index - 1), index - 1) && term(a.substr(index + 1, len - 2 - index), len - 2 - index);
	}
	else if ((inspection(a, len, '+') != -1) && ((len - 1 - inspection(a, len, '+')) > 0)) {
		int index = inspection(a, len, '+');
		return mult(a.substr(0, index), index) && term(a.substr(index + 1, len - 1 - index), len - 1 - index);
	}
	else return mult(a, len);
}
