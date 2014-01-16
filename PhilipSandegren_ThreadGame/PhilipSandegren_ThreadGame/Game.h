#pragma once

#include <conio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include "Player.h"

using namespace std;

class Game
{
private:
	Player p1, p2;
	mutex mutex_queue;
	char knapp;
	deque<char> *key1;
	deque<char> *key2;
	deque<playerInfo> *pos;
	playerInfo thePlayer;
public:
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void drawGameField()
	{
		for (int a = 0; a<7; ++a)
		{
			for (int i = 0; i < 67; ++i)
			{
				cout << "-";
			}
			cout << "\n";
			for (int i = 0; i < 12; ++i)
			{
				cout << "|     ";
			}
			cout << "\n";
			for (int i = 0; i < 67; ++i)
			{
				cout << "-";
			}
			cout << "\n";
		}
	}

	//Förflyttar aktuell spelare
	void movePlayer(char getch)
	{
		mutex_queue.lock();
		if (whichPlayer(getch) == true)
		{
			key1->push_back(getch);
		}
		else
		{
			key2->push_back(getch);
		}
		mutex_queue.unlock();

		thePlayer = pos->front();
		if (!pos->empty())
			pos->pop_front();
		gotoxy(thePlayer.x, thePlayer.y);
		if (thePlayer.id == 1)
		{
			std::cout << '1';
		}
		else
		{
			std::cout << '2';
		}
	}

	void GameMain()
	{
		drawGameField();
		do {
			if (_kbhit())
			{
				knapp = _getch();
				movePlayer(knapp);
			}
		} while (true);
	}
	
	//Avgör om spelare 1 eller 2 tryckte på tangetbordet
	bool whichPlayer(char enKnapp)
	{
		if (knapp == 'w' || knapp == 'a' || knapp == 's' || knapp == 'd')
			return true;
		else
			return false;
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
	Game(void)
	{

	}
	
	Game(deque<char> *k1, deque<char> *k2, deque<playerInfo> *p)
	{
		key1=k1;
		key2=k2;
		pos=p;
	}

	~Game(void)
	{
	}
};

