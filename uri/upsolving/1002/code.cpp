#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	
	double raio;

	double pi = 3.14159;	
	
	cin>>raio;
	
	double area = pi * (pow(raio,2));
	
	cout<<"A="<<fixed<<setprecision(4)<<area<<endl;
	
	return 0;
}