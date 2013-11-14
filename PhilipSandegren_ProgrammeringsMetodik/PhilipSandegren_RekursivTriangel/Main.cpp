#include <iostream>

using namespace std;

void triangle(ostream&outs, unsigned int m, unsigned int n)
{
	for (int i = 0; i < m; i++)
	{
		outs << "*";
	}
	outs << endl;
	m++;
	if (m <= n)
	{
		triangle(cout,m,n);
	}
	for(int i=1; i < m; i++)
	{
		outs << "*";
	}
	outs << endl; 

}

void main()
{
	triangle(cout, 3, 5);
	system("PAUSE");
}