#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string fornamn,efternamn;
	cout << "Skriv ditt f�rnamn: ";
	cin >> fornamn;
	cout << "Skriv ditt efternamn: ";
	cin >> efternamn;
	cout << "Ditt namn �r: " << fornamn << " " << efternamn;
	cin.get();
}