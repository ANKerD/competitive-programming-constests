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
#define maxn 40010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ii a[maxn];

int main(){
	int n, st = 1e5, nd = 0;
	cin >> n;

	priority_queue<int> input, output;
	
	for(int i = 0; i < n; i++){
		cin >> a[i].fi >> a[i].se;
		st = min(st, a[i].fi);
		nd = max(nd, a[i].se);
		input.push(-a[i].fi);
		output.push(-a[i].se);
	}
	
	int l = st, r = nd, ans=nd;
	while(l <= r){
		int mid = (l+r)/2;

		bool ok = true;
		int light = 0, p = 0;

		priority_queue<int> inner = input, outer = output;

		// while(!inner.empty()){
		// 	cout << inner.top() << ' ';
		// 	inner.pop();
		// }
		// break;

		// trace(st,nd);
		for(int i = st; i <= nd; i++){
			light--;
			i=-i;
			if(!inner.empty() && inner.top() == i){
				light = mid;
				while(!inner.empty() && inner.top() == i){
					p++;
					// trace("entrou", i, p);
					inner.pop();
				}
			}
			if(!outer.empty() && outer.top() == i){
				while(!outer.empty() && outer.top() == i){
					p--;
					// trace("saiu", i, p);
					outer.pop();
				}
			}
			if(light <= 0 && p){
				ok = false;
				break;
			}
			i = -i;
			// trace("dur", mid, i, p, light);
		}

		// trace(ok, mid, l,r);
		// break;

		if(ok){
			ans = min(ans, mid);
			r=mid-1;
		} else 
			l = mid+1;
	}

	cout << ans << '\n';
 	return 0;
}

