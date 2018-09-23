#include <bits/stdc++.h>

#define MAXN 100010

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

ll st[MAXN];

void update(ll i, ll v){
	if(!i)return;
	while(i < MAXN){
		st[i]+=v;
		i+=(i&(-i));
	}
}

ll query(ll i){
	ll s=0;
	// trace1(i);
	while(i>0){
		s+=st[i];
		i-=(i&(-i));
	}
	return s;
}

int main(){

	ll t, n, x,y;
	cin >> t;
	while(t--){
		cin >> n;
		ll a[MAXN];
		ll b[MAXN];
		memset(st, 0, sizeof st);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		ll cnt = 0;
		range(n){
			cin >> x >> y;
			a[x]=i;
			b[y]=i;
		}
		loop1(1, n){
			cnt += query(min(a[i], b[i])) - query(max(a[i], b[i])+1);
			update(min(a[i], b[i])+1, 1);
			update(max(a[i], b[i]), -1);
		}
		trace1(cnt);
	}
 return 0;
}
