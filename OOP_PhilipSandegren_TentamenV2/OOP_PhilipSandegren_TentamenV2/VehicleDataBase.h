#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "VehicleRegister.h"

using namespace std;

class VehicleDataBase
{
private:
	string RegisterName;
	vector<VehicleRegister>v;
public:
	VehicleDataBase()
	{
		RegisterName=" ";
	}
	void Add(VehicleRegister f)
	{
		v.push_back(f);
	}
	string List()
	{
		ostringstream oss;
		oss << RegisterName << endl;
		for(int i = 0; i < v.size(); ++i)
		{
			oss << v[i] << endl;
		}
		return oss.str();
	}
	void setRegister(string Register)
	{
		this->RegisterName = RegisterName;
	}
};

