#include <iostream>
#include <string>
#include "Article.h"

using namespace std;

/*void main3.1.2()
{
	cout << "Main3.1.2"<< endl;
	Article a1;
	a1.Read();
	a1.Write();
	cin.get();
	cin.get();
}*/

void main()
{
	istringstream iss("(2,2009-09-10,Ekonomi, Gösta,200,Nyhet)");
	Article a1;
	iss >> a1;
	cout << a1 << endl;
}