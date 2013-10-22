#pragma once
#include <string>
#include <time.h>

using namespace std;

class Dice
{
public:
	Dice()
	{
		dicenumber = ThrowDice();
	}
	int getNumber()
	{
		return dicenumber;
	}
	int ThrowDice()
	{
		dicenumber = rand()%6+1;
		return dicenumber;
	}
private:
	int dicenumber;
};

