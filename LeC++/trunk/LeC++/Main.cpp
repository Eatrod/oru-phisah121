#include <iostream>
#include <string>
#include <sstream>


using namespace std;

void
DoThis (
int
&alpha ,
int
beta )
{
int
temp ;
alpha = alpha + 326;
temp = beta ;
beta = 308;
}

int main () {
int gamma = 173;
int delta = 240;
DoThis(gamma,delta);
cout << gamma << ' ' << delta;
cin.get();
}