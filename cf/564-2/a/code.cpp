#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if (!c) {
		if (a == b)
			trace("0");
		else if (a < b)
			trace("-");
		else
			trace("+");
	} else {
		if (a > b+c)
			trace("+");
		else if (b > a+c)
			trace("-");
		else
			trace("?");
	}
 	return 0;
}

