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
	while (check != 7) {
		cout << "1 = Nytt fordon" << endl;
		cout << "2 = Tabort fordon" << endl;
		cout << "3 = Lägg till reparation" << endl;
		cout << "4 = Nytt register objekt" << endl;
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
			Vehicle v;
		}
		if (check == 3)
		{
			Vehicle v;
			v.Service();
		}
		if (check == 4)
		{
			VehicleDataBase vd;
		}
		if (check == 5)
		{
			string registerVal;
			cout << "Skriv in namnet på registret du vill jobba med" << endl;
			cin >> registerVal;
			VehicleRegister vr;
			vr.setRegister(registerVal);
		}
		if (check == 6)
		{
			Vehicle v;
			VehicleDataBase vd;
			vd.registerSearch("volvo","1984");
		}
		if (check == 7)
		{
			break;
		}
	}
}