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
	deque<char> key;
	char knapp;
public:
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
	//Kollar om aktuell spelare är utanför spelplanen
	bool outsideCheck()
	{
	}
	//Förflyttar aktuell spelare
	void movePlayer(char getch)
	{
		key.push_back(getch);
		mutex_keyboard.lock();
		p1.player1ButtonPress(getch);
		p2.player2ButtonPress(getch);
		mutex_keyboard.unlock();
	}
	void GameMain()
	{
		thread player1, player2;
		drawGameField();
		player1.join();
		player2.join();
		do {
		if (_kbhit())
		{
			knapp = _getch();
			if (whichPlayer(knapp) == true)
				player1(movePlayer, knapp);
			else
				player2(movePlayer, knapp);
		}
	} while (true);
	}
	
	bool whichPlayer(char enKnapp)
	{
		if (knapp == 'w' || knapp == 'a' || knapp == 's' || knapp == 'd')
			return true;
	}

	Game(void)
	{

	}

	~Game(void)
	{
	}
};

