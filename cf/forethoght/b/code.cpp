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

	string s;
	cin >> s;
	int n = (int) s.size();
	int l=-1;
	for(int i = 0; i < n; i++)
		if(s[i] == 'a')
			l=i;
	vector<pair<char, int> > v;
	for(int i = 0; i < n; i++)
		if(s[i] != 'a')
			v.pb(mp(s[i], i));
	int m= v.size();
	int mid = (m+1)/2;
	bool o = 1;
	int ans = 1e8;
	
	if(m){
		if(v[mid].se < l) o = 0;
		else for(int i = 0; i < mid; i++)
			if(v[i].fi != v[i+mid].fi){
				m = v[i].se;
				o = 0;
				break;
			} else ans = v[mid].se;
	}
	// trace(m);
	if(!o){
		cout << ":(\n";
	} else {
		for(int i = 0; i <= min(ans-1, n-1); i++)
			cout << s[i];
		cout << '\n';
	}
 	return 0;
}

