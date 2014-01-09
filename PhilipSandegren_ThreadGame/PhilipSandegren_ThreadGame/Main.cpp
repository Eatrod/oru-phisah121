#include "Game.h"
#include "Player.h"

using namespace std;

int main() {
	char knapp;
	Game object;
	object.drawGameField();
	do {
	if (_kbhit())
		{
		knapp = _getch();
		object.movePlayer(knapp);
		}
	} while (true);
	system("PAUSE");
}