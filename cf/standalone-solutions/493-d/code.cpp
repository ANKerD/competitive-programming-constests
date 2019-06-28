#include <bits/stdc++.h>
using namespace std;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	int n;
	cin >> n;
	if (n & 1)
		cout << "black\n";
	else {
		cout << "white\n";
		printf("1 2\n");
	}
 	return 0;
}

