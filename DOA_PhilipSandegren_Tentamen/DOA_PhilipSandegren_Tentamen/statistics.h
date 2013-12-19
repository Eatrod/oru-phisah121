#pragma once
#include <array>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <istream>
#include <fstream>

using namespace std;

namespace statclass
{
	class statistics
	{
	private:
		array<int,1000000> salaryArray;
	public:

		statistics(void)
		{
		}
		void main()
		{
			clear();
			readFile();
			cout << "Medel l�nen: " << endl;
			cout << calculate_mean() << endl;
			cout << "Median l�nen: " << endl;
			cout << calculate_median() << endl;
		}

		void readFile()
		{
			string filnamn;
			string row;
			int salary;
			cout << "Skriv in namnet p� filen: ";
			cin >> filnamn;
			ifstream myFile;
			myFile.open(filnamn);
			//Index i arrayen ska vara l�nen och v�rdet hur m�nga som har den
			//Om 2 personer har 5 kronor i l�n blir 2*5 allts� enkelt att r�kna ut
			while (getline(myFile,row))
			{
				istringstream iss(row);
				iss >> salary;
				if (salary > 20000 || salary < 1000000)
					salaryArray[salary] += 1;
			}
			myFile.close();
		}

		void clear()
		{
			salaryArray.fill(0);
		}

		long long calculate_mean()
		{
			long long meanSalary = 0;
			int loopLaps = 0;
			for (int i = 0; i < salaryArray.size(); ++i)
			{
				if (salaryArray[i] != 0)
				{
					meanSalary += salaryArray[i]*i;
					loopLaps += 1;
				}
			}
			return meanSalary/loopLaps;
		}

		int calculate_median()
		{
			deque<int> salaryQuene;
			for (int i = 0; i < salaryArray.size(); ++i)
			{
				if (salaryArray[i] != 0)
				{
					
				}
			}
			int medianSalary;
			medianSalary = salaryArray[500000];
			return medianSalary;
		}
		~statistics(void)
		{
		}
	};
}
