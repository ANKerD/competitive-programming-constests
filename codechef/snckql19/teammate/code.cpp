#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

int f[maxn];

const long long int mod = 1e9 + 7;

int main(){
	int t,n;
	scanf(" %d", &t);

	int x;
	while(t--) {
		scanf(" %d", &n);
		vi used;

		memset(f, 0, sizeof f);
		for (int i=0; i<n; i++){
			scanf(" %d", &x);
			if (f[x] == 0) {
				used.pb(x);
			}			
			f[x]++;
		}
		vii pares;
		
		for(auto it = used.begin(); it != used.end(); it++)
			pares.pb(mp(*it, f[*it]));

		sort(pares.rbegin(), pares.rend());
		// for (int j =0; j<pares.size(); j++) {
		// 	printf("{%d, %d}, ", pares[j].first, pares[j].second);
		// }
		// printf("\n");

		// reverse(pares.begin(), pares.end());
		ll ans = 1;
		int idx = 0;

		while (idx < pares.size()) {
			while (pares[idx].second > 1) {
				ans = (ans * (pares[idx].second - 1)) % mod;
				pares[idx].second -= 2;
				if(ans < 0){
					int i = 0;
					while(i < 1e15) i++;
				}
			}

			if (pares[idx].second == 1){
				ans = (ans * pares[idx+1].second) % mod;
				pares[idx+1].second--;
				if(ans < 0){
					int i = 0;
					while(i < 1e15) i++;
				}
			}
			idx++;
		}


		printf("%lld\n", ans);
	}
	return 0;
}



/*
	4
	1 7 3 8

	9 8 8 4 4 4 3 3

	- -
	1 1 1 1 1 1 1 1
	7 * 5 * 3 * 1

	2 2 2 1 1 1 
	2 * 3 * 1

	vector<int> {2, 1}

		
	[0, 1, 3, 0]

	(2, 3), (1, 3)
	2: (3-1) = 2
	(2, 1), (1, 3)
	2: 3
	(2, 0), (1, 2)
	1: (2-1) = 1
	(2 * 3 * 1) % MOD

	2 2 2 2 1 1 1 1 
	3 * 1 * 3 * 1	

	1 1 1 1
	3 * 1


	(9:8)
		(8:4)
			(4:4)
			(3:3)

		(8:4)
			(4:4)
				(3:3)
		(8:4)
			(4:4)
				(3:3)
	(9:8)
		(8:4)
			(4:4)
				(3:3)
		(8:4)
			(4:4)
				(3:3)
		(8:4)
			(4:4)
				(3:3)

	4
	2 3 2 2
*/
