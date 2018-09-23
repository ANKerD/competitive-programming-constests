#include <bits/stdc++.h>
#define MAXN 100010

#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) loop1(0, tam-1) cout << harry[i] << " \n"[i == tam -1];

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

int main(){
	int t, n, m, x, p,q,r;
	int ans = 0;
	int a[MAXN];
	scanf("%d", &t);
	while(t--){
		ans=0;
		map<ll, int> cnt;
		// cnt.clear();
		scanf("%d %d", &n, &m);
		// memset(a, 0, sizeof(a));
		range(n){
			scanf("%d", &x);
			a[i]=x;
			if(!cnt.count(x) && x != 0) ans++;
			cnt[x]++;
		}
		range(m){
			scanf("%d", &p);
			if(p == 2){
				printf("%d\n", ans);
			} else {
				scanf("%d %d", &q, &r);
				q--;
				cnt[a[q]]--;
				if(cnt[a[q]]==0 && a[q] != 0) ans--;

				a[q]=r;
				if(cnt[r]==0 && a[q] != 0) ans++;
				cnt[r]++;
			}
		}
	}


 return 0;
}
