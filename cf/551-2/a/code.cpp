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
	int n,t,w=1e8,s,d, ans;
	cin >> n >> t;
	int i =0;
	for(; i < n; i++){
		cin >> s >> d;
		int c = s;
		while(c < t) c += d;
		if(c < w)
			w = c, ans=i;
		
	}
	cout << ans+1 << '\n';
	
 	return 0;
}

