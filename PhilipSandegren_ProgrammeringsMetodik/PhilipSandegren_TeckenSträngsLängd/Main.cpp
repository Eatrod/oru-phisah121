#include <iostream>

using namespace std;

int RecStrLength(char str[])
{
	int i = 0;
	if (str[0] == '\0')
		return 0;
	i += str[i];
	++i;
	RecStrLength(&str[i]);
	return i;
}


void main() {
	char s[8] = "Hejsan";
	cout << RecStrLength(s) << endl;
	system("PAUSE");
}