#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "Vehicle.h"

using namespace std;

void main()
{
	cout << "BETYG 4" << endl;
	Vehicle v;
	v.setBrand("SUP");
	cout << v.getBrand() << endl;
	v.setRepairDate("2013-05-11");
	cout << v.getRepairDate() << endl;
	system("PAUSE");
}