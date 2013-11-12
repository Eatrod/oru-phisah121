#include <iomanip>
#include <iostream>
#include "interval.h"

using namespace std;

int main ()
{
	interval<double> m1;
	interval<double> m2;
	m1.intervala(2,1);
	m2.intervala(5,2);
	m1.mean();
	cout <<  "m1 Relativit error: " << m1.relative_error() << endl;
	cout <<  "m1 Absolut error: " << m1.absolute_error() << endl;
	cout << "m1+m2: " << m1+m2 << endl;
	cout << "m1-m2: " << m1-m2 << endl;
	cout << "m1*m2: " << m1*m2 << endl;

	cout << "Data om m1: " << m1 << endl;
	cout << "Data om m2: " << m2 << endl;
	system("PAUSE");
}
