#include <iostream>
#include <string>

using namespace std;

void SWAP(float *ptr_x, float *ptr_y)
{
	float dummy = *ptr_y;
	*ptr_y = *ptr_x;
	*ptr_x = dummy;
	cout << *ptr_x << " " << *ptr_y << endl;
}
void SWAP(float &x, float &y)
{
	float dummy = y;
	y = x;
	x = dummy;
	cout << x << " " << y << endl;
}
void SWAP(string &x, string &y)
{
	string dummy = y;
	y = x;
	x = dummy;
	cout << x << " " << y << endl;
}


int main (void) {
	float f1= 1,f2= 2;
	string s1= "hej", s2= "jeh";
	SWAP(&f1,&f2);
	SWAP(f1,f2);
	SWAP(s1,s2);
	cin.get();
}