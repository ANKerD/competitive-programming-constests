#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define tp pair<int, ii>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 1001

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

void inline remove(int &k, int &a, int d, ll &ans){
	int x = min(a, k);
	a -= x;
	k -= x;
	ans = ans + d*x;
}

bool cmp(tp a, tp b){
	return a.se.fi + a.se.se < b.se.fi + b.se.se;
}

tp q[maxn];

int main(){
	int n,a,b,k,da,db;
	while(1){
		cin >> n >> a >> b;
		if(!n && !a && !b) break;
		ll ans = 0;
		for(int i = 0; i < n; i++){
			cin >> k >> da >> db;
			q[i] = mp(k, mp(da, db));
		}
		sort(q,q+n,cmp);
		while(n--){
			k = q[n].fi;
			da = q[n].se.fi;
			db = q[n].se.se;
			if(da < db){
				remove(k, a, da, ans);
				remove(k, b, db, ans);
			} else {
				remove(k, b, db, ans);
				remove(k, a, da, ans);
			}
		}
		cout << ans << '\n';
	}
 	return 0;
}

