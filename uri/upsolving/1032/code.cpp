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
#define maxn 40000

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int p[maxn];
vi r;

int main(){
	int n;

	int i = 2;
	memset(p, -1, sizeof p);
	while(i < maxn){
		r.push_back(i);
		int j = i<<1;
		while(j < maxn){
			p[j] = 0;
			j+=i;
		}
		i++;
		while(i < maxn && !p[i]) i++;
	}

	while(cin >> n){
		if(!n) break;
		int ans = 1, i = 0;
		while(r[i] < n)ans++, i++;
		cout << i+1 << '\n';
	}

 	return 0;
}

