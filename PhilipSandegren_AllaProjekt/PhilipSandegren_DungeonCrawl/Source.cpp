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
	//En do för att spelaren ska kunna spela igen utan att starta om
	do {
	//Klocka för att hålla koll på hur snabb du är
	clock_t start;
	clock_t end;
	char knapp;
	int posX = 3, posY = 1;
	bool lose = false,win = false;
	float total;
	dungeonmap main;
	main.clearscreen();
	//Läser in alla funktioner från klassen
	main.drawMap();
	main.drawObjects();
	main.gotoxy(posX,posY);
	cout << 'P';
	start = clock();
	//Loop som körs tills spelaren landar på en fälla eller mål.
	do
	{
		//Läser av knapptryck
		if (_kbhit())
		{
			knapp = _getch();
			if(knapp == 'd')
			{
				//Ligger till en koll så användaren rör sig innanför spelplanen
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
				//Ligger till en koll så användaren rör sig innanför spelplanen
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
				//Ligger till en koll så användaren rör sig innanför spelplanen
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
				//Ligger till en koll så användaren rör sig innanför spelplanen
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
	//Avslutar klockan och rensar skärmen
	end = clock();
	total = end-start;
	main.clearscreen();
	//Kollar om spelaren vann eller förlorade och skriver ut tiden
	if (win == true)
		cout << "Grattis du vann på; " << total/CLOCKS_PER_SEC << " sekunder" << endl;
	if (lose == true)
		cout << "Du förlorade! Alldeles för dålig på datorspel" << endl;
	cout << "Skriv in j för att avsluta och t för att spela igen" << endl;
	cin >> spela;
	//Skriver spelaren in j avslutas programmet om t så spela igen
	if (spela == 'j')
		break;
	} while (spela == 't');
}