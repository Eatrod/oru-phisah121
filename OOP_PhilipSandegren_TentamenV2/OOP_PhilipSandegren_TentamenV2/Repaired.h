#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include "Vehicle.h"

using namespace std;

class Repaired 
{
protected:
	string repairDate;
	string whatFixed;
public:
	Repaired(): repairDate(" "), whatFixed(" ")
	{
	}
	Repaired(string repairDate, string whatFixed) : repairDate(repairDate),whatFixed(whatFixed)
	{
	}
	string getRepairDate() {return repairDate;}
	void setRepairDate(string RepairDate) {repairDate = RepairDate;}
	string getWhatFixed() {return whatFixed;}
	void setWhatFixed(string WhatFixed) {whatFixed = WhatFixed;}
};

