#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "Repaired.h"

using namespace std;


class Vehicle : public Repaired
{
	protected:
	string brand;
	int year;
	double purchasingPrice;
	double sellingPrice;
public:
	Vehicle(): brand(" "), year(0), purchasingPrice(0),sellingPrice(0) 
	{
	}
	Vehicle(string brand, int year, double purchasingPrice, double sellingPrice) : brand(brand),year(year),purchasingPrice(purchasingPrice), sellingPrice(sellingPrice)
	{
	}
	string getBrand() {return brand;}
	void setBrand(string Brand) {brand = Brand;}

	int getYear() {return year;}
	void setYear(int Year) {year = Year;}

	double getPurchasingPrice() {return purchasingPrice;}
	void setPurchasingPrice(double PurchasingPrice) {purchasingPrice = PurchasingPrice;}

	double getSellingPrice() {return sellingPrice;}
	void setSellingPrice(double SellingPrice) {sellingPrice = SellingPrice;}

	void Read()
	{
		cout << "Brand = " << endl;
		cin >> brand;
		cout << "Year = " <<  endl;
		cin >> year;
		cout << "Purchasing price = " << endl;
		cin >> purchasingPrice;
		cout << "Selling price = " << endl;
		cin >> sellingPrice;
	}
	void Service()
	{
		cout << "Repair date = " << endl;
		cin >> repairDate;
		cout << "Type of service = " << endl;
		cin >> whatFixed;
	}

	void deleteVehicle()
	{
		delete(this);
	}

	friend ostream& operator<<(ostream &o,const Vehicle&f)
	{
		o << "(" << f.brand << "," << f.year << "," << f.purchasingPrice << ")";
		return o;
	}
};

