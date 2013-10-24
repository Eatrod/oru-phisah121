#pragma once
#include <string>
#include <iostream>
using namespace std;
class Car
{
public:
	Car()
	{
		GetBrand();
		GetYear();
		GetPrice();
	}
	void GetCar(string Car)
	{
		cout << Car.brand;
		cout << carname.year;
		cout << carname.price;
	}
	string GetBrand()
	{
		cin >> brand;
		cout << "Du skrev:" << brand << "\n";
		return brand;
	}
	int GetYear()
	{
		cin >> year;
		cout << "Du skrev:" << year << "\n";
		return year;
	}
	double GetPrice()
	{
		cin >> price;
		cout << "Du skrev:" << price << "\n";
		return price;
	}
private:
	string brand;
	int year;
	double price;
};

