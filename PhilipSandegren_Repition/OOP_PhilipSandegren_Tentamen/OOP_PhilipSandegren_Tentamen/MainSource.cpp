#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Student.h"
#include "StudentRegister.h"

using namespace std;

void main3_1_2() //Betyg 3 - Uppgift 1 och 2
{
	cout << "Main 3_1_2" << endl;
	Student s,s2;
	s.Read();
	s.Write();
	system("pause");
}

void main3_3() //Betyg 3 - Uppgift 3
{
	cout << "Main3.3" << endl;
	Student s1;
	istringstream iss("(Gösta ,Göring ,2000 )");
	iss >> s1;
	ostringstream oss;
	oss << s1;
	string s = oss.str();
	cout << s << endl;
	system("pause");
}

void main3_4() //Betyg 3 - Uppgift 4
{
	cout << "Main3_4" << endl;
	Student s1,s2;
	istringstream iss("(Gustav ,Gustavsson ,2000 )");
	iss >> s1;
	s2.setFirstName("Hej");
	s2.setLastName("Tja");
	s2.setEnrollmentYear(5);
	StudentRegister sr;
	sr.Add(s1);
	sr.Add(s2);
	sr.setRegister("Extremt obegåvade begåvningar");
	string lis = sr.List();
	cout << lis;
	system("pause");
}

void main3_5_6() //Betyg 3 - Uppgift 5 och 6
{
	cout << "Main3_5_6" << endl;
	Student s1,s2,s3;
	istringstream iss("(Gustav ,Gustavsson ,2000 )");
	iss >> s1;
	s2.setFirstName("Hej");
	s2.setLastName("Tja");
	s2.setEnrollmentYear(5);
	StudentRegister sr;
	sr.Add(s1);
	sr.Add(s2);
	sr.setRegister("Extremt obegåvade begåvningar");
	sr.write_2File("test.txt");
	sr.readFromFile("test.txt");
	cout << sr << endl;
	system("pause");
}

int main()
{
	main3_1_2();
	main3_3();
	main3_4();
	main3_5_6();
}