#pragma once
#include <iostream>
#include <string>

using namespace std;

class Multimedia
{
public:
	Multimedia(void);
	~Multimedia(void);
	void las_objekt()
	{
		cout << "Skriv objektets titel: ";
		cin >> titel;
		cout << "Skriv objektets l�ngd: ";
		cin >> langd;
		cout << "Skriv objektets genr�: ";
		cin >> genre;
	}
private:
	string titel;
	int langd;
	string genre;
};

class Music:public Multimedia
{
public:
	Music(void);	
private:
		vector<string>title;
		vector<int>length;
};

class Bok:public Multimedia
{
public:
	Bok(void);
private:
};

class Movie:public Multimedia
{
public:
	Movie();
private:
	vector<string>actors;
};