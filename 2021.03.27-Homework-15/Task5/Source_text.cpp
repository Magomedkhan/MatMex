#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char temp;
	fstream fbin;

	while (fbin.read((char*)&temp, sizeof(char)))
	{
		cout << temp;
	}
	fbin.close();

	fbin.open("in.txt", ios::binary | ios::in | ios::out);
	while (fbin.read((char*)&temp, sizeof(char)))
	{
		temp = toupper(temp);
		if ((temp == 'A') || (temp == 'E') || (temp == 'I') || (temp == 'O') || (temp == 'U') || (temp == 'Y'))
		{
			fbin.seekg(-(int)sizeof(char), ios::cur);
			temp = '#';
			fbin.write((char*)&temp, sizeof(char));
			fbin.seekg(fbin.tellg(), ios::beg);
		}
	}
	fbin.close();

	fbin.open("in.txt", ios::binary | ios::in);
	while (fbin.read((char*)&temp, sizeof(char)))
	{
		cout << temp;
	}
	fbin.close();

	return 0;
}