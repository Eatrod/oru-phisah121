#include <iostream>
#include <deque>
#include <array>
#include <map>
#include <sstream>
#include <fstream>
#include "statistics.h"
#include "Watch.h"

using namespace Course;
Watch w;
Course::milliseconds t1;

using namespace std;

//Uppgift 3.1
namespace U31
{
	//a)
	bool palindrome(string s)
	{
		deque<char> palinQuene;
		for (int i = 0; i < s.size(); ++i)
		{
			palinQuene.push_back(s[i]);
		}
		for (int i = 0; i < palinQuene.size()*2; ++i)
		{
			if (palinQuene.front() != palinQuene.back())
			{
				cout << "Ej ett palindrom" << endl;
				return false;
			}
			palinQuene.pop_front();
			palinQuene.pop_back();
			
		}
		cout << "Ett palindrom" << endl;
		return true;
	}
	//b)
	bool palindromeRecursive(string ordet, deque<char> quene, bool first)
	{
		if (first == true)
		{
			for (int i = 0; i < ordet.size(); ++i)
			{
			quene.push_back(ordet[i]);
			}
			first = false;
		}
		if (quene.empty())
		{
			cout << "Ett palindrom" << endl;
			return true;
		}
		else if (quene.front() != quene.back())
		{
			cout << "Ej ett palindrom" << endl;
			return false;
		}
		if (quene.size() == 1)
		{
			cout << "Ett palindrom" << endl;
			return true;
		}
		quene.pop_front();
		quene.pop_back();
		palindromeRecursive(ordet, quene, first);
	}
	void main_3_1()
	{
		cout << "Betyg 3 uppgift 3.1" << endl;
		deque<char> palindromeQuene;
		string palindromString = "andna";
		cout << "---Palindrom test: andna---" << endl;
		U31::palindrome(palindromString);
		U31::palindromeRecursive(palindromString,palindromeQuene,true);
		cout << "---Palindrom test: NATTMÖRKERREKRÖMTTAN---" << endl;
		palindromString = "NATTMÖRKERREKRÖMTTAN";
		U31::palindrome(palindromString);
		U31::palindromeRecursive(palindromString,palindromeQuene,true);
		cout << "---Palindrom test: apagoapa---" << endl;
		palindromString = "apagoapa";
		U31::palindrome(palindromString);
		U31::palindromeRecursive(palindromString,palindromeQuene,true);
	}
}

using namespace statclass;

//Uppgift 3.2
namespace U32
{
	void main_3_2()
	{
		statistics salary;
		salary.main();
	}
}

namespace U33
{
	string readFile()
	{
		map<string,int> wordMap;
		string filnamn;
		string word;
		cout << "Skriv in namnet på filen: ";
		cin >> filnamn;
		ifstream myFile;
		myFile.open(filnamn);
		while (!myFile.eof())
		{
			myFile >> word;
			++wordMap[word];
		}
		int highest = 0;
		for (pair<string,int> x: wordMap) 
		{
			if (x.second > highest)
			{
				highest = x.second;
				word = x.first;
			}
		}
		myFile.close();
		return word;
	}
	void main_3_3()
	{
		cout << readFile() << endl;
	}
}

using namespace U31;
using namespace U32;
using namespace U33;

int main () 
{
	U31:main_3_1();
	U32:main_3_2();
	w.restart();
	U33:main_3_3();
	t1 = w.elapsedMs();
	cout << "Millsekunder: " << t1.count() << endl;
	system("PAUSE");
}