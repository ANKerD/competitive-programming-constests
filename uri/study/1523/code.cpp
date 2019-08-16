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

bool cmp(ii &a, ii &b) {
	if (a.fi != b.fi)
		return a.fi < b.fi;
	return a.fi < b.se;
}

int main(){
	int n,k,l,r;
	while(1){
		cin >> n >> k;
		if (k+n == 0) break;
		vii a;
		for (int i = 0; i < n; ++i) {
			cin >> l >> r;
			a.push_back({l,i});
			a.push_back({r,-i});
		}
		sort(a.begin(), a.end(), cmp);

		stack<int> s;
		bool ok = 1;
		for (int i = 0; i < a.size(); ++i) {
			if (!s.empty() && s.top() == -a[i].se)
				s.pop();
			else
				s.push(a[i].se);
			// trace("sz", s.size());
			if (s.size() > k) ok = 0;
		}
		if (!s.empty()) ok = 0;
		cout << (ok? "Sim" : "Nao") << '\n';
	}
 	return 0;
}


