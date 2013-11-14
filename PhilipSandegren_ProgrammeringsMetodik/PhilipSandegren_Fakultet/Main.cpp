#include <iostream>
#include <chrono>

using namespace std;

int rekursion(int a)
{
	if (a == 0)
		return 1;
	return a*rekursion(a-1);
}

int iterativ(int b)
{
	int a; 
	a = 1;  
	for (int n=2;n<=b;n++) 
	{ 
	a *= n; 
	}
	return a;
}

int sum (int i, int n)
{
	if (i==n)
		return n;
	else
	{
		return i+sum(i+1,n);
	}
}

int main()
{
	cout << "Rekursivt: " << rekursion(9) << endl;
	cout << "Iterativt: " << iterativ(9) << endl;
	cout << "Summering: " << sum(1,5) << endl;
	system("PAUSE");
}