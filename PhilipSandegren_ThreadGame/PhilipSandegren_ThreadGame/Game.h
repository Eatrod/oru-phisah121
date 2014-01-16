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
	mutex mutex_keyboard;
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
				std::cout << "-";
			}
			std::cout << "\n";
			for (int i = 0; i < 12; ++i)
			{
				std::cout << "|     ";
			}
			std::cout << "\n";
			for (int i = 0; i < 67; ++i)
			{
				std::cout << "-";
			}
			std::cout << "\n";
		}
	}

	//Förflyttar aktuell spelare
	void movePlayer(char getch)
	{
		if (whichPlayer(getch) == true)
			keyQueue1.push_back(getch);
		else
			keyQueue2.push_back(getch);
		mutex_keyboard.lock();
		if (whichPlayer(getch) == true)
		{
			p1();
		}
		else
		{
			p2();
		}
		mutex_keyboard.unlock();
	}
	void operator ()()
	{
		while ( true )
		{
			thePlayer = playerQueue.front();
			playerQueue.pop_front();
			gotoxy(thePlayer.x, thePlayer.y);
			if (thePlayer.id == 1)
			{
				cout << '1';
			}
			else
			{
				cout << '2';
			}
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}
	void GameMain()
	{
		thread player1(p1), player2(p2);
		drawGameField();
		player1.join();
		player2.join();
		do {
		if (_kbhit())
		{
			knapp = _getch();
			if (whichPlayer(knapp) == true)
				movePlayer(knapp);
			else
				movePlayer(knapp);
		}
	} while (true);
	}
	
	//Avgör om spelare 1 eller 2 tryckte på tangetbordet
	bool whichPlayer(char enKnapp)
	{
		if (knapp == 'w' || knapp == 'a' || knapp == 's' || knapp == 'd')
			return true;
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

