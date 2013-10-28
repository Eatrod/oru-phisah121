#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Article
{
protected:
	int id;
	string date;
	string title;
	string writer;
	int n;
	string keyword;
public:
	Article(): id(0),date(" "),title(" "), writer(" "), n(0),keyword(" ")
	{
	}
	Article(int id,string date,string title, string writer, int n,string keyword) : id(id),date(date),title(title),writer(writer),n(n),keyword(keyword)
	{
	}
	int GetId() {return id;}
	void SetId(int id) {this->id;}
	string GetDate() {return date;}
	void SetDate(string date) {this->date;}
	string GetTitle() {return title;}
	void SetTitle(string title) {this->title;}
	string GetWriter() {return writer;}
	void SetWriter(string writer) {this->writer;}
	int GetN() {return n;}
	void SetN(int n) {this->n;}
	string GetKeyword() {return keyword;}
	void SetKeyword(string keyword) {this->keyword;}
	
	void Write()
	{
		cout << "id = " << id << endl;
		cout << "Datum = " << date << endl;
		cout << "Titel = " << title << endl;
		cout << "Författare = " << writer << endl;
		cout << "N = " << n << endl;
		cout << "Nyckelord = " << keyword << endl;
	}
	void Read()
	{
		cout << "id = "<< endl;
		cin >> id;
		cout << "Datum = "<< endl;
		cin >> date;
		cout << "Titel = "<< endl;
		cin >> title;
		cout << "Författare = "<< endl;
		cin >> writer;
		cout << "N = "<< endl;
		cin >> n;
		cout << "Nyckelord = "<< endl;
		cin >> keyword;
	}
	friend ostream& operator<<(ostream &o,const Article&a)
	{
		o << "(" << a.id << "," << a.date << "," << a.title << "," << a.writer << "," << a.n << "," << a.keyword << ")";
		return o;
	}
	friend istream& operator>>(istream& in, Article&a)
	{
		string s;
		std::getline(in,s,"(");
		in>>a.id;
		std::getline(in,s,",");
		in>>a.date;
		std::getline(in,s,",");
		in>>a.title;
		std::getline(in,s,",");
		in>>a.writer;
		std::getline(in,s,",");
		in>>a.n;
		std::getline(in,s,")");
		in>>a.keyword;
		return in;
	}

};

