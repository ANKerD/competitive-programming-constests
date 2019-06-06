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
#define maxn 200010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n,k;
int v[maxn];

int f(int m) {
	vi a;
	for (int i = 0; i < n; i++)
		a.pb(abs(v[i]-m));
	sort(a.begin(), a.end());
	return a[k];
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		int lo = 0, hi = 1000000001;
		while (hi - lo > 1){
			int mid = (hi + lo)>>1;
			if (f(mid) < f(mid + 1)) 
				hi = mid;
			else 
				lo = mid; 
		}

		trace(lo+1);
	}

 	return 0;
}

