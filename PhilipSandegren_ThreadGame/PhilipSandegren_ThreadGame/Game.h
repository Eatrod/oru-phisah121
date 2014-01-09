#pragma once

#include <conio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include "Player.h"

using namespace std;

class Game
{
private:
	thread player1(), player2();
	Player p1, p2;
	mutex mutex_cout;
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
		p1.player1ButtonPress(getch);
	}
	Game(void)
	{
	}

	~Game(void)
	{
	}
};

