#pragma once
#include <Windows.h>
#include <thread>
#include <mutex>

using namespace std;

//Struct f�r att kunna skicka med spelaren x,y koordinat samt vilken spelare till game tr�den via k�n
struct playerInfo {
	int x;
	int y;
	int id;
};

mutex mutex_queue;
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
	//Den ber�mda gotoxy f�r att flytta mark�ren i konsoll f�nster
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	//Tar bort spelarens gamla figur p� gamla positionen
	void goClear(int x, int y)
	{
		gotoxy(x,y);
		cout << ' ';
	}

	void operator()() //DETTA �R FUNKTIONEN SOM EXEKVERAS I EN TR�D
	{
		while ( true )
		{
			//L�ser f�rsta tangeten i tangentk�n
			if (!key->empty())
				knapp = key->front();
			if (!key->empty())
				key->pop_front();
			//Spelare 1's knappar
			if (knapp == 'w')
			{
				if (y > 1) 
				{
					goClear(x,y);
					y -= 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
					
				}
			}
			else if (knapp == 's')
			{
				if (y < 19)
				{
					goClear(x,y);
					y += 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
				}
			}
			else if (knapp == 'a')
			{
				if (x > 3)
				{
					goClear(x,y);
					x -= 6;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
				}
			}
			else if (knapp == 'd')
			{
				if (x < 60) 
				{
					goClear(x,y);
					x += 6;
				    newPlayer.x = x; newPlayer.y = y; newPlayer.id = 1;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
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
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
				}
			}
			else if (knapp == 'k')
			{
				if (y < 19)
				{
					goClear(x,y);
					y += 3;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
				}
			}
			else if (knapp == 'j')
			{
				if (x > 3)
				{
					goClear(x,y);
					x -= 6;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
				}
			}
			else if (knapp == 'l')
			{
				if (x < 60) 
				{
					goClear(x,y);
					x += 6;
					newPlayer.x = x; newPlayer.y = y; newPlayer.id = 2;
					mutex_queue.lock();
					pos->push_back(newPlayer);
					mutex_queue.unlock();
				}
			}
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}
	
	Player(void)
	{
		this->x = 3;
		this->y = 1;
	}
	//Konstruktor med pekare till alla k�er
	Player(deque<char> *k, deque<playerInfo> *p)
	{
		key=k;
		pos=p;
	}


	~Player(void)
	{
	}
};

