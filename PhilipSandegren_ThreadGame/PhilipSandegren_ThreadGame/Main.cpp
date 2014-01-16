#include "Game.h"
#include "Player.h"

using namespace std;

struct playerInfo {
	int x;
	int y;
	int id;
};

deque<char> keyQueue1;
deque<char> keyQueue2;
deque<playerInfo> playerQueue;

int main() {
	Game mainCall(&keyQueue1,&keyQueue2,&playerQueue);
	Player p1(&keyQueue1,&playerQueue), p2(&keyQueue2,&playerQueue);
	mainCall.GameMain();
	system("PAUSE");
}