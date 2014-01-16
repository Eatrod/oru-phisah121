#pragma once
#include <Windows.h>
#include <thread>
#include "Game.h"

using namespace std;

struct playerInfo {
	int x;
	int y;
	int id;
};

class Player
{
private:
	char knapp;
	int x;
	int y;
	playerInfo newPlayer;
	deque<char> *key; 
	deque<playerInfo> *pos;

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

	void player1ButtonPress(char getch)
	{

	}

	void operator()() //DETTA ÄR FUNKTIONEN SOM EXEKVERAS I EN TRÅD
	{
		while ( true )
		{
			char knapp = '0';
			//Läs teckenkö för 
			knapp = key->front();
			if (!key->empty())
				key->pop_front();
			if (knapp == 'w')
			{
				if (y > 1) 
				{
					goClear(x,y);
					y -= 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					pos->push_back(newPlayer);
					
				}
			}
			else if (knapp == 's')
			{
				if (y < 19)
				{
					goClear(x,y);
					y += 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					pos->push_back(newPlayer);
					
				}
			}
			else if (knapp == 'a')
			{
				if (x > 3)
				{
					goClear(x,y);
					x -= 6;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					pos->push_back(newPlayer);
					
				}
			}
			else if (knapp == 'd')
			{
				if (x < 60) 
				{
					goClear(x,y);
					x += 6;
				    newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					pos->push_back(newPlayer);
					
				}
			}
			//Spelare 2's knappar
			if (knapp == 'i')
			{
				if (y > 1) 
				{
					goClear(x,y);
					y -= 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					pos->push_back(newPlayer);
					
				}
			}
			else if (knapp == 'k')
			{
				if (y < 19)
				{
					goClear(x,y);
					y += 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					pos->push_back(newPlayer);
					
				}
			}
			else if (knapp == 'j')
			{
				if (x > 3)
				{
					goClear(x,y);
					x -= 6;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					pos->push_back(newPlayer);
					
				}
			}
			else if (knapp == 'l')
			{
				if (x < 60) 
				{
					goClear(x,y);
					x += 6;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					pos->push_back(newPlayer);
					
				}
			}
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}

	int getX() {return this->x;}
	int getY() {return this->y;}
	
	Player(void)
	{
		x = 3;
		y = 1;
	}
	
	Player(deque<char> *k, deque<playerInfo> *p)
	{
		key=k;
		pos=p;
	}


	~Player(void)
	{
	}
};

