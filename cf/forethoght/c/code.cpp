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
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		vi a, b, m[2];
		for(int i = 1; i <=n; i++)
			if(i&1) a.pb(i);
			else b.pb(i);

		int ans = 0;
		bool own = 0;
		for(int i = 0; i < 9; i++){
			vi t;
			m[0].clear();
			m[1].clear();
			for(auto u: a){
				m[own].pb(u);
				own = !own;
			}
			for(auto u: b){
				m[own].pb(u);
				own = !own;
			}
			t.pb(m[0].size());
			t.pb(m[1].size());
			for(int j = 0; j < 2; j++)
				for(auto u: m[j])
					t.pb(u);
			for(int j = 0; j < (int) t.size(); j++)
				cout << t[j] << " \n"[j+1==(int) t.size()];
			cout.flush();
			int temp;
			cin >> temp;
			if(temp == -1) return 0;
			ans = max(ans, temp);
			a = m[0];
			b = m[1];
		}
		cout << "-1 " << ans << endl;
		cout.flush();
	}
 	return 0;
}

