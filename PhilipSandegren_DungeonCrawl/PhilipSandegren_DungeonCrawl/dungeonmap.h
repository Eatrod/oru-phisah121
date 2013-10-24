#pragma once
#include <iostream>
#include <Windows.h>
#include <array>

using namespace std;

class dungeonmap
{
public:
	dungeonmap(void);
	//Ritar ut spelplanen utan fiender
	void drawMap()
	{
		//Initerar matrisen med blank tecken
		for (int i=0; i<drawGrid.size(); i++)
		{
			for (int j = 0; j < drawGrid[i].size(); j++)
			{
				drawGrid[i][j] = ' ';
			}
		}
		//Ritar ut spelplanen
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
	//Konverterar koordintaer till grid
	int gridPos(int x, int y)
	{
		y = floor(y/3)+1;
		x = floor(x*6)-1;
		return x,y;
	}
    //Rensar skärmen
	void clearscreen()
	{
		gotoxy(0,0);
		for (int i = 0; i<3000; ++i)
		{
			cout << ' ';
		}
		gotoxy(0,0);
	}
	//Ritar alla fällor och målet
	void drawObjects()
	{
		int a = 0;
		gotoxy(63,19);
		drawGrid[7][11] = 'G';
		cout << 'G';
		gotoxy(57,19);
		drawGrid[7][10] = 'T';
		cout << 'T';
		gotoxy(57,13);
		drawGrid[5][10] = 'T';
		cout << 'T';
		//Använder for loopar för att skriva ut fler fällor på samma rad
		for (int i = 1; i < 7; ++i)
		{
			gotoxy(9,i+a);
			drawGrid[i][2] = 'T';
			cout << 'T';
			a += 2;
		}
		a = 0;
		for (int i = 1; i < 7; ++i)
		{
			gotoxy(21,3+i+a);
			drawGrid[i+1][4] = 'T';
			cout << 'T';
			a += 2;
		}
		a = 0;
		for (int i = 1; i < 7; ++i)
		{
			gotoxy(26+i+a,4);
			drawGrid[2][i+4] = 'T';
			cout << 'T';
			a += 5;
		}
		a = 0;
		for (int i = 1; i < 7; ++i)
		{
			gotoxy(32+i+a,10);
			drawGrid[4][i+5] = 'T';
			cout << 'T';
			a += 5;
		}
		a = 0;
		for (int i = 1; i < 3; ++i)
		{
			gotoxy(33,12+i+a);
			drawGrid[i+4][6] = 'T';
			cout << 'T';
			a += 2;
		}
		a = 0;
		for (int i = 1; i < 3; ++i)
		{
			gotoxy(45,15+i+a);
			drawGrid[i+5][8] = 'T';
			cout << 'T';
			a += 2;
		}
	}	
	//Tar bort spelarens gamla position
	void goClear(int x, int y)
	{
		gotoxy(x,y);
		cout << ' ';
	}
	//Flyttar spelaren åt höger
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
	//Kollar om spelaren befinner sig på en fälla
	bool onTrap(int x,int y)
	{
		trapCheck = false;
		if (drawGrid[floor(y/3)+1][floor(x/6)+1] == 'T')
			trapCheck = true;
		return trapCheck;
	}
	//Kollar om spelaren tagit sig i mål
	bool onGoal(int x, int y)
	{
		goalCheck = false;
		if (drawGrid[floor(y/3)+1][floor(x/6)+1] == 'G')
			goalCheck = true;
		return goalCheck;
	}
	//Ställer pekaren vid vissa koordinater så rätt sak kan ritas på rätt plats
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	~dungeonmap(void);
private:
	bool trapCheck;
	bool goalCheck;
	//Yttre är rader inre kolumner +1 riktig storlek (7,11)
	array<array<char,12>, 8> drawGrid;
};

