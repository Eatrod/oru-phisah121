#pragma once
#include <iostream>

using namespace std;

class Byggnad
{
public:
	Byggnad(void);
	~Byggnad(void);
void ny_byggnad()
{
	cout << "Skriv hur många våningar: " << endl;
	cin >> vaningar;
	cout << "Skriv hur många rum: " << endl;
	cin >> antal_rum;
	cout << "Skriv hur stor area: " << endl;
	cin >> ytArea;
}
void skriv_byggnad()
{
	cout << "Byggnaden har: " << this->vaningar << " våningar." << endl;
	cout << "Byggnaden har: " << this->antal_rum << " rum." << endl;
	cout << "Byggnaden har: " << this->ytArea << " stor area." << endl;
}
private:
	int vaningar;
	int antal_rum;
	float ytArea;
};

class Hus : public Byggnad
{
public:

void nytt_hus()
{
	cout << "Skriv hur många rum: " << endl;
	cin >> antal_rum;
	cout << "Skriv hur många badrum: " << endl;
	cin >> antal_badrum;
}
void skriv_hus()
{
	cout << "Huset har: " << this->antal_rum << " rum." << endl;
	cout << "Huset har: " << this->antal_badrum << " badrum." << endl;
}
private:
	int antal_rum;
	int antal_badrum;
};

class Kontor : public Byggnad
{
public:

void nytt_kontor()
{
	cout << "Skriv hur många brandvarnare: " << endl;
	cin >> antal_brandvarnare;
	cout << "Skriv hur många telefoner: " << endl;
	cin >> antal_telefoner;
}
void skriv_kontor()
{
	cout << "Kontoret har: " << this->antal_brandvarnare << " brandvarnare." << endl;
	cout << "Kontoret har: " << this->antal_telefoner<< " telefoner." << endl;
}
private:
	int antal_brandvarnare;
	int antal_telefoner;
};