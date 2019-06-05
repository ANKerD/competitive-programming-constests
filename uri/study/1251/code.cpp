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
	string nd = "";
	while(cin >> s){
		cout << nd;
		map<int, int> m;
		for (int i = 0; i < s.size(); i++)
			m[s[i]] += 1;

		ii a[255];
		int x = 0;
		for (int i = 255; i; i--)
			if (m[i]){
				a[x++] = mp(m[i], -i);
			}

		sort(a,a+x);
				
		for (int i = 0; i < x; i++)
			cout << -a[i].se << ' ' << a[i].fi << '\n';
		nd = '\n';
	}
 	return 0;
}

