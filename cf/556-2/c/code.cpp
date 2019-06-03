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
	int n;
	cin >> n;
	int one=0,two=0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 1) one++; else two++;
	}

	vi a;
	if(!two || !one){
		for(int i = 0; i < one; i++)
			a.pb(1);
		for(int i = 0; i < two; i++)
			a.pb(2);
	} else {
		a.pb(2);
		a.pb(1);
		for(int i = 1; i < two; i++)
			a.pb(2);
		for(int i = 1; i < one; i++)
			a.pb(1);
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << " \n"[i+1==n];


 	return 0;
}

