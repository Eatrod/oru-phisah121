#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"

using namespace std;

int main () {
	cout << "Skriv in fakta om en bil";
	Car c1;
	c1.GetBrand();
	c1.GetPrice();
	c1.GetYear();
}