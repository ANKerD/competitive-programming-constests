#include <bits/stdc++.h>

#define MAXN 30011

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1]);

#define swap(a, b) auto temp = a; a = b; b = temp;

#define loop1(l, r) for(int i = l; i <= r; i++)
#define loop2(l, r) for(int j = l; j <= r; j++)
#define loop3(l, r) for(int k = l; k <= r; k++)
#define iloop1(l, r) for(int i = l; i >= r; i--)
#define iloop2(l, r) for(int j = l; j >= r; j--)
#define iloop3(l, r) for(int k = l; k >= r; k--)
#define range(sz) loop1(0, sz-1)

#define read(l, r, a) for(int i = l; i <= r; i++) scanf("%d", &a[i])

#define mp(a, b) make_pair(a, b);

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<ll> vll;
typedef vector<double> vd;

// ll state[3001][3001];


int main(){
	ll ans = 1e30;
	memset(state, -1, sizeof state);
	int n, m, v, price;
	cin >> n >> m;
	ll cnt[MAXN]; // Votos tirados
	// ll votes[MAXN]; // Votos tirados
	pair<ll, ll> c[MAXN];
	vector<ll> party[MAXN]; // Votos valoe de cada voto
	range(n){
		cin >> v >> price;
		c[i] = mp(price, v);
		party[v].push_back(price);
		// votes[v]++;
	}
	range(n) sort(party[i].begin(), party[i].end());
	loop1(0, n-1){
		memset(cnt, 0, sizeof cnt);
		int take = i, pos=0, cost=0, tt=0;
		while(take > 0 && take < n){
			if(c[pos++].second == 1) continue;
			cnt[c[pos-1].second]++;
			cost += c[pos-1].first;
			tt++;
		}
		bool ok = 1;
		loop2(2, m) if(party[1].size()+tt <= party[i].size()-cnt[i]) ok = 0;
		if(ok) ans = min(ans, cost);
	}

 return 0;
}
