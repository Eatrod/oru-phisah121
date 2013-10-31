#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "Student.h"

using namespace std;

class StudentRegister
{
private:
	string Register;
	vector<Student>v;
public:
	StudentRegister()
	{
		Register=" ";
	}
	void Add(Student s)
	{
		v.push_back(s);
	}
	string List()
	{
		ostringstream oss;
		oss << Register << endl;
		for(int i = 0; i < v.size(); ++i)
		{
			oss << v[i] << endl;
		}
		return oss.str();
	}
	void setRegister(string Register)
	{
		this->Register = Register;
	}
	void write_2File(string filename)
	{
		ofstream fout(filename);
		fout << "Studentregister=" << Register << endl;
		for (auto &s : v)
		{
			fout << "Student" << s << endl;
		}
		fout.close();
	}
	
	friend ostream& operator<<(ostream& fout,StudentRegister& sr)
	{
		fout << "Studentregister=" << sr.Register << endl;
		for (auto &a : sr.v)
		{
			fout << "Register" << a << endl;
		}
		return fout;
	}

	void readFromFile (string fileName)
	{
		string str,strrow;
		ifstream fin;
		try
		{
			fin.open(fileName);
			v.clear();
			while (std::getline(fin,strrow))
			{
				istringstream iss(strrow);
				getline(iss,str,'=');
				if(str == "Studentregister")
				{
					getline(iss,this->Register);
				}
				else if(str.compare("Student") == 0)
				{
					Student s;
					iss >> s;
					if(s.getEnrollmentYear() != -1)
						v.push_back(s);
				}
				fin.close();
			}
			
		}
		catch (exception e)
		{
			cerr << "Exception: " << fileName << endl;
			cerr << e.what() << endl;
		}

	}
};

