#include <iostream>

using namespace std;

int RecStrLength(char str[])
{
	if (str[0] == '\0')
		return 0;
	return 1+RecStrLength(&str[1]);
}


void main() {
	char s[7] = "Hejsan";
	cout << RecStrLength(s) << endl;
	system("PAUSE");
}