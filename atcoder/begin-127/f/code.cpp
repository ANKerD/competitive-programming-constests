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
#define maxn 3001

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];
int sol[maxn];
int p;

int expo(int a, int b) {
	if (!b) return 1;
	if (b&1) return a * expo(a, b-1) % p;
	return expo(a * a % p, b>>1);
}

int main(){
	cin >> p;
	for (int i = 0; i < p; ++i)	
		cin >> a[i];
	sol[0] = a[0];
	for (int i = 1; i < p; ++i)	{
		int cur = 0;
		for (int j = 0; j < i; ++i)
			cur = (cur + expo(sol[j], i)) % p; 
	}
	
 	return 0;
}

