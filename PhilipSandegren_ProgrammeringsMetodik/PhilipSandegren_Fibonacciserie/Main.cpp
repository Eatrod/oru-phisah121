#include <iostream>

using namespace std;

int fibrek(unsigned int a) 
{
	//Stackoverflow vid ungefär 4800
   if (a == 0)
        return 0;
	if (a == 1)
        return 1;
	return fibrek(a-1)+fibrek(a-2);
}

int fibiter()
{
	return 0;
}

int main()
{
	cout << fibrek(5) << endl;
	system("PAUSE");
}