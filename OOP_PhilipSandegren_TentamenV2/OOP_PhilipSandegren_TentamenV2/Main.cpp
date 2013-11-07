#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "Vehicle.h"
#include "VehicleRegister.h"
#include "VehicleDataBase.h"

using namespace std;

void main()
{
	cout << "BETYG 4" << endl;
	int check = 0;
	Vehicle v;
	VehicleRegister vr;
	VehicleDataBase vd;
	while (check != 7) {
		cout << "1 = Nytt fordon" << endl;
		cout << "2 = Tabort fordon" << endl;
		cout << "3 = Lägg till reparation" << endl;
		cout << "4 = Nytt Dotterbolag" << endl;
		cout << "5 = Aktivit register" << endl;
		cout << "6 = Sök efter fordon" << endl;
		cout << "7 = Avsluta" << endl;
		cin >> check;
		if (check == 1)
		{
			Vehicle v;
			v.Read();
		}
		if (check == 2)
		{
			v.deleteVehicle();
		}
		if (check == 3)
		{
			v.Service();
		}
		if (check == 4)
		{
			string namn;
			VehicleRegister vr;
			cout << "Skriv företagets namn" << endl;
			cin >> namn;
			vr.setCompanyName(namn);
		}
		if (check == 5)
		{
			string registerVal;
			cout << "Skriv in namnet på registret du vill jobba med" << endl;
			cin >> registerVal;
			vr.setRegister(registerVal);
		}
		if (check == 6)
		{
			vd.registerSearch("volvo","1984");
		}
		if (check == 7)
		{
			break;
		}
	}
}