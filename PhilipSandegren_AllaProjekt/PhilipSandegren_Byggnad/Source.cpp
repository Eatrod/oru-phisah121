#include <iostream>
#include "Byggnad.h"

using namespace std;

int main () {
	Byggnad b1;
	Hus h1;
	Kontor k1;
	b1.ny_byggnad();
	k1.nytt_kontor();
	h1.nytt_hus();
	b1.skriv_byggnad();
	k1.skriv_kontor();
	h1.skriv_hus();
	system("PAUSE");
}