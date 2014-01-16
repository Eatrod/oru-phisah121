#include "Game.h"
#include "Player.h"

using namespace std;

deque<char> keyQueue1;
deque<char> keyQueue2;
deque<playerInfo> playerQueue;

int main() {
	Game mainCall(&keyQueue1,&keyQueue2,&playerQueue);
	Player p1(&keyQueue1,&playerQueue), p2(&keyQueue2,&playerQueue);
	thread tp1(p1); thread tp2(p2);
	mainCall.GameMain();
	tp1.join();
	tp2.join();
	system("PAUSE");
}