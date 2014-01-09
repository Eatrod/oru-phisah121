#pragma once
#include <Windows.h>

using namespace std;

class Player
{
private:
	char knapp;
	int x;
	int y;
public:
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void player1ButtonPress(char getch)
	{
		knapp = getch;
		if (knapp == 'w')
		{
			gotoxy(x - 1, y);
			cout << ' ';
			gotoxy(x + 6, y);
			x += 6;
			cout << '1';
		}
		else if (knapp == 's')
		{
			cout << ' ';
			gotoxy(x - 6, y);
			cout << '1';
		}
		else if (knapp == 'a')
		{
			cout << ' ';
			gotoxy(x, y - 6);
			cout << '1';
		}
		else if (knapp == 'd')
		{
			cout << ' ';
			gotoxy(x, y + 6);
			cout << '1';
		}
	}

	void player2ButtonPress(char getch)
	{
		knapp = getch;
		if (knapp = 'i')
		{
			cout << ' ';
			gotoxy(x + 6, y);
			cout << '2';
		}
		else if (knapp = 'k')
		{
			cout << ' ';
			gotoxy(x - 6, y);
			cout << '2';
		}
		else if (knapp = 'j')
		{
			cout << ' ';
			gotoxy(x, y - 6);
			cout << '2';
		}
		else if (knapp = 'l')
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

