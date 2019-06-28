#include <bits/stdc++.h>
using namespace std;

int main(){
	long double a,b,c,s;
	while(scanf("%Lf %Lf %Lf", &a, &b, &c) != EOF) {
		s = (a+b+c)/2.0;
		printf("%Lf %Lf %Lf %Lf\n", s,a,b,c);
		printf("The radius of the round table is: %.3Lf\n", sqrt(s*(s-a)*(s-b)*s-c));
	}
 	return 0;
}

