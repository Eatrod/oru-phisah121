#include <iostream>
#include <ctime>
#include <conio.h>
#include "Dice.h"

using namespace std;

int main()
{
	char koll;
	int i;
	Dice A;
	cout << "Tryck på enter för att kasta träning!\n";
	do
	{
		A.ThrowDice();
		cout << "----" << "\n" << "! " << A.getNumber() <<" !" << "\n" << "----" <<  endl;
		koll = _getch();
	} while (koll == '\r');
	cin.get();
	return 0;
}