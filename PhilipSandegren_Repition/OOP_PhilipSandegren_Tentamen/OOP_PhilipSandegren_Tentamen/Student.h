#include <string>
#include <iostream>

using namespace std;

#pragma once
class Student
{
protected:
	string firstName;
	string lastName;
	int enrollmentYear;
public:
	Student(): firstName(" "), lastName(" "), enrollmentYear(0)
	{
	}
	Student(string firstName, string lastName, int enrollmentYear)
	{
	}
	string getFirstName() {return firstName;}
	void setFirstName(string FirstName) {firstName = FirstName;}
	string getLastName() {return lastName;}
	void setLastName(string LastName) {lastName = LastName;}
	int getEnrollmentYear() {return enrollmentYear;}
	void setEnrollmentYear(int enrollmentyear) {enrollmentYear = enrollmentyear;}

	void Read()
	{
		cout << "First name = " << endl;
		cin >> firstName;
		cout << "Last name = " <<  endl;
		cin >> lastName;
		cout << "Enrollment year = " << endl;
		cin >> enrollmentYear;
	}

	void Write()
	{
		cout << "First name = " << firstName << endl;
		cout << "Last name = " << lastName << endl;
		cout << "Enrollment year = " << enrollmentYear << endl;
	}

	friend ostream& operator<<(ostream &o,const Student&s)
	{
		o << "(" << s.firstName << "," << s.lastName << "," << s.enrollmentYear << ")";
		return o;
	}

	friend istream& operator>>(istream& in, Student&s)
	{
		string ss;
		std::getline(in,ss,'(');
		in>>s.firstName;
		std::getline(in,ss,',');
		in>>s.lastName;
		std::getline(in,ss,',');
		in>>s.enrollmentYear;
		std::getline(in,ss,')');
		return in;
	}

};

