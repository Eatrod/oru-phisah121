//PhilipSandegren_DungeonCrawl
//Skapad av Philip Sandegren
//Objektorienterad programmering instuderingsuppgift

#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <stdlib.h> 
#include <ctime>
#include "dungeonmap.h"

using namespace std;

int main(void) {
	//Initerar variabler
	char spela = 'j';
	//En do f�r att spelaren ska kunna spela igen utan att starta om
	do {
	//Klocka f�r att h�lla koll p� hur snabb du �r
	clock_t start;
	clock_t end;
	char knapp;
	int posX = 3, posY = 1;
	bool lose = false,win = false;
	float total;
	dungeonmap main;
	main.clearscreen();
	//L�ser in alla funktioner fr�n klassen
	main.drawMap();
	main.drawObjects();
	main.gotoxy(posX,posY);
	cout << 'P';
	start = clock();
	//Loop som k�rs tills spelaren landar p� en f�lla eller m�l.
	do
	{
		//L�ser av knapptryck
		if (_kbhit())
		{
			knapp = _getch();
			if(knapp == 'd')
			{
				//Ligger till en koll s� anv�ndaren r�r sig innanf�r spelplanen
				if(posX < 60)
				{
					main.goClear(posX,posY);
					main.goRight(posX, posY);
					posX += 6;
					if(lose = main.onTrap(posX,posY) == true)
						break;
					if(win = main.onGoal(posX,posY) == true)
						break;
					cout << "P";
				}
					
			}

			if(knapp == 's')
			{
				//Ligger till en koll s� anv�ndaren r�r sig innanf�r spelplanen
				if(posY < 19)
				{
					main.goClear(posX,posY);
					main.goDown(posX, posY);
					posY += 3;
					if(lose = main.onTrap(posX,posY) == true)
						break;
					if(win = main.onGoal(posX,posY) == true)
						break;
					cout << "P";
				}

			}

			if(knapp == 'a')
			{
				//Ligger till en koll s� anv�ndaren r�r sig innanf�r spelplanen
				if(posX > 3)
				{
					main.goClear(posX,posY);
					main.goLeft(posX, posY);
					posX -= 6;
					if(lose = main.onTrap(posX,posY) == true)
						break;
					if(win = main.onGoal(posX,posY) == true)
						break;
					cout << "P";
				}
			}

			if(knapp == 'w')
			{
				//Ligger till en koll s� anv�ndaren r�r sig innanf�r spelplanen
				if(posY > 1)
				{
					main.goClear(posX,posY);
					main.goUp(posX, posY);
					posY -= 3;
					if(lose = main.onTrap(posX,posY) == true)
						break;
					if(win = main.onGoal(posX,posY) == true)
						break;
					cout << "P";
				}

			}
		}
	} while(lose == false || win == false);
	//Avslutar klockan och rensar sk�rmen
	end = clock();
	total = end-start;
	main.clearscreen();
	//Kollar om spelaren vann eller f�rlorade och skriver ut tiden
	if (win == true)
		cout << "Grattis du vann p�; " << total/CLOCKS_PER_SEC << " sekunder" << endl;
	if (lose == true)
		cout << "Du f�rlorade! Alldeles f�r d�lig p� datorspel" << endl;
	cout << "Skriv in j f�r att avsluta och t f�r att spela igen" << endl;
	cin >> spela;
	//Skriver spelaren in j avslutas programmet om t s� spela igen
	if (spela == 'j')
		break;
	} while (spela == 't');
}