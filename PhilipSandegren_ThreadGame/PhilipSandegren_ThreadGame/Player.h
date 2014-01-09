#pragma once
#include <Windows.h>

using namespace std;

class Player
{
private:
	char knapp;
public:
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void player1ButtonPress(char _getch, int x, int y)
	{
		knapp = _getch;
		if (knapp = 'w')
		{
			cout << ' ';
			gotoxy(x + 6, y);
			cout << '1';
		}
		else if (knapp = 's')
		{
			cout << ' ';
			gotoxy(x - 6, y);
			cout << '1';
		}
		else if (knapp = 'a')
		{
			cout << ' ';
			gotoxy(x, y - 6);
			cout << '1';
		}
		else if (knapp = 'd')
		{
			cout << ' ';
			gotoxy(x, y + 6);
			cout << '1';
		}
	}

	void player2ButtonPress(char _getch, int x, int y)
	{
		knapp = _getch;
		if (knapp = 'w')
		{
			cout << ' ';
			gotoxy(x + 6, y);
			cout << '2';
		}
		else if (knapp = 's')
		{
			cout << ' ';
			gotoxy(x - 6, y);
			cout << '2';
		}
		else if (knapp = 'a')
		{
			cout << ' ';
			gotoxy(x, y - 6);
			cout << '2';
		}
		else if (knapp = 'd')
		{
			cout << ' ';
			gotoxy(x, y + 6);
			cout << '2';
		}

	}
	Player(void)
	{
	}

	~Player(void)
	{
	}
};

