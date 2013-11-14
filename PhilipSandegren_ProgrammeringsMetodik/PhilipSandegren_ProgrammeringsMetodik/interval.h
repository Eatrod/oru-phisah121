#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

template<class T>
class interval
{
private:
	T lower;
	T upper;
public:
	interval() {lower=upper=0;}
	void intervala (T mean, double procent)
	{
		lower = mean-mean*procent/100;
		upper = mean+mean*procent/100;
	}
	T mean() {return (upper-lower)/2;}
	double relative_error() {return(upper-lower)/mean();}
	double absolute_error() {return(upper-mean())+(lower-mean());}

	T getUpper() {return upper;}
	void setUpper(T Upper) {upper = Upper;}

	T getLower() {return lower;}
	void setLower(T Lower) {lower = Lower;}

	
	friend interval<T> operator+(interval<T> &lop,interval<T> &rop)
	{
		interval<T> m;
		m.upper = lop.upper + rop.upper;
		m.lower = lop.lower + rop.lower;
		return m;
	}

	friend interval<T> operator-(interval<T> &lop,interval<T> &rop)
	{
		interval<T> m;
		m.upper = lop.upper - rop.upper;
		m.lower = lop.lower - rop.lower;
		return m;
	}

	friend interval<T> operator*(interval<T> &lop,interval<T> &rop)
	{
		interval<T> m;
		m.upper = max( max( max(lop.upper*rop.upper, lop.upper*rop.lower) , lop.lower*rop.upper) , lop.lower*rop.lower);
		m.lower = min( min( min(lop.upper*rop.upper, lop.upper*rop.lower) , lop.lower*rop.upper) , lop.lower*rop.lower);
		return m;
	}

	friend ostream& operator<<(ostream &o,interval<T> &rop)
	{
		o << "Övre: " << rop.upper << " Undre: " << rop.lower << " Median: " << rop.mean();
		return o;
	}
};

