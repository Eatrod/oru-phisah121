#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string fornamn,efternamn;
	cout << "Skriv ditt förnamn: ";
	cin >> fornamn;
	cout << "Skriv ditt efternamn: ";
	cin >> efternamn;
	cout << "Ditt namn är: " << fornamn << " " << efternamn;
	cin.get();
}