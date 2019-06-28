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

bool cmp(string &a, string &b) {
	return a.size() > b.size();
}

int main(){
	int n,k;
	string s;
	cin >> n >> k;
	cin >> s;
	set<string> a;
	a.insert(s);
	while(1) {
		bool ins = 0;
		set<string> aux;
		for (auto u: a) {
			for (int i = 0; i < u.size(); ++i) {
				ins = 1;
				if (i)
			}
			
		}
		if (!ins) break;
		a = aux;
	}
	if (a.size() < k) {
		cout << "-1\n";
	} else {
		// trace(n,k);
		vector<string> that = vector<string>(a.begin(), a.end());
		sort(that.begin(), that.end(), cmp);
		ll ans = 0;
		for (int i = 0; i < k; ++i)
			ans += n-that[i].size();
		cout << ans << '\n';
	}

 	return 0;
}

