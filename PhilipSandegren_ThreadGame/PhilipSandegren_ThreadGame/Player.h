#pragma once
#include <Windows.h>

using namespace std;

class Player
{
private:
	char knapp;
	int x;
	int y;
	deque<int> pos;
public:
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	void goClear(int x, int y)
	{
		gotoxy(x,y);
		cout << ' ';
	}
	void goRight(int x, int y)
	{
		gotoxy(x+6, y);
	}
	//Flyttar spelaren åt vänster
	void goLeft(int x, int y)
	{
		gotoxy(x-6, y);
	}
	//Flyttar spelaren uppåt
	void goUp(int x, int y)
	{
		gotoxy(x, y-3);
	}
	//Flyttar spelaren neråt
	void goDown(int x, int y)
	{
		gotoxy(x, y+3);
	}
	void player1ButtonPress(char getch)
	{
		knapp = getch;
		if (knapp == 'w')
		{
			if (y > 1) 
			{
				goClear(x,y);
				goUp(x,y);
				y -= 3;
				cout << '1';
			}
		}
		else if (knapp == 's')
		{
			if (y < 19)
			{
				goClear(x,y);
				goDown(x,y);
				y += 3;
				cout << '1';
			}
		}
		else if (knapp == 'a')
		{
			if (x > 3)
			{
				goClear(x,y);
				goLeft(x,y);
				x -= 6;
				cout << '1';
			}
		}
		else if (knapp == 'd')
		{
			if (x < 60) 
			{
				goClear(x,y);
				goRight(x,y);
				x += 6;
				cout << '1';
			}
		}
	}

	void player2ButtonPress(char getch)
	{
		knapp = getch;
		if (knapp == 'i')
		{
			if (y > 1) 
			{
				goClear(x,y);
				goUp(x,y);
				y -= 3;
				cout << '2';
			}
		}
		else if (knapp == 'k')
		{
			if (y < 19)
			{
				goClear(x,y);
				goDown(x,y);
				y += 3;
				cout << '2';
			}
		}
		else if (knapp == 'j')
		{
			if (x > 3)
			{
				goClear(x,y);
				goLeft(x,y);
				x -= 6;
				cout << '2';
			}
		}
		else if (knapp == 'l')
		{
			if (x < 60) 
			{
				goClear(x,y);
				goRight(x,y);
				x += 6;
				cout << '2';
			}
		}

	}
	int getX() {return this->x;}
	int getY() {return this->y;}
	Player(void)
	{
		x = 3;
		y = 1;
	}

	~Player(void)
	{
	}
};

