#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "Vehicle.h"

using namespace std;

class VehicleRegister
{
private:
	string Register;
	string companyName;
	vector<Vehicle>v;
public:
	VehicleRegister()
	{
		Register=" ";
	}
	void Add(Vehicle f)
	{
		v.push_back(f);
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
	
	friend ostream& operator<<(ostream& fout,VehicleRegister& vr)
	{
		fout << "Vehicleregister=" << vr.Register << endl;
		for (auto &a : vr.v)
		{
			fout << "Register" << a << endl;
		}
		return fout;
	}
	
	
	void AddVehicle()
	{
		Vehicle f;
		f.Read();
		Add(f);
	}
	void DeleteVehicle(Vehicle f)
	{
		
	}
	void AddService(Vehicle f)
	{
		f.Service();
	}
};

